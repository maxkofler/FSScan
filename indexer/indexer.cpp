#include "indexer.h"

Indexer::Indexer(){
}

size_t Indexer::indexDirRecursive(std::string path, bool delete_old_results){
    FUN();
    if (delete_old_results){
        this->_names.clear();
        this->_paths.clear();
        LOGI("Cleared all old results!");
    }
    std::filesystem::path   fPath;
    std::string             sfPath;
    std::string             sfName;

    using namespace std::filesystem;

    recursive_directory_iterator it(path, directory_options::skip_permission_denied);
    recursive_directory_iterator end;

    LOGSP(Log::U);
    size_t curSize = 0;

    while(it != end){
        std::error_code err;
        //recursive_directory_iterator file;
        try {
            if (it->exists() && it->is_regular_file()){
                fPath = std::filesystem::canonical(*it);
                sfPath = fPath.string();
                sfPath.shrink_to_fit();
                sfName = fPath.filename().string();
                sfName.shrink_to_fit();
                if (this->_names.size() < this->_names.max_size()){
                    //LOGI("New file: \"" + sfPath + "\"");
                    curSize++;
                    LOGPP("Scanned " + std::to_string(curSize) + " files...", Log::U);
                    this->_paths.push_back(sfPath);
                    this->_names.push_back(sfName);
                }else{
                    LOGE("Maximum size of vector reached: " + std::to_string(this->_names.size()));
                    break;
                }
            }
        }  catch (filesystem_error& e) {
        } catch(...){
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
    LOGEP(Log::U);
    //this->_paths.shrink_to_fit();
    //this->_names.shrink_to_fit();
    return this->_paths.size();
}

size_t Indexer::getByteSize(){
    FUN();
    size_t n = 0;
    for(auto i : this->_paths){
        n += i.size();
    }
    for(auto i : this->_names){
        n += i.size();
    }
    return n;
}

std::vector<std::string> Indexer::find(std::string name){
    FUN();
    std::vector<std::string> ret;
    for (size_t i = 0; i < this->_names.size(); i++){
        if (this->_names.at(i).find(name) != std::string::npos){
            ret.push_back(this->_paths.at(i));
        }
    }
    return ret;
}
