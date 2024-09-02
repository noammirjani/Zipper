#include "Cli.h"

Cli::Cli(int argc, char ** argv) 
: m_argc(argc), m_argv(argv), m_cliOptions(create()) 
{}


cxxopts::Options Cli::create(){

	cxxopts::Options options("Archiver", "Archiver - User friendly app for compressing and decompressing archives");

    // define the flags - <project name> <option> <type method> <filenames>
	options.add_options()
    ("a,action", "Wanted action - compress or C/ decompress or D", cxxopts::value<std::string>()->default_value("compress"))
    ("t,type", "Wanted type method - (zip), (7zip)", cxxopts::value<std::string>()->default_value("zip"))
    ("f,filenames", "The filenames (or directories) to process", cxxopts::value<std::vector<std::string>>())
    ("h,help", "Print usage")
    ;

	options.positional_help("<project name> <action> <type> <filenames>");
	options.show_positional_help();

	return options;
}


void Cli::log(const cxxopts::ParseResult& result) const{
    std::cout << "action: " << result["action"].as<std::string>() << "\ntype: " << result["type"].as<std::string>() << "\nfiles:";

	auto vec = result["filenames"].as<std::vector<std::string>>();
	for (const auto &x : vec) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}


std::optional<CommandInfo> Cli::read(){
	
    m_cliOptions.parse_positional({ "action", "type", "filenames"});
    auto result{m_cliOptions.parse(m_argc, m_argv)};

    if (result.count("help")) {
		std::cout << m_cliOptions.help() << std::endl;
        return std::nullopt;
	}
    else {
        log(result); 

        return CommandInfo(
            result["action"].as<std::string>(), 
            result["type"].as<std::string>(),
            result["filenames"].as<std::vector<std::string>>() 
        );
    }
}