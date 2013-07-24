#include <sstream>
#include <math.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constante.h"

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
        QObject::connect(ui->tableWidget,
                         SIGNAL(cellDoubleClicked(int,int)),
                         this,
                         SLOT(on_tableWidget_celldoubleClicked(int,int)));
        QObject::connect(ui->tableWidget,
                         SIGNAL(cellPressed(int,int)),
                         this,
                         SLOT(on_tableWidget_cellPressed(int,int)));
        /*
        QObject::connect(ui->MiFuncion,
                         SIGNAL(editingFinished()),
                         this,
                         SLOT(on_MiFuncion_editingFinished()));
                         */
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Usado en resizeh: Agregando valores a la cabecera*/
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

/*-- Usado en resize: Ampliacion horizontal--*/
void MainWindow::resizeh()
{
    for(register coord i=0; i<my_incremento; ++i){
        ui->tableWidget->insertColumn(max_col+i);
        insert_header(max_col+i);
    }
    max_col+=my_incremento;
    ui->tableWidget->setHorizontalHeaderLabels(horizontal_Headers);
}

/*-- Usado en resize: Ampliacion vertical--*/
void MainWindow::resizev()
{
    for(register coord i=0; i<my_incremento; ++i)
        ui->tableWidget->insertRow(max_row+i);
    max_row+=my_incremento;
}

/*-- Usado en inicio: Amplia la tabla horizontal y verticalmente--*/
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

/*Usado en cellClicked: Muestra valor de la funcion del nodo en la posicion actual de la tabla*/
void MainWindow::get_function()
{
    //ui->MiFuncion->setText("");

    if(ui->tableWidget->item(current_row,current_col)!=NULL)
    {
        nodo& this_nodo = my_matriz.get_nodo(current_row,current_col);
        ui->MiFuncion->setText(QString::fromStdString(this_nodo.get_my_function()));
        T valor = this_nodo.get_value();
        std::ostringstream valorn;
        valorn << valor;
        string valor_n = valorn.str();
        ui->tableWidget->item(current_row,current_col)->setText(QString::fromStdString(valor_n));
    }
}

/*Usado en cellClicked: transforma fila y columna de numeros a alphanumerico */
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

/*Evento cellClicked: Acciones realizadas tras la detección de una celda clickeada*/
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    set_current_row(row);
    set_current_col(column);
    ui->My_Coord->setText("");
    ui->My_Coord->setText(my_position(row, column));
    get_function();
}

/*devuelve valor de fila actual*/
inline coord MainWindow::get_current_row() const
{
    return current_row;
}

/*devuelve valor de columna actual*/
inline coord MainWindow::get_current_col() const
{
    return current_col;
}

void MainWindow::on_tableWidget_cellPressed(int row, int column)
{
    ui->My_Coord->setText("cellPressed");
}

/*Accion realizada tras el ingreso de datos*/
void MainWindow::on_tableWidget_cellEntered(int row, int column)
{
    //ui->My_Coord->setText("");
    ui->My_Coord->setText(":" + my_position(row, column));
    //ui->My_Coord->setText(my_position(row, column));

    //ui->tableWidget->setItem(0,1,new QTableWidgetItem("cellEntered"));
    //my_matriz.set_nuevo_valorx(current_row,current_col,ui->tableWidget->setItem(current_row,current_col,this));
    /*Implementar funcion que conecte con la matriz logica
    y permita enviar los datos del valor y/o funcion*/
}

void MainWindow::on_tableWidget_cellActivated(int row, int column)
{

    ui->My_Coord->setText("cellActivated");
    //ui->My_Coord->setText("cellactivated");
    //ui->My_Coord->setText(my_position(row, column));

    //ui->tableWidget->setItem(0,2,new QTableWidgetItem("cellActivated"));
    //ui->My_Coord->setText();
    //implementar my_coord que indique la posicion
}


/*cambio de celda*/
void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    Func func_a = ui->tableWidget->item(row,column)->text().toStdString();
    if (is_constante(func_a))
    {
        expresion* this_const = new constante(func_a);
        T new_valor = this_const->get_value();
        nodo& this_nodo = my_matriz.get_nodo(current_row,current_col);
        this_nodo.set_my_function(func_a);
        this_nodo.set_value(new_valor);
        //ui->My_Coord->setText("");
        //ui->My_Coord->setText(my_position(row, column));
    }
   // ui->tableWidget->setItem(0,3,new QTableWidgetItem("cellChanged"));
}

/*void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    //int my_col=ui->tableWidget->column(ui->tableWidget->currentItem());
    //int my_row=ui->tableWidget->row(ui->tableWidget->currentItem());
    connect(ui->Table->horizontalHeader(), SIGNAL(sectionClicked(int)), SLOT(Table_HeaderClick(int)));

}*/

/*Aumenta 10 columnas visuales y no visuales en caso de click en boton ADDColumns*/
void MainWindow::on_pushButton_ADDColumns_clicked()
{
    resizeh();
    my_matriz.resizeh();
    my_stx.resizeh();
}

/*Aumenta 10 filas visuales y no visuales en caso de click en boton ADDRows*/
void MainWindow::on_pushButton_ADDRows_clicked()
{
    resizev();
    my_matriz.resizev();
    my_stx.resizev();
}

 /*Ingresa nuevo valor de la funcion al nodo de la posicion actual */
void MainWindow::set_function()
{
    string new_funcion = ui->MiFuncion->text().toStdString();
    start_logic_function(new_funcion);
    /*
    nodo& actual_nodo = my_matriz.get_nodo(current_row,current_col);
    actual_nodo.set_my_function(new_funcion);
    if(new_funcion.size()>0)
    {
    stx& actual_stx = my_stx.get_stx(current_row,current_col);
    actual_stx.set_func(new_funcion);
    actual_stx.edit_ptr_matrix(&my_matriz);
    actual_stx.reduction();
    QTableWidgetItem *itemm = new QTableWidgetItem(QString::fromStdString(actual_stx.my_func));
    ui->tableWidget->setItem(0,1,itemm);
    actual_stx.atomizer();
    int tam=actual_stx.list_atomos.size();
    stringstream stam;
    stam << tam;
    string s_tam = stam.str();
    QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString("longitud = "+s_tam));
    ui->tableWidget->setItem(1,0,item);
    int col_x_=0;
    for (size_t i = 0; i < actual_stx.list_atomos.size(); ++i){
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString("at = " + actual_stx.list_atomos[i]));
        ui->tableWidget->setItem(1,++col_x_,item);
    }
    actual_stx.starting_vector();
    actual_stx.Number_Operators();
    int mas = actual_stx.number_operators_[0],
        menos = actual_stx.number_operators_[1],
        por = actual_stx.number_operators_[2],
        entre = actual_stx.number_operators_[3],
        seno = actual_stx.number_operators_[4];
    stringstream ssa, ssb, ssc, ssd, sse;
    ssa << mas; ssb << menos; ssc << por ; ssd << entre; sse << seno;
    string s_mas = ssa.str();
    string s_menos = ssb.str();
    string s_por = ssc.str();
    string s_entre = ssd.str();
    string s_seno = sse.str();
    QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString("+ = "+s_mas));
    ui->tableWidget->setItem(3,1,item1);
    QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString("- = "+s_menos));
    ui->tableWidget->setItem(4,1,item2);
    QTableWidgetItem *item3 = new QTableWidgetItem(QString::fromStdString("* = "+s_por));
    ui->tableWidget->setItem(5,1,item3);
    QTableWidgetItem *item4 = new QTableWidgetItem(QString::fromStdString("/ = "+s_entre));
    ui->tableWidget->setItem(6,1,item4);
    QTableWidgetItem *item5 = new QTableWidgetItem(QString::fromStdString("sin = "+s_seno));
    ui->tableWidget->setItem(7,1,item5);
    actual_stx.next_operator();
    int mi_sgte_operador = actual_stx.next_op;
    stringstream mso;
    mso << mi_sgte_operador;
    string s_mso = mso.str();
    QTableWidgetItem *itemo = new QTableWidgetItem(QString::fromStdString("n_priority = "+s_mso));
    ui->tableWidget->setItem(9,1,itemo);

    expresion* pos_root = actual_stx.detect_root(0,actual_stx.list_atomos.size());
    double val_pos_root = pos_root->get_value();
    std::ostringstream mroot;
    mroot << val_pos_root ;
    std::string s_root = mroot.str();
    if (ui->tableWidget->item(current_row,current_col)!= NULL)
        ui->tableWidget->item(current_row,current_col)->setText(QString::fromStdString(s_root));
    else{
        QTableWidgetItem *itemroot = new QTableWidgetItem(QString::fromStdString("principal root = "+s_root));
        ui->tableWidget->setItem(current_row,current_col,itemroot);
    }
    }
    */
}

void MainWindow::start_logic_function(string new_function)
{
    if(new_function[0]=='=' && new_function.length()>1)
    {
        //ingresamos valor de la funcion a nodo (=)
        nodo& this_nodo = my_matriz.get_nodo(current_row,current_col);
        this_nodo.set_my_function(new_function);
        //ahora ejecutamos stx quitando el =
        new_function.erase(new_function.begin());
        stx& this_stx = my_stx.get_stx(current_row, current_col);
        this_stx.set_func(new_function);
        this_stx.clean(); //limpia vector de dependencias
        this_stx.edit_ptr_matrix(&my_matriz);
        this_stx.reduction();
        this_stx.atomizer();
        this_stx.starting_vector();
        this_stx.Number_Operators();
        this_stx.next_operator();
        expresion* root_reload= this_stx.detect_root(0,this_stx.list_atomos.size());
        T new_valor = root_reload->get_value();
        //Ahora agregamos a valor T del Nodo;
        this_nodo.set_value(new_valor);
        //Imprimimos valores de T y Func donde corresponda
        std::ostringstream nvalor;
        nvalor << new_valor ;
        std::string n_valor = nvalor.str();
        if (ui->tableWidget->item(current_row,current_col)!= NULL)
            ui->tableWidget->item(current_row,current_col)->setText(QString::fromStdString(n_valor));
        else{
            QTableWidgetItem *item_valor_n = new QTableWidgetItem(QString::fromStdString(n_valor));
            ui->tableWidget->setItem(current_row,current_col,item_valor_n);
        }
    }else if(is_constante(new_function))
    {
        expresion* this_const = new constante(new_function);
        T new_valor = this_const->get_value();
        nodo& this_nodo = my_matriz.get_nodo(current_row,current_col);
        this_nodo.set_value(new_valor);
        this_nodo.set_my_function(new_function);
        //Imprimimos valores de T y Func donde corresponda
        ui->MiFuncion->setText(QString::fromStdString(new_function));
        std::ostringstream nvalor;
        nvalor << new_valor ;
        std::string n_valor = nvalor.str();
        if (ui->tableWidget->item(current_row,current_col)!= NULL)
            ui->tableWidget->item(current_row,current_col)->setText(QString::fromStdString(n_valor));
        else{
            QTableWidgetItem *item_valor_n = new QTableWidgetItem(QString::fromStdString(n_valor));
            ui->tableWidget->setItem(current_row,current_col,item_valor_n);
        }
    }else
    {
        //mensaje de error por el inicializador =
    }
}
 /*Comprueba si un string es de tipo T (double)*/
bool MainWindow::is_constante(const Func &atomo)
{
    int point=0;/*numero de puntos en el atomo*/
    for(register size_t i=0; i<atomo.size(); ++i)
        if(atomo[i] < '0' || '9' < atomo[i] ){
            if(atomo[i]=='.')
                ++point;
            else
                return false;
        }
    if(point>1)
        return false;
    return true;
}

void MainWindow::restart_function(string funcion)
{

}


/*Accion realizada tras el ingreso o editado de la funcion*/
void MainWindow::on_MiFuncion_editingFinished()
{
    set_function();
    /*
    QTableWidgetItem *item = new QTableWidgetItem(ui->MiFuncion->text());
    ui->tableWidget->setItem(current_row,current_col,item);
    */
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{

}

void MainWindow::on_actionPaste_triggered()
{
    //ui->tableWidget->item(current_row,current_col)->text().co
}

/*Evento Save: Guarda el archivo actual por defecto como prueba.txt*/
void MainWindow::on_actionSave_triggered()
{
    char* name_file= "prueba.txt";
    my_matriz.SaveDisk(name_file);
}

void MainWindow::on_actionNew_triggered()
{
    mfilename = "";
    for(register int i=0; i< current_row; ++i)
        for(register int j=0; j< current_row; ++j)
            ui->tableWidget->item(i,j)->setText("");
}

void MainWindow::on_actionCut_triggered()
{

}

void MainWindow::on_actionCopy_triggered()
{

}
