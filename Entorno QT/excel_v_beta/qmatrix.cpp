#include "qmatrix.h"
#include "ui_qmatrix.h"

qmatrix::qmatrix(QWidget *parent) : QMainWindow(parent), ui(new Ui::qmatrix)
{
    ui->setupUi(this);
    filas = 50;  ///
    columnas =50; ///
    ui->tableWidget->setRowCount(filas); /// numero filas
    ui->tableWidget->setColumnCount(columnas); /// numerop columnas
}

qmatrix::~qmatrix()
{
    delete ui;
}

void qmatrix::on_filas_clicked()/// aumenta fila
{
       ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       ++filas;
}

void qmatrix::on_columnas_clicked()/// aumenta columna
{
       ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
       ++columnas;
}

void qmatrix::on_agregar_clicked() /// aumenta filas y columnas
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ++filas;
    ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
    ++columnas;
}


void qmatrix::on_removeRow_clicked() /// disminuye ultima fila
{
   --filas;
    ui->tableWidget->removeRow(filas);

}

void qmatrix::on_removeColumn_clicked() /// disminuye ultima columna
{
    --columnas;
    ui->tableWidget->removeColumn(columnas);
}

void qmatrix::on_removeAll_clicked()   /// disminuye columnas y filas
{
     --filas;
     --columnas;
     ui->tableWidget->removeRow(filas);
     ui->tableWidget->removeColumn(columnas);


}
/// _____________________________________________________________________________-
void qmatrix::on_ok_clicked()
{
               ui->formula2->setText(ui->formula->text());

               QTableWidgetItem *item = new QTableWidgetItem(ui->formula->text());
               ui->tableWidget->setItem(row_x,column_y,item);/// inserta item en la fila 10,columna 10

}
