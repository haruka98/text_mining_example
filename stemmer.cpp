#include "stemmer.hpp"

std::vector<std::string> stem(std::vector<std::pair<std::string, std::string>> dict, std::vector<std::string> wordlist) {
	for(int i = 0; i < wordlist.size(); i++) { /* loop over all words from the document */
		if(wordlist[i] == "") { /* check for empty words and remove them */
			wordlist.erase(wordlist.begin() + i);
			i--; /* decrease the index to not skip a word */
		} else {
			for(int j = 0; j < wordlist[i].size(); j++) { /* loop over all characters in a single word */
				if(wordlist[i][j] >= 'A' && wordlist[i][j] <= 'Z') { /* find uppercase characters */
					wordlist[i][j] -= ('Z' - 'z'); /* make uppercase characters lowercase */
				}
			}
			for(int j = 0; j < dict.size(); j++) { /* loop over dictionary to find stem */
				if(dict[j].first == wordlist[i]) { /* find the word in the dictionary */
					wordlist[i] = dict[j].second; /* replace the word by its stem */
					break; /* enhance performance by skipping the rest of the dictionary */
				}
			}
		}
	}
	return wordlist; /* return the vector with the stemmed words */
}
