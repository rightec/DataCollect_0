#include "mainwindow.h"
#include "ui_mainwindow.h"


const QString csWhiteColor = "background-color: rgb(255, 255, 255);";



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    for (int iRowIndex = 0;iRowIndex< MAINW_NUMROW;iRowIndex++){
        for (int iColIndex = 0; iColIndex<MAINW_NUMCOL; iColIndex++){
             qDebug() << "Value:" << labelNameArray[iRowIndex][iColIndex];
        }
    }

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
           // qDebug() << "Item:" << iRowIndex << iColIndex;
           bRetVal = setSingleFrame(framArray[iRowIndex][iColIndex]);
           if (bRetVal == false){
               //Force the break of both for cycle
               iColIndex = MAINW_NUMCOL;
               iRowIndex = MAINW_NUMROW;
           }else{
               vBoxLayoutArray[iRowIndex][iColIndex] = new (QVBoxLayout);
               bRetVal = setSingleVLayout(vBoxLayoutArray[iRowIndex][iColIndex], iRowIndex,iColIndex);
               if (bRetVal == false){
                   //Force the break of both for cycle
                   iColIndex = MAINW_NUMCOL;
                   iRowIndex = MAINW_NUMROW;
               }else{
                   framArray[iRowIndex][iColIndex]->setLayout(vBoxLayoutArray[iRowIndex][iColIndex]);
               }
           }
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

bool MainWindow::setSingleVLayout(QVBoxLayout *vBoxLayoutToSet,int row, int col)
{
    bool bRetVal = false;

    if (vBoxLayoutToSet != nullptr){
        labelArray[row][col] = new (QLabel);
        bRetVal = setSingleLabel(labelArray[row][col]);
        if (bRetVal == true){
            vBoxLayoutToSet->addWidget(labelArray[row][col]);
            textEditArray[row][col] = new (QPlainTextEdit);
            bRetVal = setSinglePlainText(textEditArray[row][col]);
            if (bRetVal == true){
                vBoxLayoutToSet->addWidget(textEditArray[row][col]);
            }//else
        }//else
    }else{
        bRetVal = false;
    }

    return bRetVal;

}

bool MainWindow::setSingleLabel(QLabel *labelToSet)
{
    bool bRetVal = false;

    if (labelToSet != nullptr){
        labelToSet->setText("Ciccio");
        labelToSet->setFrameShape(QFrame::Box);
        labelToSet->setLineWidth(MAINW_FRAMELW);
        labelToSet->setAlignment(Qt::AlignCenter);
        bRetVal = true;
    }else{
        bRetVal = false;
    }

    return bRetVal;

}

bool MainWindow::setSinglePlainText(QPlainTextEdit *plainTextToSet)
{
    bool bRetVal = false;

    if (plainTextToSet != nullptr){
        plainTextToSet->setPlainText("Pasticcio");
        plainTextToSet->setFrameShape(QFrame::Box);
        plainTextToSet->setLineWidth(MAINW_FRAMELW);
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
