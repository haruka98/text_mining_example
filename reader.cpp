#include "reader.hpp"

std::vector<std::string> read_doc(std::string path) {
	std::vector<std::string> ret; /* creating return vector */
	std::ifstream file(path); /* open the file */
	if(!file.is_open()) {
		/* opening the file failed */
		std::cout << "[ERROR] Opening file \"" << path << "\" failed." << std::endl;
		return ret;
	}
	std::string new_line = ""; /* string to read the file into */
	while(std::getline(file, new_line)) { /* reading the file line by line */
		std::string word = ""; /* creating the string for new words */
		for(int i = 0; i < new_line.size(); i++) { /* loop over the entire line of the document */
			if(new_line[i] == L' ') { /* check for space between two words */
				ret.push_back(word); /* add the old word */
				word = ""; /* clean old word */
			} else {
				if(new_line[i] != L'.' && new_line[i] != L',' && new_line[i] != L'\r' && new_line[i] != L'\n') { /* remove ".,\r\n" */
					word += new_line[i]; /* add new character to current word */
				}
			}
		}
		ret.push_back(word); /* add the last word of the line */
	}
	file.close(); /* close the document */
	return ret; /* return the vector containing all words */
}
