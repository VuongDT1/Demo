#ifndef CUASOMA_H
#define CUASOMA_H

#include <QtWidgets>
class CuaSoMa : public QDialog {
    public:
    CuaSoMa(QString &maNguon, QWidget *cuaSoMe);

    private:
    QTextEdit *m_maNguon;
    QPushButton *thoat;
};

#endif // CUASOMA_H

