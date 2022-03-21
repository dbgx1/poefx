#include "Struct.h"

unsigned short CHead::getPort() { return htons(sever.sin_port); }
QString CHead::getIp()
{
  QString strIp = inet_ntoa(sever.sin_addr);
  return strIp;
}
