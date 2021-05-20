#include "indexer.h"

#include <algorithm>

Indexer::Indexer(){
}

size_t Indexer::indexDirRecursive(std::string path, bool delete_old_results, bool printProgress, QStatusBar* statBar){
    FUN();
    if (delete_old_results){
        this->_entries.clear();
        LOGI("Cleared all old results!");
    }
    if (statBar != nullptr){
        LOGD("Outputting info to statusbar");
    }

    std::filesystem::path   fPath;
    std::string             sfPath;
    std::string             sfName;

    using namespace std::filesystem;

    recursive_directory_iterator it(path, directory_options::skip_permission_denied);
    recursive_directory_iterator end;

    if (printProgress)
        LOGSP(Log::U);
    size_t curSize = 0;

    while(it != end){
        std::error_code err;
        //recursive_directory_iterator file;
        try {
            if (it->exists()){
                fPath = std::filesystem::canonical(*it);
                sfPath = fPath.string();
                sfPath.shrink_to_fit();
                sfName = fPath.filename().string();
                sfName.shrink_to_fit();
                if (this->_entries.size() < this->_entries.max_size()){
                    //LOGI("New file: \"" + sfPath + "\"");
                    curSize++;
                    if (printProgress)
                        LOGPP("Scanned " + std::to_string(curSize) + " files...", Log::U);
                    emit onStatusUpdate(QString().fromStdString("Indexing \"" + sfPath + "\"..."));
                    this->_entries.push_back(FSEntry(sfName, sfPath));
                }else{
                    LOGE("Maximum size of vector reached: " + std::to_string(this->_entries.size()));
                    break;
                }
            }
        }  catch (filesystem_error& e) {
        } catch(...){
            if (printProgress)
                LOGEP(Log::U);
            LOGE("Fatal error while scanning!");
            break;
        }

        it.increment(err);
        if (err){
            //LOGEP(Log::U);
            //LOGE("Error while incrementing: " + err.message());
        }

    }
    if (printProgress)
        LOGEP(Log::U);
    emit onStatusUpdate("Sorting entries...");
    LOGU("Sorting entries...");
    std::sort(this->_entries.begin(), this->_entries.end());
    emit onStatusUpdate(QString().fromStdString("Indexed " + std::to_string(this->_entries.size()) + " files!"));
    LOGU("Done!");
    emit onFinishedIndex();
    return this->_entries.size();
}

size_t Indexer::getByteSize(){
    FUN();
    size_t n = 0;
    for(auto i : this->_entries){
        n += i.size();
    }
    return n;
}

std::vector<FSEntry> Indexer::findByName(std::string name){
    FUN();
    std::vector<FSEntry> ret;

    std::string curName;

    for (size_t i = 0; i < this->_entries.size(); i++){
        curName = this->_entries.at(i).getName();
        if (curName.find(name) != std::string::npos){
            ret.push_back(this->_entries.at(i));
        }
    }
    return ret;
}

std::vector<FSEntry> Indexer::findByExactName(std::string name){
    FUN();
    std::vector<FSEntry> ret;

    std::string curName;

    for (size_t i = 0; i < this->_entries.size(); i++){
        curName = this->_entries.at(i).getName();
        if (curName == name){
            ret.push_back(this->_entries.at(i));
        }
    }
    return ret;
}
