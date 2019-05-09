#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <numeric>

int main() {
	
	//read in input 
	auto ifs = std::ifstream("input.txt");
	if (!ifs) {
		std::cout << "File could not be read " << std::endl;
		exit(1);
	}
	
	//input to vector 
	std::vector<std::string> ifs_vec;
	std::string str; 
	while (std::getline(ifs, str)) {
		ifs_vec.push_back(str);
	}

	//// Part 1 
	/*
	std::string line = "";
	std::set<char> characters;
	std::vector<bool> has2, has3;
	has2.resize(ifs_vec.size(), false);
	has3.resize(ifs_vec.size(), false);
	
	int idx = 0; 
	for (auto line : ifs_vec) {
		// Get number of times each letter appears 
		std::map<char, size_t> letter_map;
		for (size_t i = 0; i < line.size(); ++i) {
			letter_map[line[i]] += 1;
			characters.insert(line[i]);
		}
		// See if each letter appears twice or 3 times  
		for (auto c : characters) {
			if (letter_map[c] == 2)   has2[idx] = true;
			if (letter_map[c] == 3)   has3[idx] = true; 
		}
	//	std::cout << line << " has2: " << has2[idx] << " has3: " << has3[idx] << "\n";
		idx += 1;
	}

	// Calculate checksum 
	float has2sum = std::accumulate(has2.begin(), has2.end(), 0.);
	float has3sum = std::accumulate(has3.begin(), has3.end(), 0.);

	std::cout << has2sum * has3sum;
	return 0;
	*/

	///// Part 2 
	ifs_vec;
	int mismatches = 0; 
	std::string sames = ""; 
	for (auto str1 : ifs_vec) {
		for (auto str2 : ifs_vec) {
			for (auto i = 0; i < str2.size(); ++i) {
				if (str1[i] != str2[i]) {
					mismatches += 1;
				}
				else {
					sames += str1[i];
				}

			}
			if (mismatches == 1) {
				std::cout << str1 << "\n" << str2 << "\n"; 
				std::cout << sames;
				goto endloop; 
			}
			mismatches = 0;
			sames = "";
		}
	}
endloop:;


}