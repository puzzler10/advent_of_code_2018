// 01_aoc2018.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <set>


int main()
{
	// Part 1 
	/*
	auto ifs = std::ifstream("input.txt");

	if (!ifs) {
		std::cout << "File couldn't be opened for some reason";
		exit(1);
	}

	int total = 0; 
	int tmp = 0; 
	while (ifs >> tmp)
		total += tmp; 

	std::cout << total; 
	*/

	//Part 2 

	// read in file and turn stream into vector 
	auto ifs = std::ifstream("input.txt");
	if (!ifs) {
		std::cout << "file ain't working dawg";
		exit(1);
	}

	std::vector<int> input_vec; 
	std::copy(
		std::istream_iterator<int>(ifs),
		std::istream_iterator<int>(), 
		std::back_inserter(input_vec)
	);

	// logic stuff 
	std::set<int> sums;
	sums.insert(0); 
	int tmp = 0, total = 0;
	bool flag = false; 
	int n_nums = 1, counter = 0; 

	while (not flag) {
		for (auto i = 0; i < input_vec.size(); ++i) {
			total += input_vec[i];
			sums.insert(total);
			n_nums += 1;
			if (sums.size() != n_nums) {
				std::cout << "Repeat is " << total << std::endl;
				flag = true; 
				break; 
			}
		}
		counter += 1;
		if (counter % 100 == 0) std::cout << "Counter :" << counter << std::endl; 
		if (counter >= 500) flag = true;
	}
	




}


