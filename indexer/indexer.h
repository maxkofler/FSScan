#ifndef INDEXER_H
#define INDEXER_H

class Indexer;

#include "log/log.h"
#include "fsentry/fsentry.h"

#include <QObject>
#include <QStatusBar>

#include <filesystem>
#include <string>
#include <vector>
#include <ostream>
#include <istream>

class Indexer : public QObject
{
    Q_OBJECT
public:
    Indexer();

    size_t                      indexDirRecursive(std::string path, bool delete_results, bool printProgress, QStatusBar* bar = nullptr);

    size_t                      savePaths(std::ostream& stream);
    size_t                      loadPaths(std::istream& stream, bool delete_results);

    size_t                      getByteSize();
    size_t                      getSize(){return this->_entries.size();}

    std::vector<FSEntry>        getVector(){return this->_entries;}
    std::vector<FSEntry>        findByName(std::string name);
    std::vector<FSEntry>        findByExactName(std::string name);


    /**
     * @brief   Deletes all entries and indexes in the workspace
     */
    void                        clear();

    /**
     * @brief   Cleans up the workspace e.g. removing duplicates, this can take some time to complete,
     *          but this can significantly speed up the searching when done regularly
     * @return                  Ammount of duplicates removed
     */
    size_t                      clean();

signals:
    void                        onStatusUpdate(QString text);
    void                        onFinishedIndex();

private:
    std::vector<FSEntry>        _entries;
    //std::vector<std::string>    _names;
};

#endif // INDEXER_H
