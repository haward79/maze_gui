#ifndef InputMaze_h

    #define InputMaze_h

    #include <QMainWindow>
    #include <QMouseEvent>
    #include "QButton.h"
    #include "Maze.h"
    #include "SolveMaze.h"
    #include "QButton.h"

    namespace Ui { class InputMaze; }

    class InputMaze : public QMainWindow
    {
        Q_OBJECT

        public:
            // Constructor.
            InputMaze();
            InputMaze(int, int);

            // Destructor.
            ~InputMaze();

        private:
            // Variable.
            Ui::InputMaze *ui;
            int height, width;
            Point* startPos;
            NutnDS_Maze::Element map[NutnDS_Maze::kMaxHeight][NutnDS_Maze::kMaxWidth];
            QButton* mapGui[NutnDS_Maze::kMaxHeight][NutnDS_Maze::kMaxWidth];
            SolveMaze* solveMaze;
            QStatusBar* statusbar_readme;

        private slots:
            void markMapSelection();
            void markMapSatrtFinal();
            void solvingMaze();

        signals:
    };

#endif

