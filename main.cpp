#include <iostream>
#include <vector>
#include <utility>

#include "reader.hpp"
#include "stemmer.hpp"

std::vector<std::string> remove_common_words(std::vector<std::string> common_words, std::vector<std::string> wordlist) {
	for(int i = 0; i < wordlist.size(); i++) { /* loop over all words */
		for(int j = 0; j < common_words.size(); j++) { /* loop over all common words */
			if(wordlist[i] == common_words[j]) { /* check if the current word is a common word */
				wordlist.erase(wordlist.begin() + i); /* remove the common word from the list */
				i--; /* decrease the index to not skip a word */
				break; /* stop searching the rest of the common words to enhance performance*/
			}
		}
	}
	return wordlist; /* return the list without the common words */
}

int main(int argc, char* argv[]) {
	std::vector<std::pair<std::string, std::string>> stem_dict = {
		{"computing", "comput"}, {"contains", "contain"}, {"something", "some"}, {"testing", "test"}, {"tests", "test"}, {"words", "word"} /* ... fill with all the possible words, first one is any word, second one is the stem */
	};
	std::vector<std::string> common_words = {
		"a", "as", "can", "few", "he", "i", "is", "it", "only", "she", "the", "they", "this", "you" /* ... fill with all words that are contained in most documents */
	};
	int matrix[9][5] = {0}; /* create the initial empty matrix */
	std::vector<std::string> keywords = {"comput", "contain", "document", "new", "see", "some", "test", "text", "word"}; /* list of keywords to decode the lines of the matrix */
	std::vector<std::string> file_list = {"example_docs/ex1.txt", "example_docs/ex2.txt", "example_docs/ex3.txt", "example_docs/ex4.txt", "example_docs/ex5.txt"}; /* list of the file names of the documents */
	for(int i = 0; i < file_list.size(); i++) { /* fill the matrix with the documents */
		std::vector<std::string> temp_document = stem(stem_dict, remove_common_words(common_words, read_doc(file_list[i]))); /* read the document, remove common words and apply stemming */
		for(int j = 0; j < 9; j++) { /* loop over all lines of the matrix */
			for(int k = 0; k < temp_document.size(); k++) { /* loop over the stemmed document */
				if(keywords[j] == temp_document[k]) { /* check if the word exists in the document */
					matrix[j][i]++; /* increase the word counter */
				}
			}
		}
	}
	/* output the resulting matrix */
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 5; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << keywords[i] << std::endl;
	}
	return 0;
}
