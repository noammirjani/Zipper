#include "CommandHandler.h"

CommandHandler::CommandHandler(const CommandInfo &info)
    : m_info(info), m_archive(archive_write_new())
{

}

CommandHandler::~CommandHandler()
{
    if (m_archive)
    {
        archive_write_free(m_archive);
    }
}

void CommandHandler::execute() const
{
    if (m_info.action() == "compress")
    {
        compress();
    }
    else
    {
    }
}

int CommandHandler::compress() const
{
    if (archive_write_set_format_by_name(m_archive, m_info.type().c_str()) != ARCHIVE_OK)
    {
        throw std::runtime_error("can not set the archive to the wanted format: " + m_info.type());
    }

    // build archive folder name
    std::string suffix = "." + m_info.type();
    std::string archiveName(m_info.targetPath());
    archiveName += (m_info.targetPath().find(suffix) == std::string::npos) ? suffix : "";

    if (archive_write_open_filename(m_archive, archiveName.c_str()) != ARCHIVE_OK)
    {
        throw std::runtime_error("can not open the archive filename");
    }

    for (const auto &file : m_info.files())
    {
        if (std::filesystem::is_directory(std::filesystem::status(file)))
        {
            addDirectoryToArchive(file, std::filesystem::path(file).filename().string());
        }
        else
        {
            addFileToArchive(file, std::filesystem::path(file).filename().string());
        }
    }

    if (archive_write_close(m_archive) != ARCHIVE_OK)
    {
        throw std::runtime_error("can not close the archive writing");
    }

    return ARCHIVE_OK;
}

void CommandHandler::addFileToArchive(
    const std::string &filepath, const std::string &entryPath) const
{
    static constexpr auto filePermissions{0644};

    // set file variables to prepare for reading the file
    std::ifstream inputFile(filepath, std::ios::binary | std::ios::ate);
    std::streamsize size = inputFile.tellg();
    std::vector<char> buffer(size);
    inputFile.seekg(0, std::ios::beg);

    if (inputFile.read(buffer.data(), size))
    {
        struct archive_entry *entry = createEntry(entryPath, AE_IFREG, filePermissions);
        archive_write_data(m_archive, buffer.data(), size);
        archive_entry_free(entry);
    }

    inputFile.close();
}

void CommandHandler::addDirectoryToArchive(
    const std::string &dirname, const std::string &entryPath) const
{
    static constexpr auto directoryPermissions{0755};
    struct archive_entry *currEntry = createEntry(entryPath, AE_IFDIR, directoryPermissions);

    for (const auto &childEntry : std::filesystem::directory_iterator(dirname))
    {
        const auto &path = childEntry.path();
        std::string entryName = entryPath + "/" + path.filename().string();

        if (std::filesystem::is_directory(childEntry.status()))
        {
            addDirectoryToArchive(path.string(), entryName);
        }
        else
        {
            addFileToArchive(path.string(), entryName);
        }
    }

    archive_entry_free(currEntry);
}

struct archive_entry *CommandHandler::createEntry(
    const std::string &entryPath, const unsigned filetype, const int permissions) const
{

    struct archive_entry *entry = archive_entry_new();
    archive_entry_set_pathname(entry, entryPath.c_str());
    archive_entry_set_filetype(entry, filetype);
    archive_entry_set_perm(entry, permissions);

    if (archive_write_header(m_archive, entry) != ARCHIVE_OK)
    {
        throw std::runtime_error("can not write header for " + entryPath);
    }

    return entry;
}