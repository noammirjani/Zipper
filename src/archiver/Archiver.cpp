#include "Archiver.h"


void Archiver::execute(int argc, char **argv) {

    // TODO: add gui - print nice logo in the command line
	
	//TODO: create cli object and call to read function
	auto temp = Cli(argc, argv).read(); 

	if (temp == std::nullopt)
	{
		return; 
	}

	// TODO: create a command handler and run excexute
}   