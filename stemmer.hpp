#ifndef STEMMER_HPP
#define STEMMER_HPP

#include <string>
#include <vector>
#include <utility>

std::vector<std::string> stem(std::vector<std::pair<std::string, std::string>> dict, std::vector<std::string> wordlist);

#endif
