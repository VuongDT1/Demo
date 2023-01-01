#ifndef CUASOCHINH_H
#define CUASOCHINH_H
#include <QtWidgets>
class CuaSoChinh : public QWidget {
    Q_OBJECT

    public:
    CuaSoChinh();

    private slots:
    void sinhMa();

    private:
    QLineEdit *tenLop;
    QLineEdit *tenLopMe;
    QCheckBox *quyenTruyCap;
    QCheckBox *hamKhoiTao;
    QCheckBox *hamHuy;
    QGroupBox *chuThich;
    QLineEdit *tacGia;
    QDateEdit *ngay;
    QTextEdit *mucDich;
    QPushButton *nutSinhMa;
    QPushButton *thoat;
};

#endif // CUASOCHINH_H

