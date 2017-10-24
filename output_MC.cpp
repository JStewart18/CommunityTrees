#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "CliqueTree.h"

class Output_MC {
	//Algorithm 6

	std::vector<boost::property_tree::ptree> output_MC(boost::property_tree::ptree x, CliqueTree* tree){
		std::vector<boost::property_tree::ptree> C;

		C[tree->level(x.key)] = x.data;		
		if (tree->leafList.contains(x)) {	//if x is an element of t.leaflist
			searchUp(C, x, tree);
		} else {
			searchUp(C, x, tree);
			searchDown(C, x, tree);
		}
		return C;
	}
};
				
void searchUp(std::vector<boost::property_tree::ptree> clique, boost::property_tree::ptree x, CliqueTree* overallTree) {//CliqueTree = clique subtree, T = overall root tree

	while (x.data != overallTree->topRoot.data) {
		//x = overallTree->parentOf(x);
		clique[overallTree->level(overallTree->parentOf(x).get_child(x.key).first)] = x.data; //check the keys of the fellow children to original x's parent node
	}
}
std::vector<boost::property_tree::ptree> searchDown(std::vector<boost::property_tree::ptree> clique, boost::property_tree::ptree x, CliqueTree* overallTree) {//c=current clique, cliques = subset of tree
	if (overallTree->leafList.contains(x)) {//x is a leaf of t
		return clique;						//} as an MC
	} else {

		for(auto const &y: x.get_child(x.key)) {					// children y of ptree x
			clique[overallTree->level(y.first)] = y.second;			//y.label to store at C[y.level]
			return searchDown(clique, y.second, overallTree);		//need to confirm y.second is correct for the ptree child for both of these <^
		}
	}
}