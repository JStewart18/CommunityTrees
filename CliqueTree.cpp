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

struct CliqueTree {
	std::ifstream inFile;
	DLinkedList nodeList;
	DLinkedList leafList;
	int pseudodepth;
	pt::ptree* topRoot;
	pt::ptree* current;

	CliqueTree::CliqueTree(std::string fileDirectory) { //needs depth set
		buildLists(fileDirectory);
		pt::ptree topNode = nodeList.*top;
		topRoot = topNode.data;
		current = topRoot;
		leafList.current = leafList.top;

		//std::string path_of<>::
		//wefdfas
			pt::ptree propTree;

		auto& list = propTree.add_child(path, ptree{});	///change to properly use parser

		pt::xml_parser::write_xml(std::cout, propTree);
		//fgrag

		/*while (pathList.current != pathList.end) {
			
			buildTree(topRoot, leafList.current, nodeList);
		}*/
	}

	// returns the length of the path to the node specified
	int level(std::string path) { //inelegant, but should function until the key field is more clear
		int level = 0;
		std::size_t found;
		while (found != std::string::npos) {
			found = path.find(".");
			level++;
		}
		return level;
	}
	pt::ptree parentOf(pt::ptree node) {
		return nodeAt(node.key.substr(0, node.key.length - 1)); // to path until
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
		while (inFile >> temp.data) {
									  //temp.data = x.substr(0, x.find_first_of(";"));
			nodeList.add(temp.data);
			if (leafList.contains(temp.data)) { //check if needs to be added to leaflist
				leafList.add(temp.data); // same input data type oddness as above
			}
		}
	}
};