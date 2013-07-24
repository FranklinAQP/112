#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.h"
#include "analizer_stx.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //friend class matrix;
    //friend class stx;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tableWidget_cellActivated(int row, int column);
//    void on_tableWidget_clicked(const QModelIndex &index);
    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_cellEntered(int row, int column);

    void on_pushButton_ADDColumns_clicked();

    void on_pushButton_ADDRows_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_MiFuncion_editingFinished();


private:
    Ui::MainWindow *ui;
    coord current_row, /*--fila actual--*/
          current_col, /*--columna actual--*/
          max_row, /*--maximo de espacio en filas--*/
          max_col, /*--maximo de espacio en columnas--*/
          my_incremento; /*--incremento en el resize--*/
    coord get_current_row() const; /*retorna valor de fila*/
    coord get_current_col() const;/*retorna valor de columna*/
    inline coord &get_max_col() {return max_col;}/*retorna maximo de columnas*/
    inline coord &get_max_row() {return max_row;}/*retorna maximo de filas*/
    void resizeh(); /*-- para ampliar columnas --*/
    void resizev(); /*--para ampliar filas--*/
    void resize(); /*--para ampliar la matriz en filas y columnas--*/
    void inicio(coord my_incremento=10); /*--creo mi matriz--*/
    QString my_position(int &row, int &col);
    QStringList horizontal_Headers;
    void insert_header(coord columna);
    inline void set_current_row(coord fila){current_row=fila;}/*cambia el valor de fila actual*/
    inline void set_current_col(coord col){current_col=col;}/*cambia el valor de columna actual*/
    void set_function();/*Ingresa una funcion en un nodo de fila y columna actual*/
    void get_function();
    //QStandardItemModel *model;

    matrix my_matriz;
    analizer_stx my_stx;

};

#endif // MAINWINDOW_H
