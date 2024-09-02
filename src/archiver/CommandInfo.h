#pragma once
#include <string>
#include <vector>
#include <fmt/format.h>
#include <sys/stat.h>
#include <filesystem>

const int MAX_DECOMPRESS_FOLDERS = 1;

namespace fs = std::filesystem;

class CommandInfo
{
public:
    CommandInfo(const std::string& action, const std::string& type, const std::string &targetPath, const std::vector<std::string>& files);
    std::string action() const;
    std::vector<std::string> files() const;
    std::string type() const;
    std::string targetPath() const; 

private:
    std::string m_action;
    std::string m_type;
    std::string m_targetPath; 
    std::vector<std::string> m_files;

    void validateAction(const std::string &);
    void validateFiles(const std::vector<std::string> &) const;
    void checkFileExist(const std::vector<std::string> & files) const;
    bool isDirectory(const std::string &) const;

};