
#include <sstream>
#include <math.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*constructor*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    current_row(0),current_col(0),max_row(0),max_col(0)
{
    ui->setupUi(this);
    inicio();

    QObject::connect(ui->tableWidget,
                     SIGNAL(cellChanged(int,int)),
                     this,
                     SLOT(on_tableWidget_cellChanged(int,int)));
    /*
    QObject::connect(ui->pushButton_ADDRows,
                     SIGNAL(clicked()),
                     this,
                     SLOT(on_pushButton_ADDRows_clicked()));
    QObject::connect(ui->pushButton_ADDColumns,
                     SIGNAL(clicked()),
                     this,
                     SLOT(on_pushButton_ADDColumns_clicked()));
    */
    QObject::connect(ui->tableWidget,
                     SIGNAL(cellClicked(int,int)),
                     this,
                     SLOT(on_tableWidget_cellClicked(int,int)));
    QObject::connect(ui->tableWidget,
                     SIGNAL(cellEntered(int,int)),
                     this,
                     SLOT(on_tableWidget_cellEntered(int,int)));
    QObject::connect(ui->MiFuncion,
                     SIGNAL(editingFinished()),
                     this,
                     SLOT(on_MiFuncion_editingFinished()));
}


/*Destructor*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*-- Ampliacion horizontal--*/
void MainWindow::resizeh()
{
    for(register coord i=0; i<my_incremento; ++i){
        ui->tableWidget->insertColumn(max_col+i);
        insert_header(max_col+i);
    }
    max_col+=my_incremento;
    ui->tableWidget->setHorizontalHeaderLabels(horizontal_Headers);
}

/*Agregando valores a la cabecera*/
void MainWindow::insert_header(coord col)
{
    string col_alpha = "";
    coord res,
        factor=26,/*numero de digitos del alfabeto*/
        temp = col;
    for(register coord i=0; temp>25; ++i){
        res = temp%factor;/*residuo a convertir en caracter alpha*/
        col_alpha = char(res+65) + col_alpha;
        temp = temp/factor;
        --temp;
    }
    col_alpha = char(temp+65) + col_alpha;
    horizontal_Headers << QString::fromStdString(col_alpha);
}

/*-- Ampliacion vertical--*/
void MainWindow::resizev()
{
    for(register coord i=0; i<my_incremento; ++i)
        ui->tableWidget->insertRow(max_row+i);
    max_row+=my_incremento;
}

/*--  para ampliar el vector horizontal y verticalmente--*/
void MainWindow::resize()
{
    resizeh();
    resizev();
}

/*inicia la matriz con filas y columnas 10x10 por defecto*/
void MainWindow::inicio(coord incremento)
{
    my_incremento = incremento;
    resize();
}

/*detecta las coordenadas de la celda presionada*/
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    set_current_row(row);
    set_current_col(column);
    ui->My_Coord->setText("");
    ui->My_Coord->setText(my_position(row, column));
    ui->MiFuncion->setText("");
    get_function();

    /*implementar qLineEdit myFuncion para que muestre el resultado de la
    formula de esa coordenada si la hay y su posicion conectar a su funcion*/
}

QString MainWindow::my_position(int &row,int &col)
{
    string col_alpha = "";
    int res,
        factor=26,/*numero de digitos del alfabeto*/
        temp = col;
    for(register int i=0; temp>25; ++i){
        res = temp%factor;/*residuo a convertir en caracter alpha*/
        col_alpha = char(res+65) + col_alpha;
        temp = temp/factor;
        --temp;
    }
    col_alpha = char(temp+65) + col_alpha;
    stringstream ss;
    ss << row+1;
    string row_numeric = ss.str();
    return QString::fromStdString(col_alpha+row_numeric);
}

/*retorna valor de fila*/
inline coord MainWindow::get_current_row() const
{
    return current_row;
}

/*retorna valor de columna*/
inline coord MainWindow::get_current_col() const
{
    return current_col;
}

/*Accion realizada tras el ingreso de datos*/
void MainWindow::on_tableWidget_cellEntered(int row, int column)
{
    ui->My_Coord->setText("");
    ui->My_Coord->setText(my_position(row, column));
    //ui->tableWidget->setItem(0,1,new QTableWidgetItem("cellEntered"));
    //my_matriz.set_nuevo_valorx(current_row,current_col,ui->tableWidget->setItem(current_row,current_col,this));
    /*Implementar funcion que conecte con la matriz logica
    y permita enviar los datos del valor y/o funcion*/
}

void MainWindow::on_tableWidget_cellActivated(int row, int column)
{
    ui->My_Coord->setText("");
    ui->My_Coord->setText(my_position(row, column));
    //ui->tableWidget->setItem(0,2,new QTableWidgetItem("cellActivated"));
    //ui->My_Coord->setText();
    //implementar my_coord que indique la posicion
}

/*cambio de celda*/
void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    Func func_a = ui->tableWidget->item(row,column)->text().toStdString();
    nodo& actual_nodo = my_matriz.get_nodo(current_row,current_col);
    actual_nodo.set_my_function(func_a);
    ui->My_Coord->setText("");
    ui->My_Coord->setText(my_position(row, column));
   // ui->tableWidget->setItem(0,3,new QTableWidgetItem("cellChanged"));
}

/*void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    //int my_col=ui->tableWidget->column(ui->tableWidget->currentItem());
    //int my_row=ui->tableWidget->row(ui->tableWidget->currentItem());
    connect(ui->Table->horizontalHeader(), SIGNAL(sectionClicked(int)), SLOT(Table_HeaderClick(int)));

}*/

/*Aumenta las columnas visuales y no visuales en caso de click en boton ADDColumns*/
void MainWindow::on_pushButton_ADDColumns_clicked()
{
    resizeh();
    my_matriz.resizeh();
}

/*Aumenta las columnas visuales y no visuales en caso de click en boton ADDRows*/
void MainWindow::on_pushButton_ADDRows_clicked()
{
    resizev();
    my_matriz.resizev();
}
 /*Ingresa nuevo valor de la funcion al nodo de la posicion actual */
void MainWindow::set_function()
{
    nodo& actual_nodo = my_matriz.get_nodo(current_row,current_col);
    actual_nodo.set_my_function(ui->MiFuncion->text().toStdString());
}

/*devuelve el valor de la funcion del nodo en la posicion actual*/
void MainWindow::get_function()
{
    ui->MiFuncion->setText("");
    nodo& actual_nodo = my_matriz.get_nodo(current_row,current_col);
    ui->MiFuncion->setText(QString::fromStdString(actual_nodo.get_my_function()));
}

void MainWindow::on_MiFuncion_editingFinished()
{
    set_function();
    QTableWidgetItem *item = new QTableWidgetItem(ui->MiFuncion->text());
    ui->tableWidget->setItem(current_row,current_col,item);
}
