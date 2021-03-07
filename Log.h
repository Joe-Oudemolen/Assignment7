#pragma once
#include <string>
using namespace std;

#ifndef LOG_H_
#define LOG_H_


inline string getCurrentDateTime(string s) {
    time_t now = time(0);
    struct tm  tstruct;
    char  buf[100];
    tstruct = *localtime(&now);
    if (s == "now")
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    else if (s == "date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return string(buf);
};

inline void Logger(string logMsg) {

    string filePath = "output" + getCurrentDateTime("date") + ".txt";
    string now = getCurrentDateTime("now");
    ofstream ofs(filePath.c_str(), ios_base::out | ios_base::app);
    ofs << now << '\t' << logMsg << '\n';
    ofs.close();
}

#endif