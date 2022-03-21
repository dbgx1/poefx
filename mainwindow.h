#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#undef UNICODE
#include "QTime"
#include "hp/HPSocket.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE

#include "CBuffer.h"
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, CTcpClientListener
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

public:
  CTcpPackClientPtr m_client;
  CBuffer m_buffer;

public:
  EnHandleResult OnReceive(ITcpClient *pSender, CONNID dwConnID,
                           const BYTE *pData, int iLength);

  EnHandleResult OnClose(ITcpClient *pSender, CONNID dwConnID,
                         EnSocketOperation enOperation, int iErrorCode)
  {
    return HR_OK;
  };

  EnHandleResult OnAccept(ITcpClient *pSender, CONNID dwConnID,
                          UINT_PTR soClient)
  {
    log("客户进入");
    return HR_OK;
  }

  bool startTcp();

  //打印日志
  void log(QString text);
  //加入新连接
  void addLink();
};
#endif // MAINWINDOW_H
