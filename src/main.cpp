#include <iostream>
#include <string>

#include "../include/hash.h"
#include "../include/integrity.h"


int main() {

	char opt;
	std::string fileName, output;

	while(true) {
		std::cout << std::endl;
		std::cout << "   _____   _       ____ _               _     " << std::endl;
  		std::cout << "  |  ___(_) | ___ / ___| |__   ___  ___| | __ " << std::endl;
		std::cout << "  | |_  | | |/ _ | |   | '_ | / _ |/ __| |/ / " << std::endl;
		std::cout << "  |  _| | | |  __/ |___| | | |  __/ (__|   <  " << std::endl;
		std::cout << "  |_|   |_|_||___||____|_| |_||___||___|_||_| " << std::endl;
                                            
		
		std::cout << std::endl;
		std::cout << "1. Calculate the hash of a file." << std::endl;
		std::cout << "2. Record a new file." << std::endl;
		std::cout << "3. Verify file integrity." << std::endl;
		std::cout << "4. View recorded files." << std::endl;
		std::cout << "5. Exit." << std::endl;

		std::cout << "Option: ";
		std::cin >> opt;

		if(opt == '1') {
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			output = hashCalculator(fileName);
			std::cout << std::endl;
			std::cout << "Hash: " << output << std::endl;

		} else if (opt == '2') {
			std::cout << "Enter file name : ";
			std::cin >> fileName;
			output = recordFile(fileName);
			std::cout << std::endl;
			std::cout << output << std::endl;

		} else if (opt == '3') {
			std::string fileNameCmp;
			std::cout << "Enter file name : ";
			std::cin >> fileName;
			std::cout << std::endl;
			output = filesCmp(fileName);
			std::cout << output << std::endl;

		} else if(opt == '4') {
			std::cout << "Files recorded in the database: " << std::endl;
			showFiles();
			
		} else if(opt == '5'){
			std::cout << "Bye!" << std::endl;
			break;
			
		} else {
			std::cout << "Invalid parameter." << std::endl;
		}
	}
}
