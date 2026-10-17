#include "file.h"

using namespace std;

namespace core{

file::file(const char* path, FileMode mode){ open(path, mode); }

//void* peut etre pour le futur, il faudra static cast
size_t file::read(char* buffer, size_t size){
    m_file.read(buffer,size);
    return m_file.gcount();
    
}

size_t file::write(const char* buffer, size_t size){
    m_file.write(buffer, size);
    return m_file.good() ? size : 0;
}

bool file::isOpen(){
    return m_file.is_open();
}

bool file::open(const char* path, FileMode mode){
    ios_base::openmode flags;
    if(hasFlag(FileMode::READ,mode)) flags |= ios_base::in;
    else if(hasFlag(FileMode::WRITE,mode)) flags |= ios_base::out;
    else if(hasFlag(FileMode::BINARY,mode)) flags |= ios_base::binary;
    else if(hasFlag(FileMode::APPEND,mode)) flags |= ios_base::app;
    else if(hasFlag(FileMode::AT_END,mode)) flags |= ios_base::ate;
    else if(hasFlag(FileMode::TRUCATE,mode)) flags |= ios_base::trunc;
    
    m_file.open(path, flags);

    return m_file.is_open();
}

void file::close(){
    if(m_file.is_open()) m_file.close();
}

vector<char> file::readAll(){

    //Get length
    m_file.seekg(0, m_file.end);
    int length = m_file.tellg();
    m_file.seekg(0, m_file.beg);

    vector<char> data(length);
    m_file.read(data.data(),length);

    return data;
}

}