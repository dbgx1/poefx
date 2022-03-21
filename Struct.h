#ifndef STRUCT_H
#define STRUCT_H
#include <QString>
#include <vector>
#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")

class CHead
{
public:
  //发送或接收0：recv 1:send
  char sr;
  sockaddr_in sever;
  //  buffer长度
  int BufferSize;
public:
  unsigned short getPort();
  QString getIp();
};

class CData
{
public:
  // recv或send
  char rs = 0;
  QString ip;
  uint16_t port = 0;
  std::vector<QByteArray> byteArray_s;
  std::vector<QByteArray> byteArray_r;
  //在控件上的索引
  int index = -1;
};

#endif // STRUCT_H
