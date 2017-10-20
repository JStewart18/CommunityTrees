#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "CliqueTree.h"

class Output_MC {
	//Algorithm 6

	std::vector<boost::property_tree::ptree> output_MC(boost::property_tree::ptree x, CliqueTree tree){
		std::vector<boost::property_tree::ptree> C;

		C[x.level] = x.data;		//x.key won't work
		if () {	//if x is an element of t.leaflist
			searchUp(C, x, tree);
		} else {
			searchUp(C, x, tree);
			searchDown(C, x, tree);
		}
		return C;
	}
};
				
void searchUp(std::vector<boost::property_tree::ptree> clique, boost::property_tree::ptree x, CliqueTree overallTree) {//CliqueTree = clique subtree, T = overall root tree

	while (x.data == overallTree.topRoot.data) {
		x = x.forcepath(x.key);
		clique.[level.x] = x.label;
	}
}
boost::property_tree::ptree searchDown(std::vector<boost::property_tree::ptree> clique, boost::property_tree::ptree x, CliqueTree overallTree) {//c=current clique, cliques = subset of tree
	if (x is leaf in T) {
		return clique[i]: 1 <= i <= level(x)//} as an MC
	}
	else {
		for (auto __begin = x.children.begin, __end = x.children.end; __begin != __end; ++__begin) {
			x.children[__begin] = y.label;
			return searchDown(clique, y, overallTree);
		}
	}
}