#ifndef QBUTTONRIGHTCLICK_H

    #define QBUTTONRIGHTCLICK_H

    #include <QPushButton>
    #include <QMouseEvent>

    class QButton : public QPushButton
    {
        Q_OBJECT

        public:
            explicit QButton(QWidget* arent = nullptr);

        private slots:
            void mousePressEvent(QMouseEvent*);

        signals:
            void rightClicked();
    };

#endif
