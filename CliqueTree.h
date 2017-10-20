#pragma once
#include "CliqueTree.cpp"

class CliqueTree {
	std::ifstream inFile;
	DLinkedList nodeList;
	DLinkedList leafList;
	int pseudodepth;
	pt::ptree* topRoot;
	pt::ptree* current;

	CliqueTree::CliqueTree(std::string fileDirectory);

private:
	int depth;
	void buildLists(std::string fileDirectory);
};