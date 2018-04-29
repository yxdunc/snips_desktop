#include "RemoteHostCredentials.h"

RemoteHostCredentials::RemoteHostCredentials(QObject *parent)
    : QAbstractListModel(parent)
{
}

int RemoteHostCredentials::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_knownHosts.size();
}

QVariant RemoteHostCredentials::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QVariant result;

    if (role == Qt::DisplayRole)
    {
        Credentials const& item = getItem(index.row());
        result = item.hostname;
    }

    return result;
}

bool RemoteHostCredentials::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        if(role == Qt::EditRole || role == Qt::DisplayRole)
        {
            m_knownHosts[index.row()].hostname = value.toString();
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
    }
    return false;
}

Qt::ItemFlags RemoteHostCredentials::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void RemoteHostCredentials::appendRow(QString hostname, QString port)
{
    int const size = m_knownHosts.size();
    Credentials newRow;

    newRow.hostname = hostname;
    newRow.port = port;

    beginInsertRows({}, size, size);
    m_knownHosts.append(newRow);
    endInsertRows();
}

bool RemoteHostCredentials::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    m_knownHosts.remove(row, count);
    endRemoveRows();
}

RemoteHostCredentials::Credentials const& RemoteHostCredentials::getItem(int row) const
{
    Q_ASSERT(row > -1 && row < m_knownHosts.size());

    return m_knownHosts[row];
}
