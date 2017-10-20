//#include "RadixNode.cpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
//#include <boost/property_tree/string_path.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "DLinkedList.h"
namespace pt = boost::property_tree;

class CliqueTree {
	std::ifstream inFile;
	DLinkedList nodeList;
	DLinkedList leafList;
	int pseudodepth;
	pt::ptree* topRoot;
	pt::ptree* current;

	CliqueTree::CliqueTree(std::string fileDirectory) { //needs depth set
		buildLists(fileDirectory);

		topRoot -> nodeList.top.data;
		current = topRoot;
		leafList.current = leafList.top;

		//std::string path_of<>::
		//wefdfas
			pt::ptree propTree;

		auto& list = propTree.add_child(path, ptree{});	///change to INFO parser to use strings

		for (auto data : { 12, 44, 23 })	//replace with actual data to be input to tree
			list.add("value", data)
			.add("<xmlattr>.active", true);

		pt::xml_parser::write_xml(std::cout, propTree);
		//fgrag

		/*while (pathList.current != pathList.end) {
			
			buildTree(topRoot, leafList.current, nodeList);
		}*/
	}

private:
	int depth;
	/*CliqueTree buildTree(pt::ptree* rootNode, DLLNode* leafListNext, DLinkedList nodeList) {
		//establish new node placement in tree
		rootNode pt::&add_child(const std::string* &path, const self_type &value); // requires higher nodes in tree to be listed first
		
		if (nodeList.current.data != leafListNext) {
			root = buildTree(nodeList.begin, leafListNext, nodeList);
		}
	}*/

	// builds the leafList and nodeLists using the input data
	void buildLists(std::string fileDirectory) {
		inFile.open(fileDirectory);
		if (!inFile) {
			std::cerr << "Unable to open file datafile.txt";
			exit(1);   // calls system to stop, cannot continue without properly loaded file
		}
		//std::string x;
		pt::ptree temp;
		pt::ptree tTree;
		while (inFile >> temp.data) { //seems odd, accpets string only when ptreee should be the case
									  //temp.data = x.substr(0, x.find_first_of(";"));
			nodeList.add(temp.data);
			if (temp.data == Leaf) { //check if needs to be added to leaflist
				leafList.add(temp.data); // same input data type oddness as above
			}
		}
	}
};