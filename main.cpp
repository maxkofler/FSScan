
#include "log/log.h"
#include "indexer/indexer.h"

#include <fstream>
#include <iostream>

Log* hlog;

int main(int argc, char** argv)
{
    hlog = new Log(Log::F);
    FUN();

    std::string path = "/home";
    std::string indexFile = "out.txt";
    std::string keyword = "home";

    if (argc == 2){
        indexFile = std::string(argv[1]);
    }
    else if (argc == 3){
        path = std::string(argv[1]);
        keyword = std::string(argv[2]);
    }

    Indexer indexer;

    LOGI("Loading from file...");

    {
        std::ifstream inFile;
        inFile.open(indexFile);
        if (inFile.is_open())
            indexer.loadPaths(inFile, true);
        inFile.close();
    }

    LOGI("Indexing recursively from \"" + path + "\"...");

    indexer.indexDirRecursive(path, true);

    LOGI("Done");

    LOGI("RAM containing " + std::to_string(indexer.getByteSize()) + " bytes of paths");

    LOGI("Saving to file \"" + indexFile + "\"...");

    std::ofstream outFile;
    outFile.open(indexFile);

    LOGI("Written " + std::to_string(indexer.getPaths(outFile)) + " files and directories!");

    auto results = indexer.find(keyword);
    std::cout << "Found paths:" << std::endl;
    if (results.size() > 0){
        for (auto& i : results){
            std::cout << i << std::endl;
        }
    }else{
        std::cout << "none" << std::endl;
    }

    outFile.close();

    return 0;
}
