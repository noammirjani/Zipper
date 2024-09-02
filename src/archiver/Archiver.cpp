#include "Archiver.h"


void Archiver::execute(int argc, char **argv) {

    // TODO: add gui - print nice logo in the command line
	auto info = Cli(argc, argv).read(); 

	if (info == std::nullopt)
	{
		return; 
	}
	CommandHandler(info.value()).execute(); 
}   