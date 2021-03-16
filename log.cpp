//
// Created by ilya on 15.03.21.
//

#include "log.h"
#include <fstream>

log log::create(const std::string& filename, const std::string& prefix){
    std::ostream* os = &std::cout;
    bool is_file = false;
    if (!filename.empty()){
        os = new std::ofstream(filename, std::ios_base::app);
        is_file = true;
    }

    return log(is_file, prefix, *os);
}

log& log::operator() (LogLevel log_level){
    this->log_level_ = log_level;
    return *this;
}

log::~log(){
    if (is_file_){
        delete &stream_;
    }
}

log::log(bool is_file, std::string prefix, std::ostream& stream)
:is_file_(is_file),prefix_(std::move(prefix)),stream_(stream)
{
    log_level_ = INFO;
}




log getLogger(const std::string& filename, const std::string& prefix){
    return log::create(filename, prefix);
}
