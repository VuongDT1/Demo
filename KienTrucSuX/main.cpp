#include <QApplication>
#include "CuaSoChinh.h"
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    CuaSoChinh cuaSo;
    cuaSo.show();

    return app.exec();
}
