#include "CuaSoMa.h"
CuaSoMa::CuaSoMa (QString &maNguon, QWidget *cuaSoMe = 0) : QDialog(cuaSoMe){
    m_maNguon = new QTextEdit();
    m_maNguon ->setPlainText(maNguon);
    m_maNguon ->setReadOnly(true);
    m_maNguon ->setFont(QFont("Courier"));
    m_maNguon ->setLineWrapMode(QTextEdit::NoWrap);

    thoat = new QPushButton("Thoát");

    QVBoxLayout *lopChinh = new QVBoxLayout;
    lopChinh ->addWidget(m_maNguon);
    lopChinh ->addWidget(thoat);

    resize(350, 450);
    setLayout(lopChinh);

    connect(thoat, SIGNAL(clicked()), this, SLOT(accept()));
}
