/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename,
		std::string &contents) {
	fstream stream;
	stream.open(filename.c_str(), ios::in);
	if (!stream.is_open()) {
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	string line;
	while (getline(stream, line)) {
		contents += line;
	}
	stream.close();
	return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,
		std::vector<std::string> &myEntryVector) {
	fstream stream;
	stream.open(filename.c_str(), ios::out);
	if (!stream.is_open()) {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	for (int i = 0; i < myEntryVector.size(); i++) {
		stream << myEntryVector[i] << endl;
	}
	stream.close();
	return SUCCESS;
}

