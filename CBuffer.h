#ifndef LOG_H
#define LOG_H
#include "Struct.h"
#include <QObject>
#include <QTreeWidget>
#include <vector>
class CBuffer : public QObject
{

public:
  CBuffer();
  std::vector<CData *> m_buffer;
  QTreeWidget *m_treeWidget = nullptr;
  bool update(const char *buffer, int len);
  int findItem(CData *data);
  int addItem(CData *data);
  void updateItem(int index);

signals:
};

#endif // LOG_H
