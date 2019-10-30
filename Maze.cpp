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

        for(int i=0; i<kMaxSolution; ++i)
            solution[i] = new PointSet();
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
        
        for(int i=0; i<kMaxSolution; ++i)
            solution[i] = new PointSet();
    }

    // Destructor.
    Maze::~Maze()
    {
        delete size;

        for(int i=0; i<kMaxSolution; ++i)
            delete solution[i];
    }

    // Accessor.
    element Maze::getMap(int indexI, int indexJ) const
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
        bool isSolved = false;

        ++numSolution;
        nextStep(startI, startJ, isSolved);

        return numSolution;
    }

    PointSet Maze::getSolution(int index) const
    {
        if(index>=0 && index<numSolution)
            return PointSet(*solution[index]);
        else
            return PointSet();
    }

    bool Maze::printSolution(int index) const
    {
        if(index>=0 && index<numSolution)
        {
            using std::cout;

            cout << "\n" << solution[index]->getSize() << " steps in total.\n";

            for(int i=0; i<solution[index]->getSize(); ++i)
                printf("- Step %2d: (%2d, %2d)\n", i+1, solution[index]->getPointI(i), solution[index]->getPointJ(i));
            
            cout << "\n";

            return true;
        }
        else
            return false;
    }

    void Maze::printAllSolution() const
    {
        using std::cout;

        cout << "\nSolution: " << numSolution << " found.\n";

        if(numSolution > 0)
        {
            for(int i=0; i<numSolution; ++i)
            {
                cout << "\nNo. " << i+1 << " solution.\n";
                cout << "  " << solution[i]->getSize() << " steps in total.\n";

                for(int j=0; j<solution[i]->getSize(); ++j)
                    printf("  - Step %2d: (%2d, %2d)\n", j+1, solution[i]->getPointI(j), solution[i]->getPointJ(j));
                
                cout << "\n";
            }
        }
        else
            cout << "\n";
    }

    void Maze::nextStep(int indexI, int indexJ, bool isSolved)
    {
        if(isSolved)
            return ;

        if(numSolution<=0 && isInBoundary(indexI, indexJ) && (map[indexI][indexJ]==road || map[indexI][indexJ]==final))
        {
            solution[numSolution]->push(indexI, indexJ);

            if(map[indexI][indexJ] == final)
            {
                isSolved = true;
                ++numSolution;
            }
            else
            {
                map[indexI][indexJ] = obstacle;

                nextStep(indexI+1, indexJ, isSolved);
                nextStep(indexI-1, indexJ, isSolved);
                nextStep(indexI, indexJ+1, isSolved);
                nextStep(indexI, indexJ-1, isSolved);
                nextStep(indexI+1, indexJ+1, isSolved);
                nextStep(indexI+1, indexJ-1, isSolved);
                nextStep(indexI-1, indexJ+1, isSolved);
                nextStep(indexI-1, indexJ-1, isSolved);

                map[indexI][indexJ] = road;
            }

            if(numSolution <= 0)
                solution[numSolution]->pop();
        }
    }
}

