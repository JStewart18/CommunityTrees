#include <set>
#include <vector>
#include <string>
//#include <algorithm> //may need for std::find()
#include <boost/property_tree/ptree.hpp>
//#include "RadixNode.h"
#include "CliqueTree.h"
//#include "Search.h"

// Algorithm 5

namespace pt = boost::property_tree;

std::set<pt::ptree>* computeKCliques(pt::ptree t, int k, std::vector<pt::ptree> nodeList, std::vector<pt::ptree> leafList) {// were all radixNodes?
	std::set<pt::ptree> mC; //was Radixnode
	//set Maximal Cliques starting at depth k to spread from k, clique is sub-tree
	CliqueTree tree;
	//tree.basic_ptree(std::string data.next); //t, nodeList, leafList);
	for (auto begin = mC.begin, end = mC.end; begin != end; ++begin) {//each vertex found in G
		if (tree.pseudodepth = k) { //t = tree from top root node
			std::set<pt::ptree> sk;
			std::set<pt::ptree> s_k;
			for (auto _begin = tree.leafList.begin, _end = tree.leafList.end; _begin != _end; ++_begin) {//Sk<-{f:f that is an element of T(v).leaflist, f.level=k}
				if (_begin.level = k){
					sk.insert(_begin);
				} else {
					s_k.insert(_begin);
				} //^Sk<- each f contained in Tree's leaflist with level k
			}
			for (auto __begin = sk.begin, __end = sk.end; __begin != __end; ++__begin){//_each f in Sk
				std::vector<int> cliqueTemp;
				std::set<std::string> cliquesK; // CLiquetree/(s)?
				cliqueT.basic_ptree(data.next());//(__begin, tree.nodeList, tree.leafList);
				nU <- mU union {cliquesK};
			}
			//S_k <- stuff in tree.leaflist but not in Sk


			//if there exists an element f in s_K with level <k
			for (auto __begin = s_k.begin, __end = s_k.end; __begin != __end; ++__begin) {//S_k.add(tree.leafList\S_k);
				if (__begin.level < k) {
					tree.pseudodepth = __begin.level;
					break;//? make certain no need to continue checks after, wip
				} else {
					tree.pseudodepth = 0;
				}

			}
			
			/*for (auto __begin = tree.leafList.begin, __end = tree.leafList.end; __begin != __end; ++__begin) {
				if (sk.find(__begin) != __begin) {//contained in T(v).leaflist but not sk
					S_k.insert(__begin);
				}
			}*/// moved up into other for loop
		}
	}
	return &mC;
}

		