#ifndef _QMATRIX_H_
#define _QMATRIX_H_
#include <QMainWindow>
#include <iostream>
using namespace std;

namespace Ui {
    class qmatrix;
}

class qmatrix : public QMainWindow
{
    Q_OBJECT
public:
    explicit qmatrix(QWidget *parent = 0);
    virtual ~qmatrix();
private slots:
    void on_filas_clicked(); /// aumenta fila
    void on_columnas_clicked(); /// aumenta columna
    void on_agregar_clicked(); /// aumenta fila y columna
    void on_removeRow_clicked();  /// elimina fila
    void on_removeColumn_clicked(); /// elimina columna
    void on_removeAll_clicked();  /// elimina fila y columna
    void on_ok_clicked();
private:
    Ui::qmatrix *ui;
    typedef  int posicion;
    posicion filas;
    posicion columnas;
    string dato;
    posicion row_x=0;     ///
    posicion column_y=0;  ///
};


#endif // _QMATRIX_H_
