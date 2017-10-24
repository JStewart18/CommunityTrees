#pragma once
#include "CliqueTree.cpp"

struct CliqueTree {
	std::ifstream inFile;
	DLinkedList nodeList;
	DLinkedList leafList;
	int pseudodepth;
	pt::ptree* topRoot;
	pt::ptree* current;

	CliqueTree::CliqueTree(std::string fileDirectory);
	int level(std::string path);
	pt::ptree parentOf(pt::ptree node);
private:
	int depth;
	void buildLists(std::string fileDirectory);
};