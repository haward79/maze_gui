#ifndef InputSize_h

    #define InputSize_h

    #include <QMainWindow>
    #include "InputMaze.h"
    #include "Maze.h"

    namespace Ui { class InputSize; }

    class InputSize : public QMainWindow
    {
        Q_OBJECT

        public:
            // Constructor.
            InputSize(QWidget *parent = nullptr);

            // Destructor.
            ~InputSize();

            // Variable.
            InputMaze* inputMaze;

            // Method.
            void load();

        private:
            // Variable.
            Ui::InputSize *ui;

            // Method.
            bool isDigit(QString) const;

        private slots:
            void on_lineEdit_height_textEdited(const QString&);
            void on_lineEdit_width_textEdited(const QString&);
            void on_pushButton_ok_clicked();
    };

#endif

