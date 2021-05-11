#include "indexer.h"

#include <algorithm>
#include <set>

size_t Indexer::savePaths(std::ostream &stream){
    FUN();
    LOGU("Sorting entries...");
    std::sort(this->_entries.begin(), this->_entries.end());
    LOGU("Saving...");
    for (size_t i = 0; i < this->_entries.size(); i++){
        stream << this->_entries.at(i).toStoreString() << std::endl;
    }
    return this->_entries.size();
}

size_t Indexer::loadPaths(std::istream &stream, bool delete_results){
    FUN();
    if (delete_results)
        this->clear();

    std::string     curLine;
    std::string     curName;
    std::string     curPath;
    size_t          pos;

    while(!stream.eof()){
        getline(stream, curLine);

        pos = curLine.find('/');
        if (pos != std::string::npos){
            curName = curLine.substr(0, pos-1);
            curPath = curLine.substr(pos+1, curLine.length()-pos-1);
            curName.shrink_to_fit();
            curPath.shrink_to_fit();
            this->_entries.push_back(FSEntry(curName, curPath));
        }
    }

    LOGD("Loaded " + std::to_string(this->_entries.size()) + " indexes");
    LOGU("Sorting entries...");
    std::sort(this->_entries.begin(), this->_entries.end());
    LOGU("Done!");
    return this->_entries.size();
}

void Indexer::clear(){
    FUN();
    this->_entries.clear();
}

template <typename Type>
void remove_duplicate(std::vector<Type>& vec) {
    FUN();
    LOGU("Sorting...");
    std::sort(vec.begin(), vec.end());
    LOGU("Cleaning...");
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    LOGU("Done!");
}

size_t Indexer::clean(){
    FUN();
    size_t oldSize = this->_entries.size();

    remove_duplicate(this->_entries);

    return oldSize - this->_entries.size();
}
