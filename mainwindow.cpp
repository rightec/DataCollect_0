#include "mainwindow.h"
#include "ui_mainwindow.h"


const QString csWhiteColor = "background-color: rgb(255, 255, 255);";



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startSetUp();

}


void MainWindow::startSetUp()
{
    //Build the main page
    buildFrameStruct();

}

bool MainWindow::buildFrameStruct()
{
   bool bRetVal = false;
   int iRowIndex= 0;
   int iColIndex = 0;

   for (iRowIndex = 0;iRowIndex< MAINW_NUMROW;iRowIndex++){
       for (iColIndex = 0; iColIndex<MAINW_NUMCOL; iColIndex++){
           framArray[iRowIndex][iColIndex] = new (QFrame);
           ui->gLayMainForm->addWidget(framArray[iRowIndex][iColIndex], iRowIndex, iColIndex);
            qDebug() << "Item:" << iRowIndex << iColIndex;
           bRetVal = setSingleFrame(framArray[iRowIndex][iColIndex]);
           if (bRetVal == false){
               //Force the break of both for cycle
               iColIndex = MAINW_NUMCOL;
               iRowIndex = MAINW_NUMROW;
           }//else
       }//end for column cycle
   }//end for row cycle

   return bRetVal;
}

bool MainWindow::setSingleFrame(QFrame *frameToSet)
{
   bool bRetVal = false;

   if (frameToSet != nullptr){
       frameToSet->setLineWidth(MAINW_FRAMELW);
       frameToSet->setFrameShape(QFrame::Box);
       frameToSet->setStyleSheet(csWhiteColor);
       bRetVal = true;
   }else{
       bRetVal = false;
   }

   return bRetVal;
}

MainWindow::~MainWindow()
{
    delete ui;
}
