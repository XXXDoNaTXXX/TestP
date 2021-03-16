//
// Created by ilya on 16.03.21.
//

#ifndef TESTP_WRITER_H
#define TESTP_WRITER_H

#include <iostream>

class Writer{

public:

    static Writer create(std::ostream& stream){
        return Writer(stream);
    }

    template<typename T>
    Writer &operator<<( T s) {
        stream_ << s<<" ";
        return *this;
    }

    ~Writer(){
        stream_<<"\n";
    }

private:
    explicit Writer(std::ostream& stream):stream_(stream){}

private:
    std::ostream& stream_;
};

#endif //TESTP_WRITER_H
