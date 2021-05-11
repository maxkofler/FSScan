#include "fsentry.h"

FSEntry::FSEntry(){

}

FSEntry::FSEntry(std::string name, std::string path){
    this->_name = name;
    this->_path = path;
}

size_t FSEntry::size(){
    return this->_name.size() + this->_path.size();
}

bool FSEntry::operator==(FSEntry e){
    return (this->_path == e._path);
}

bool FSEntry::operator<(FSEntry e){
    return (this->_path < e._path);
}

bool FSEntry::operator>(FSEntry e){
    return (this->_path > e._path);
}
