#ifndef InputMaze_h

    #define InputMaze_h

    #include <QMainWindow>
    #include <QMouseEvent>
    #include "Maze.h"
    #include "SolveMaze.h"
    #include "QButton.h"

    namespace Ui { class InputMaze; }

    class InputMaze : public QMainWindow
    {
        Q_OBJECT

        public:
            // Constructor.
            InputMaze(QWidget *parent = nullptr);
            InputMaze(int, int);

            // Destructor.
            ~InputMaze();

        private:
            // Variable.
            Ui::InputMaze *ui;
            int height, width;
            NutnDS_Maze::Element map[NutnDS_Maze::kMaxHeight][NutnDS_Maze::kMaxWidth];
            SolveMaze* solveMaze;
            QStatusBar* statusbar_readme;

        private slots:
            void markMapSelection();
            void markMapFinal();
            void solvingMaze();

        signals:
    };

#endif

