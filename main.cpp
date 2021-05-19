
#include "log/log.h"
#include "indexer/indexer.h"

#include "ui/mainwindow.h"
#include <QApplication>

#include <fstream>
#include <iostream>

Log* hlog;

Indexer indexer;

bool switchCommand(std::string com);

int main(int argc, char** argvc_str)
{
    hlog = new Log(Log::A, true);
    FUN();

    int ret = 0;

    std::vector<std::string> argv;
    for(int i = 0; i < argc; i++)
        argv.push_back(std::string(argvc_str[i]));

    bool startcli = false;

    if (argc >= 2){
        if(argv[1] == "cli"){
            startcli = true;
        }
    }

    if (startcli){
        LOGU("Entering cli mode...");

        bool run = true;
        std::string curCom;
        while(run){
            std::cout << ">>";
            std::cin >> curCom;
            if (curCom == "exit" || curCom == "q"){
                run = false;
                LOGU("Exiting...");
                continue;
            }
            if (!switchCommand(curCom)){
                LOGUE("Could not find command " + curCom);
            }
            ret = 0;
        }
    }else{
        LOGU("Starting in GUI mode...");

        QApplication a(argc, argvc_str);
        MainWindow w;
        w.show();
        ret = a.exec();
    }


    return ret;
}


bool switchCommand(std::string com){
    FUN();
    using namespace std;
    std::string buf;
    if (com == "scan"){
        //cout << "Enter path to scan: ";
        cin >> buf;
        LOGU("Scanning " + buf + "...");
        size_t i = indexer.indexDirRecursive(buf, false, true);
        {
            string l = "Done scanning " + buf + ": " + std::to_string(i);
            l += " files (" + std::to_string(indexer.getByteSize()) + " bytes) indexed!";
            LOGU(l);
        }
        return true;
    }

    else if (com == "clear"){
        indexer.clear();
        LOGU("Cleared all entries from workspace!");
        return true;
    }

    else if (com == "clean"){
        size_t i = indexer.clean();
        LOGU("Cleaned up " + to_string(i) + " duplicates!");
        return true;
    }

    else if (com == "save"){
        size_t s = 0;
        //cout << "Enter file to save indexes: ";
        cin >> buf;
        ofstream f;
        f.open(buf);
        if (f.is_open()){
            s = indexer.savePaths(f);
        }else
            LOGUE("Can't open file " + buf);
        f.close();
        LOGU(   "Saved " + std::to_string(s) + " indexes (" +
                std::to_string(indexer.getByteSize()) + " bytes) to " + buf + "!");
        return true;
    }

    else if (com == "load"){
        size_t s = 0;
        //cout << "Enter file to load indexes from: ";
        cin >> buf;
        ifstream f;
        f.open(buf);
        if (f.is_open()){
            s = indexer.loadPaths(f, false);
        }else
            LOGUE("Can't open file!");
        f.close();
        LOGU(   "Loaded " + std::to_string(s) + " indexes (" +
                std::to_string(indexer.getByteSize()) + " bytes) from " + buf + "!");
        return true;
    }

    else if (com == "stat"){
        LOGU(   "Workspace holding " + std::to_string(indexer.getSize()) + " indexes (" +
                std::to_string(indexer.getByteSize()) + " bytes)!");
        return true;
    }

    else if (com == "findc"){
        cin >> buf;

        LOGU("Searching for entries containing \"" + buf + "\"...");

        auto res = indexer.findByName(buf);

        //Check for found entries
        if (res.size() <= 0){
            LOGUE("Could not find any entries containing \"" + buf + "\"!");
            return true;
        }

        std::string plt = "";
        for (auto i : res){
            plt += i.getPath() + "\n";
        }

        LOGU("Found entries for \"" + buf + "\":");
        LOGU(plt);

        return true;
    }

    else if (com == "find"){
        cin >> buf;

        LOGU("Searching for \"" + buf + "\"");

        auto res = indexer.findByExactName(buf);

        //Check for found entries
        if (res.size() <= 0){
            LOGUE("Could not find any entries matching \"" + buf + "\"!");
            return true;
        }

        std::string plt = "";
        for (auto i : res){
            plt += i.getPath() + "\n";
        }

        LOGU("Found entries for \"" + buf + "\":");
        LOGU(plt);

        return true;
    }

    return false;
}
