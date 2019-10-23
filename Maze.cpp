#include <iostream>
#include "Maze.h"

namespace NutnDS_Maze
{
    // Constructor.
    Maze::Maze()
    {
        size = new Size(100, 100);

        for(int i=0; i<kMaxHeight; ++i)
            for(int j=0; j<kMaxWidth; ++j)
                setMap(i, j, wall);

        numSolution = -1;
        solution = new PointSet();
    }

    Maze::Maze(int height, int width, element map[kMaxHeight][kMaxWidth])
    {
        if(height <= 0)
            height = 100;

        if(width <= 0)
            width = 100;

        size = new Size(height, width);

        for(int i=0; i<height; ++i)
            for(int j=0; j<width; ++j)
                setMap(i, j, map[i][j]);

        numSolution = -1;
        solution = new PointSet();
    }

    // Destructor.
    Maze::~Maze()
    {
        delete size;
        delete solution;
    }

    // Accessor.
    const element Maze::getMap(int indexI, int indexJ) const
    {
        if(isInBoundary(indexI, indexJ))
            return map[indexI][indexJ];
        else
            return unknown;
    }

    // Mutator.
    bool Maze::setMap(int indexI, int indexJ, element value)
    {
        if(isInBoundary(indexI, indexJ))
        {
            map[indexI][indexJ] = value;
            return true;
        }
        else
            return false;
    }

    // Method.
    bool Maze::isInBoundary(int indexI, int indexJ) const
    {
        if(indexI>=0 && indexJ>=0 && indexI<size->getHeight() && indexJ<size->getWidth())
            return true;
        else
            return false;
    }

    void Maze::printMap() const
    {
        using std::cout;

        // Print title.
        cout << "+";

        for(int j=0; j<size->getWidth(); ++j)
            cout << "-";
        
        cout << "+\n| Map ";

        for(int i=0; i<size->getWidth()-5; ++i)
            cout << " ";

        cout << "|\n+";

        for(int j=0; j<size->getWidth(); ++j)
            cout << "-";
        
        cout << "+\n";

        // Print maze.
        for(int i=0; i<size->getHeight(); ++i)
        {
            // Print rows.
            cout << "|";

            for(int j=0; j<size->getWidth(); ++j)
            {
                switch(map[i][j])
                {
                    case road:
                        cout << " ";
                        break;

                    case obstacle:
                        cout << "@";
                        break;

                    case wall:
                        cout << "#";
                        break;

                    case final:
                        cout << "*";
                        break;

                    default:
                        cout << "?";
                }
            }
            cout << "|\n";
        }

        // Print last row seperator.
        cout << "+";

        for(int j=0; j<size->getWidth(); ++j)
            cout << "-";
        
        cout << "+\n";
    }

    int Maze::solve(int startI, int startJ)
    {
        ++numSolution;
        nextStep(startI, startJ);
    }

    void Maze::printSolution() const
    {
        using std::cout;

        cout << "\nSolution: " << numSolution << " found.\n";

        if(numSolution > 0)
        {
            cout << "    " << solution->getSize() << " steps in total.\n";

            for(int i=0; i<solution->getSize(); ++i)
                printf("        Step %2d: (%2d, %2d)\n", i+1, solution->getPointI(i), solution->getPointJ(i));
            
            cout << "\n";
        }
        else
            cout << "\n";
    }

    void Maze::nextStep(int indexI, int indexJ)
    {
        if(numSolution<=0 && isInBoundary(indexI, indexJ) && (map[indexI][indexJ]==road || map[indexI][indexJ]==final))
        {
            solution->push(indexI, indexJ);

            if(map[indexI][indexJ] == final)
                ++numSolution;
            else
            {
                map[indexI][indexJ] = obstacle;

                nextStep(indexI+1, indexJ);
                nextStep(indexI-1, indexJ);
                nextStep(indexI, indexJ+1);
                nextStep(indexI, indexJ-1);
                nextStep(indexI+1, indexJ+1);
                nextStep(indexI+1, indexJ-1);
                nextStep(indexI-1, indexJ+1);
                nextStep(indexI-1, indexJ-1);

                map[indexI][indexJ] = road;
            }

            if(numSolution <= 0)
                solution->pop();
        }
    }
}

