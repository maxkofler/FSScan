#ifndef INDEXER_H
#define INDEXER_H

class Indexer;

#include "log/log.h"

#include <filesystem>
#include <string>
#include <vector>
#include <ostream>
#include <istream>

class Indexer
{
public:
    Indexer();

    size_t                      indexDirRecursive(std::string path, bool delete_results);

    size_t                      getPaths(std::ostream& stream);
    size_t                      loadPaths(std::istream& stream, bool delete_results);

    size_t                      getByteSize();

    std::vector<std::string>    find(std::string name);

    void                        clean();


private:
    std::vector<std::string>    _paths;
    std::vector<std::string>    _names;
};

#endif // INDEXER_H
