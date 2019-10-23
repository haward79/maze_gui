#ifndef InputMaze_h

    #define InputMaze_h

    #include <QMainWindow>
    #include "Maze.h"

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
            NutnDS_Maze::Element map[NutnDS_Maze::kMaxHeight][NutnDS_Maze::kMaxWidth];
    };

#endif

