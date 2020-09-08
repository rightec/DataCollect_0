#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <mainwindowdef.h>
#include <QDebug>

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


   /** ATTRIBUTES*/
    QFrame *framArray[MAINW_NUMROW][MAINW_NUMCOL];
};

#endif // MAINWINDOW_H
