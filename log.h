//
// Created by ilya on 15.03.21.
//

#ifndef TESTP_LOG_H
#define TESTP_LOG_H

#include "Writer.h"
#include <thread>
#include <ctime>


enum LogLevel{INFO, DEBUG, WARNING, ERROR};
const std::string log_level_string[4]{"INFO","DEBUG","WARNING", "ERROR"};

class log {

public:

    static log create(const std::string& filename, const std::string& prefix);

public:

    log& operator() (LogLevel log_level);


    template<typename T>
    Writer operator<<( T s){

        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);


        stream_ << now->tm_mday/10<<now->tm_mday%10 <<"."
        << (now->tm_mon + 1)/10<<(now->tm_mon + 1)%10<<"."
        <<(now->tm_year + 1900) <<" "
        <<now->tm_hour/10<<now->tm_hour%10<<":"
        <<now->tm_min/10<<now->tm_min%10<<":"
        <<now->tm_sec/10<<now->tm_sec%10<<"; "
        <<log_level_string[this->log_level_]<<"; "
        <<this->prefix_<<"("<< std::this_thread::get_id()<<"): "
        <<s<<" ";
        this->log_level_ = INFO;
        return Writer::create(this->stream_);
    }

    ~log();

private:
    explicit log(bool is_file, std::string, std::ostream&);

private:
    bool is_file_;
    std::string prefix_;
    std::ostream& stream_;
    LogLevel log_level_;
};

log getLogger(const std::string& filename ="", const std::string& prefix="");

#endif //TESTP_LOG_H
