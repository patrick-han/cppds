#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define MAZE_OBSTACLE '+'
#define MAZE_START 'S'
#define MAZE_PATH 'O'
#define MAZE_DEAD_END '_'
#define MAZE_TRIED '.'


class Maze
{
public:
    int totalRows;
    int totalColumns;
    int startRow;
    int startColumn;


    // Constructor
    Maze(const char *filename) 
    {
        std::cout << "Loading file: " << filename << std::endl;
        readMazeFile(filename);
    }

    /*
     * Loads the text file representation of a maze, converting it
     * to the Maze object's desired representation (vector of char vectors)
     * 
     * Also, finds the coordinatees of the starting point and the maze dimensions
     */
    void readMazeFile(const char *filename) 
    {
        std::ifstream file(filename); // Make an ifstream object
        int rowcounter = 0;
        if (file.is_open()) 
        {
            std::string line;
            while (std::getline(file, line)) // Read line by line
            {   
                // Vectorize each line, adding it to mazeList
                std::vector<char> vectorized_line;
                for (int i = 0; i < line.length(); ++i) 
                {
                    if (line[i] == MAZE_START) // Set the starting position when found
                    {
                        startRow = rowcounter;
                        startColumn = i;
                        std::cout << "Found starting position at: (" << startRow << ", " << startColumn << ")" << std::endl;
                    }
                    vectorized_line.push_back(line[i]);
                }
                mazeList.push_back(vectorized_line);
                rowcounter++;
            }
            std::cout << "Maze File Loaded (EOF)\n";
            file.close();
        }

        // Determine the maze dimensions
        totalRows = mazeList.size();
        totalColumns = mazeList[0].size();
    }
    
    /*
     * Prints the maze row by row
     */
    void printMaze() {
        for (std::vector<char> line:mazeList) 
        {
            for (int i = 0; i < line.size(); ++i)
            {
                std::cout << line[i];
            }
            std::cout << std::endl;
        }
    }

    /*
     * Returns if a given coordinate is on the edge of the maze
     */
    bool isOnEdge(int row, int col) 
    {
        return (row == 0) || 
        (row == (totalRows - 1)) || 
        (col == 0) || 
        (col == (totalColumns - 1));
    }

    // Access rows of the maze (important: overload with a reference return type: otherwise, assignment won't work)
    std::vector<char>& operator[](int index) 
    {
        return mazeList[index];
    }

private:
    // Maze representation is a vector of char vectors
    std::vector<std::vector<char>> mazeList;
};

bool searchFrom(Maze &maze, int startRow, int startColumn)
{
    
    // Steps 1, 2, 3 are our base cases for this recursive problem
    bool found;
    // 1. If we found a square that is an obstacle, stop searching this way
    if (maze[startRow][startColumn] == MAZE_OBSTACLE)
    {
        return false;
    }

    // 2. If we found a square that we already tried, stop searching this way
    if (maze[startRow][startColumn] == MAZE_TRIED)
    {
        return false;
    }

    // 3. If we're on a square that is on the edge (and didn't fail the
    // above two conditions), we've found the exit
    if (maze.isOnEdge(startRow, startColumn))
    {
        maze[startRow][startColumn] = MAZE_PATH;
        return true;
    }

    // 4. Indicate that the currently visited space has been tried
    maze[startRow][startColumn] = MAZE_TRIED;

    // 5. Check each cardinal direction
    found = searchFrom(maze, startRow - 1, startColumn) ||
    searchFrom(maze, startRow + 1, startColumn) ||
    searchFrom(maze, startRow, startColumn - 1) ||
    searchFrom(maze, startRow, startColumn + 1);
    
    // 6. Mark the location as either part of the path or a deadned depending
    // on if the exit was found -- searchFrom() only returns true in the case
    // of an exit being found (step 3)
    if (found)
    {
        maze[startRow][startColumn] = MAZE_PATH;
    }
    else
    {
        maze[startRow][startColumn] = MAZE_DEAD_END;
    }
    return found;
}

int main() {
    const char *filename = "maze1.txt";
    Maze maze1(filename);
    std::cout << "Starting state: " << std::endl;
    maze1.printMaze();
    searchFrom(maze1, maze1.startRow, maze1.startColumn);
    std::cout << "Ending state: " << std::endl;
    maze1.printMaze();
}