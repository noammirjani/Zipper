#include <iostream>
#include "archiver/Archiver.h"

int main(int argc, char **argv) {

	try {
		Archiver().execute(argc, argv);
	} catch (const std::exception &e) {
		std::cerr << "Error parsing options: " << e.what() << std::endl;
		return 1;
	}
}