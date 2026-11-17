#include <iostream>
#include <string>
#include <fstream>

#include "../include/hash.h"
#include "../include/integrity.h"

std::string recordFile(std::string& fileName){
	std::string hashFile = hashCalculator(fileName);
	std::ofstream file("db/database.txt", std::ios::app);
	file << fileName << " | " << hashFile << "\n";
	file.close();

	return "Operation completed.";
}

void showFiles(){
	std::ifstream file("db/database.txt");
	std::string line;
	while(getline(file, line)) {
		std::cout << line << std::endl; 
	}
}

std::string filesCmp(std::string& fileName){
	std::string hashFile = hashCalculator(fileName);
	
	std::string line;
	bool findIt = false;
	std::string lineCmp = fileName + " | " + hashFile;

	std::ifstream file("db/database.txt");

	while(getline(file, line)){
		if(line == lineCmp){
			findIt = true;
			break;
		} else {
			bool findIt = false;
		}	
	}

	if(findIt){
		return "No changes made!";
	} else {
		return "The file has been modified.";
	}
}



