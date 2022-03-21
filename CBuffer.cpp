#include "CBuffer.h"
#include <QByteArray>
CBuffer::CBuffer() {}
bool CBuffer::update(const char *buffer, int len)
{
  CHead *h = (CHead *)buffer;
  CData *d = new CData;
  d->port = h->getPort();
  d->ip = h->getIp();

  //查找数组中是否有该数据
  int index = -1;
  for (auto i = m_buffer.begin(); i != m_buffer.end(); i++)
  {
    if ((*i)->port == d->port && (*i)->ip == d->ip)
    {
      index = (*i)->index;
      break;
    }
  }

  //如果有则刷新，如果没有则增加
  if (index >= 0)
  {
    if (h->sr == 0)
    {
      m_buffer[index]->byteArray_r.push_back(
          QByteArray(buffer + sizeof(CHead), h->BufferSize));
    }
    else
    {
      m_buffer[index]->byteArray_s.push_back(
          QByteArray(buffer + sizeof(CHead), h->BufferSize));
    }

    updateItem(index);
  }
  else
  {
    if (h->sr == 0)
    {
      d->byteArray_r.push_back(
          QByteArray(buffer + sizeof(CHead), h->BufferSize));
    }
    else
    {
      QByteArray(buffer + sizeof(CHead), h->BufferSize);

      d->byteArray_s.push_back(
          QByteArray(buffer + sizeof(CHead), h->BufferSize));
    }
    m_buffer.push_back(d);
    m_buffer[m_buffer.size() - 1]->index = addItem(d);
  }

  return true;
}

int CBuffer::findItem(CData *data)
{

  QTreeWidgetItemIterator it(m_treeWidget);
  while (*it)
  {
    if (((*it)->text(3)).toInt() == data->port && ((*it)->text(4)) == data->ip)
    {
      return m_treeWidget->indexOfTopLevelItem(*it);
    }
    it++;
  }

  return -1;
}

int CBuffer::addItem(CData *data)
{
  QTreeWidgetItem *item = new QTreeWidgetItem(m_treeWidget);
  data->index = m_treeWidget->indexOfTopLevelItem(item);
  item->setText(0, QString::number(data->index));
  item->setText(2, QString::number(data->byteArray_s.size()) + "/" +
                       QString::number(data->byteArray_r.size()));
  item->setText(3, QString::number(data->port));
  item->setText(4, data->ip);
  return data->index;
}

void CBuffer::updateItem(int index)
{
  QTreeWidgetItem *it = m_treeWidget->topLevelItem(index);
  if (it)
  {
    CData *data = m_buffer[index];
    it->setText(2, QString::number(data->byteArray_s.size()) + "/" +
                       QString::number(data->byteArray_r.size()));
  }
}
