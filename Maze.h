#ifndef Maze_h

    #define Maze_h
    #include "Size.h"
    #include "Point.h"

    using namespace NutnDS_Size;
    using namespace::NutnDS_Point;

    namespace NutnDS_Maze
    {
        typedef enum Element {unknown, road, obstacle, wall, final} element;

        const int kMaxHeight = 1000;
        const int kMaxWidth = 1000;

        class Maze
        {
            public:
                // Constructor.
                Maze();
                Maze(int, int, element[kMaxHeight][kMaxWidth]);

                // Destructor.
                ~Maze();

                // Accessor.
                const Size getSize() { return *size; }
                const element getMap(int, int) const;
                const int getNumSolution() const { return numSolution; }

                // Mutator.
                bool setMap(int, int, element);

                // Method.
                bool isInBoundary(int, int) const;
                void printMap() const;
                int solve(int, int);
                void printSolution() const;

            private:
                // Variable.
                Size* size;
                element map[kMaxHeight][kMaxWidth];
                int numSolution;
                PointSet* solution;

                // Method.
                void nextStep(int, int);
        };
    }

#endif

