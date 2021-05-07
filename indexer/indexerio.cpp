#include "indexer.h"

size_t Indexer::getPaths(std::ostream &stream){
    FUN();
    for (size_t i = 0; i < this->_paths.size(); i++){
        stream << this->_names.at(i) << "/" << this->_paths.at(i) << std::endl;
    }
    return this->_paths.size();
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
            this->_names.push_back(curName);
            this->_paths.push_back(curPath);
        }
    }

    LOGD("Loaded " + std::to_string(this->_names.size()) + " indexes");
    return this->_names.size();
}

void Indexer::clear(){
    FUN();
    this->_names.clear();
    this->_paths.clear();
}
