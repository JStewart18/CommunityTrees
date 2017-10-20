#include <string>
#include <vector>
#include <set>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include "CliqueTree.h"
#include "Search.h"

// Algorithm 7

//#include "CliqueTree.h" -> now ptree data type
namespace pt = boost::property_tree;
std::string FILE = "C://";


std::string computeCliquesCommonVertices () {
	std::set<pt::ptree>* mU = new std::set<pt::ptree>();//radixNode->radixRoot?
	CliqueTree tree = CliqueTree::CliqueTree(FILE);
	//return all MCs of size >=k except C, in T(v1) and T(v2)
	
	for (auto begin = tree.leafList.begin, end = tree.leafList.end; begin != end; ++begin) {// each f that is an element of T(v1).leaflist where f.level >=k
		std::vector<int> C(k);
		C[k] = f.label;
		searchUp(C, f, T(v1));
		if (C != Ci) {
			mCondGToETk(Ci) < -union mCondGToETk(Ci) { C };
		}
	}
	if (T(v2).depth >= k) {
		for () {// each f that is an element of T(v2).leaflist where f.level >=k
			std::vector<int> C(k);
			C[k] = f.label;
			searchUp(C, f, T(v2));
		}
		mCondGToETk(Ci) < -;
			union mCondGToETk(Ci) { C };
	}

	//Output a selected set of MCs of size >=k in T(u) for u that is an element of union N~(vk-1) {N~(vk)}

	for(){// each j that is an element of {k-1, k}
		for () {// each u that is an element of N~(vj)
			for () {// each node that is an element of nodeListu(v) where getLevel(node(v))>=k
				std::vector<int> C(k);
				C[getLevel(node(v))] <- v;
				searchUp(C, node(v), T(u));
				searchDown(C, node(v), T(u));
				mCondGToETk(Ci) <- union mCondGToETk(Ci) { C };
			}
		}
	}
	return mU; 
}