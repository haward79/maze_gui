#ifndef SOLVEMAZE_H

    #define SOLVEMAZE_H

    #include <QMainWindow>
    #include "Maze.h"

    namespace Ui { class SolveMaze; }

    class SolveMaze : public QMainWindow
    {
        Q_OBJECT

        public:
            // Constructor.
            explicit SolveMaze(QWidget *parent = nullptr);
            explicit SolveMaze(int, int, NutnDS_Maze::Element[NutnDS_Maze::kMaxHeight][NutnDS_Maze::kMaxWidth]);

            // Destructor.
            ~SolveMaze();

        private:
            // Variable.
            Ui::SolveMaze *ui;
            QStatusBar* statusbar_readme;
    };

#endif

