#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void setLogFile(const std::string& filename) {
        if (m_file.is_open()) m_file.close();
        m_file.open(filename, std::ios::app);
    }

    void setConsoleOutput(bool enabled) { m_showConsole = enabled; }

    void info(const std::string& msg) {
        std::string entry = "[" + timestamp() + "] " + msg;
        if (m_showConsole) std::cout << entry << std::endl;
        if (m_file.is_open()) m_file << entry << std::endl;
    }

    ~Logger() { if (m_file.is_open()) m_file.close(); }

private:
    Logger() : m_showConsole(true) {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    bool m_showConsole;
    std::ofstream m_file;

    std::string timestamp() {
        std::time_t now = std::time(nullptr);
        char buf[20];
        std::strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", std::localtime(&now));
        return buf;
    }
};

#endif
