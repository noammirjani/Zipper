#include "CommandInfo.h"

// TODO: add fix format file
CommandInfo::CommandInfo(const std::string &action, const std::string &type, const std::string &targetPath, const std::vector<std::string> &files)
    : m_type(type), m_files(files), m_targetPath(targetPath)
{
    validateAction(action);
   // validateFiles(files); 
   // validatePath(targetPath);
}

void CommandInfo::validateAction(const std::string &action)
{
    if (action == "compress" or action == "C")
    {
        m_action = "compress";
    }
    else if (action == "decompress" or action == "D")
    {
        m_action = "decompress";
    }
    else
    {
        throw std::invalid_argument(fmt::format("The option { } does not exists!\n", action));
    }
}

void CommandInfo::validateFiles(const std::vector<std::string> &files) const
{

    if (files.empty())
    {

        throw std::invalid_argument("Argument is missing, the wanted files/directories to process should be specify implicitly");
    }

    if (m_action == "decompress")
    {
        if (files.size() > MAX_DECOMPRESS_FOLDERS)
        {
            throw std::invalid_argument("Decompress action can get only one folder at a time");
        }

        if (!isDirectory(files[0]))
        {
            throw std::invalid_argument("Decompress action can get only a path for a folder!");
        }
    }
    else
    {
        checkFileExist(files);
    }
}

void CommandInfo::checkFileExist(const std::vector<std::string> &files) const
{

    for (const auto &filename : files)
    {
        if (!fs::exists(fs::status(filename)))
        {
            throw std::runtime_error(fmt::format("File {} does not exist!", filename));
        }
    }
}

bool CommandInfo::isDirectory(const std::string &filePath) const
{
    auto fileStat = fs::status(filePath);
    return fs::exists(fileStat) && fs::is_directory(fileStat);
}

std::string CommandInfo::action() const {
    return m_action;
}

std::vector<std::string> CommandInfo::files() const {
    return m_files;
}

std::string CommandInfo::type() const {
    return m_type;
}

std::string CommandInfo::targetPath() const{
    return m_targetPath;
}