#include <iostream>
#include <string>
#include <fstream>
#include <openssl/evp.h>
#include <sstream>
#include <iomanip>

#include "../include/hash.h"


// We use const to prevent the file from being modified, and we pass it by reference using string&.
std::string hashCalculator(const std::string& fileName){
	std::ifstream file(fileName, std::ios::binary); //Binary mode for reading bytes exactly as they are on the disk

	if(!file){
		return "[ERROR] File not accessible."; 
	}

	// We create a structure that holds the internal state of the calculation. 
	EVP_MD_CTX* ctx = EVP_MD_CTX_new();
	
	if (!ctx) {
		return "[ERROR] Allocation error.";
	}

	// We tell it which alghoritm to use. (SHA256) 
	// If It works,the function return 1, otherwise we free the allocated memorty that we made.
	if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1){
		EVP_MD_CTX_free(ctx);
		return "[ERROR] Error in the use of SHA-256.";
	}

	char buffer[4096]; // We create a 4Kb buffer that allow us to read the file in blocks.
	
	// file.read(buffer, sizeof(buffer)) == Reads until 4096 bytes.
	// file.gcount() actually returns the bytes read.
	// In the end, it passes the bytes read to the SHA-256 algorithm until the end of the file. Otherwise we free the allocated memory. 
	while(file.read(buffer, sizeof(buffer)) || file.gcount()){
		if(EVP_DigestUpdate(ctx, buffer, file.gcount()) != 1){
			EVP_MD_CTX_free(ctx);
			return "[ERROR] Error while updating the SHA-256.";
		}
	}

	unsigned char hash[EVP_MAX_MD_SIZE]; 
	//  EVP_MAX_MD_SIZE = 32 byte, while hash is the array where the result will be saved.
	unsigned int hashLength;
	
	if(EVP_DigestFinal_ex(ctx, hash, &hashLength) != 1){
		EVP_MD_CTX_free(ctx);
		return "[ERROR] Error in completing the calculation.";
	}

	EVP_MD_CTX_free(ctx); // We can free the allocated memory.
	

	// We convert it in hexadecimal using <sstream>.
	std::stringstream ss;

	for(unsigned int i = 0; i < hashLength; i++){
		// setw = set the minimum length of 2 chars.
		// setfill = fill the empty spaces with zeros.
		// It converts the byte to a int to print it.
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	}

	return ss.str();

}
