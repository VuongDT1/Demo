#include "CuaSoChinh.h"
#include "CuaSoMa.h"
CuaSoChinh::CuaSoChinh() {
    // Tao ra cac lop sap xep va cac widget

    tenLop = new QLineEdit();
    tenLopMe = new QLineEdit();

    QFormLayout *lopThongTin = new QFormLayout();
    lopThongTin->addRow("Tên &lớp :", tenLop);
    lopThongTin->addRow("Tên lớp &mẹ :", tenLopMe);

    QGroupBox *nhomThongTin = new QGroupBox("Thông tin lớp");
    nhomThongTin->setLayout(lopThongTin);


    // Cac tuy chon dung khi tao ma
    quyenTruyCap = new QCheckBox("Tránh bao gồm kép các gói trong tiêu đề");
    quyenTruyCap->setChecked(true);
    hamKhoiTao = new QCheckBox("Tạo phương thức khởi tạo mặc định");
    hamHuy = new QCheckBox("Tạo phương thức hủy mặc định");

    QVBoxLayout *lopTuyChon = new QVBoxLayout();
    lopTuyChon->addWidget(quyenTruyCap);
    lopTuyChon->addWidget(hamKhoiTao);
    lopTuyChon->addWidget(hamHuy);

    QGroupBox *nhomTuyChon = new QGroupBox("Các tùy chọn");
    nhomTuyChon->setLayout(lopTuyChon);



    // Chu thich
    tacGia = new QLineEdit();
    ngay = new QDateEdit();
    ngay->setDate(QDate::currentDate());
    mucDich = new QTextEdit();

    QFormLayout *lopChuThich = new QFormLayout();
    lopChuThich->addRow("&Tác giả :", tacGia);
    lopChuThich->addRow("&Ngày :", ngay);
    lopChuThich->addRow("Mụ&c đích :", mucDich);

    chuThich = new QGroupBox("Thêm chú thích");
    chuThich->setCheckable(true);
    chuThich->setChecked(false);
    chuThich->setLayout(lopChuThich);


    // Cac nut bam
    nutSinhMa = new QPushButton("&Sinh mã !");
    thoat = new QPushButton("&Thoát");

    QHBoxLayout *lopNutBam = new QHBoxLayout();
    lopNutBam->setAlignment(Qt::AlignRight);

    lopNutBam->addWidget(nutSinhMa);
    lopNutBam->addWidget(thoat);


    //Lop sap xep chinh trong cua so
    QVBoxLayout *lopChinh = new QVBoxLayout();
    lopChinh->addWidget(nhomThongTin);
    lopChinh->addWidget(nhomTuyChon);
    lopChinh->addWidget(chuThich);
    lopChinh->addLayout(lopNutBam);

    setLayout(lopChinh);
    setWindowTitle("Kiến trúc sư X");
    setWindowIcon(QIcon("icon.png"));
    resize(400, 450);

    // Ket noi cac tin hieu va cac slot
    connect(thoat, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(nutSinhMa, SIGNAL(clicked()), this, SLOT(sinhMa()));

}

void CuaSoChinh::sinhMa() {
    // Kiem tra xem nguoi dung da nhap ten lop chua, neu chua thi ket thuc ham
    if (tenLop->text().isEmpty()) {
        QMessageBox::critical(this, "Thông báo lỗi", "Xin mời nhập tên lớp bạn muốn tạo !");
        return; // Ket thuc
    }

    // Neu moi thu deu on, thuc hien sinh ma
    QString maNguon;

    // Thuc hien tao ma nguon dua tren gia tri cac truong nhap vao tu cua so
    if (chuThich->isChecked()) {// Them chu thich
        maNguon += "/*\nTác giả : " + tacGia->text() + "\n";
        maNguon += "Ngày : " + ngay->date().toString() + "\n\n";
        maNguon += "Mục đích :\n" + mucDich->toPlainText() + "\n*/\n\n\n";
    }

    if (quyenTruyCap->isChecked())
    {
        maNguon += "#ifndef HEADER_" + tenLop->text().toUpper() + "\n";
        maNguon += "#define HEADER_" + tenLop->text().toUpper() + "\n\n\n";
    }

    maNguon += "class " + tenLop->text();

    if (!tenLopMe->text().isEmpty()) {
        maNguon += " : public " + tenLopMe->text();
    }

    maNguon += " {\n    public:\n";
    if (hamKhoiTao->isChecked()) {
        maNguon += "        " + tenLop->text() + "();\n";
    }
    if (hamHuy->isChecked()) {
        maNguon += "        ~" + tenLop->text() + "();\n";
    }

    if (quyenTruyCap->isChecked()) {
        maNguon += "\n\n    protected:\n";
        maNguon += "\n\n    private:\n";
    }
    maNguon += "};\n\n";
    maNguon += "#endif\n";

    // Tao ra cua so ma voi tham so la doan ma vua tao ra va hien thi cua so
    CuaSoMa *cuaSoMa= new CuaSoMa (maNguon, this);
    cuaSoMa->exec();
}

