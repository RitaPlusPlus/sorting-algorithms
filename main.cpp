#include <iostream>

using namespace std;

#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "array-vector.h"

int main(int argc, char *argv[])
{
    ArrayVector<int> b;
    b.insert(0, 5);
    b.insert(0, 6);
    b.insert_back(9);

    cout << b.at(2) << endl;
    b.erase_back();
    cout << b.at(0) << endl;
    b[0] = 5;
    cout << b.at(0) << endl;

    b.sort(ArrayVector<int>::SELECTION_SORT);


    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "sorting-algorithms_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
