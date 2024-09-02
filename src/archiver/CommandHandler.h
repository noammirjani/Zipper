#pragma once
#include "CommandInfo.h"
#include "ArchiveType.h"
#include <memory>
#include <archive.h>
#include <archive_entry.h>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <functional>

class CommandHandler
{
public:
    CommandHandler(const CommandInfo&); 
    ~CommandHandler(); 

    void execute() const;
    int compress() const;

private:
    struct archive * m_archive;
    const CommandInfo m_info; 

    //static std::unordered_map<std::string, std::function<int (struct archive*)>> s_archive_write_set_format;

    void addFileToArchive( const std::string &filename, const std::string &entryPath) const;

    archive_entry *createEntry( const std::string &entryPath, const unsigned filetype, const int permissions) const;

    int archive_write_set_format() const;

    void addDirectoryToArchive( const std::string &dirname, const std::string &entryPath) const;
};

