#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QStandardItem"
#include <QByteArray>
#include <QCheckBox>
#include <QDebug>
#include <QDockWidget>
#include <QPushButton>
#include <QTcpSocket>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_client(this)
{

  setMinimumSize(1500, 1000);

  ui->setupUi(this);
  m_buffer.m_treeWidget = ui->treeWidget_link;
  startTcp();
}

MainWindow::~MainWindow() { delete ui; }

bool MainWindow::startTcp()
{
  if (m_client->Start("192.168.50.246", 56789))
  {
    log("连接服务器成功");
  }
  else
  {
  }
  return 0;
}

void MainWindow::log(QString text)
{
  QDateTime time;
  ui->listWidget_log->addItem(
      time.currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") + ": " + text);
}

EnHandleResult MainWindow::OnReceive(ITcpClient *pSender, CONNID dwConnID,
                                     const BYTE *pData, int iLength)
{

  // m_buffer.update((const char *)pData, iLength);
  return HR_OK;
};
