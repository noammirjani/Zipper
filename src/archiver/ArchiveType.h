#pragma once
#include <vector>
#include <string>

class ArchiveType
{
public:
    ArchiveType();
    ~ArchiveType() = default; 

    void compress(const std::vector<std::string>& files) const {} 
    void decompress(const std::string& file) const {}

private:

};
