#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <mainwindowdef.h>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QPlainTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*!
     * \brief startSetUp: main windows set up style
     */
    void startSetUp();

private:
    Ui::MainWindow *ui;
    /*!
     * \brief buildFrameStruct
     * \return true if the frame structure is correctly built
     */
    bool buildFrameStruct();

    /*!
     * \brief setSingleFrame
     * \param frameToSet: Frame to set the style
     * \return true if the frame is set false if the parameter is null
     */
    bool setSingleFrame(QFrame *frameToSet);

    /*!
     * \brief setSingleVLayout
     * \param vBoxLayoutToSet
     * \param row
     * \param col

     * \return true if the layout is set false if the input parameter is null
     */
    bool setSingleVLayout(QVBoxLayout *vBoxLayoutToSet,int row, int col);


    /*!
     * \brief setSingleLabel
     * \param labelToSet
     * \return
     */
    bool setSingleLabel(QLabel *labelToSet);

    /*!
     * \brief setSinglePlainText
     * \param plainTextToSet
     * \return
     */
    bool setSinglePlainText(QPlainTextEdit *plainTextToSet);


   /** ATTRIBUTES*/
    QFrame *framArray[MAINW_NUMROW][MAINW_NUMCOL];
    QLabel *labelArray[MAINW_NUMROW][MAINW_NUMCOL];
    QVBoxLayout *vBoxLayoutArray[MAINW_NUMROW][MAINW_NUMCOL];
    QPlainTextEdit *textEditArray[MAINW_NUMROW][MAINW_NUMCOL];
    const QString labelNameArray[MAINW_NUMROW][MAINW_NUMCOL] = {{"Connection","Create","Select"},
                                                                {"Update", "Add", "Delete"}};

};

#endif // MAINWINDOW_H
