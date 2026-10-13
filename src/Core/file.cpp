#include "file.h"

using namespace std;

namespace core{

file::file(const char* path, FileMode mode){ open(path, mode); }

void file::close(){
    m_file.close();
}

//void* peut etre pour le futur, il faudra static cast
size_t file::read(char* buffer, size_t size){
    m_file.read(buffer,size);
    return m_file.gcount();
    
}

size_t file::write(char* buffer, size_t size){
    m_file.write(buffer, size);
    return m_file.good() ? size : 0;
}

constexpr FileMode operator|(FileMode a, FileMode b){
    return static_cast<FileMode>(static_cast<unsigned>(a) | static_cast<unsigned>(b));
}

constexpr bool hasFlag(FileMode value, FileMode flag){
    return static_cast<unsigned>(value) & static_cast<unsigned>(flag) != 0;
}

bool file::isOpen(){
    return m_file.is_open();
}

bool file::open(const char* path, FileMode mode){
    ios_base::openmode flags;
    switch (mode)
    {
        case FileMode::READ:
            flags |= ios_base::in;
            break;
        case FileMode::WRITE:
            flags |= ios_base::out;
            break;
        case FileMode::BINARY:
            flags |= ios_base::binary;
            break;
        case FileMode::APPEND:
            flags |= ios_base::app;
            break;
        case FileMode::AT_END:
            flags |= ios_base::ate;
            break;
        case FileMode::TRUCATE:
            flags |= ios_base::trunc;
            break;
        default:
            break;
    }

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