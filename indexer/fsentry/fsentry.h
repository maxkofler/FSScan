#ifndef FSENTRY_H
#define FSENTRY_H

#include <string>

class FSEntry
{
public:
    FSEntry();
    FSEntry(std::string name, std::string path);

    size_t                      size();

    std::string                 getName(){return this->_name;}
    std::string                 getPath(){return this->_path;}

    std::string                 toStoreString(){return this->_name + "/" + this->_path;}

    bool operator               ==(FSEntry);
    bool operator               >(FSEntry);
    bool operator               <(FSEntry);

private:
    std::string                 _name;
    std::string                 _path;
};

#endif // FSENTRY_H
