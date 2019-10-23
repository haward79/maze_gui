#ifndef InputMaze_h

    #define InputMaze_h

    #include <QMainWindow>

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
    };

#endif

