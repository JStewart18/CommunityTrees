
#include <boost/property_tree/ptree.hpp>
namespace pt = boost::property_tree;

class DLinkedList {
public:
	DLLNode* current;	//Points to current location in list

	// Add a node to the list right before the current location in the list
	void insert(DLLNode curr, pt::ptree s) {
		DLLNode n;
		n.data = s;
		if (empty()) {
			top = &n;
		} else {
			//n.next = curr.next;	// Switch which group is commented out to switch 
			//curr.next = &n;		// between inserting before or after the current node
			
			if (top = &curr) {
				top = &n;
			}
			n.prev = curr.prev;
			n.next = &curr;
		}		
	}

	// Add a node to the end of the list containing the input ptree for its data
	void add(pt::ptree id) {

		DLLNode newNode;
		newNode.data = id;
		if (top == NULL) {			//in case the add is the first node of the list --check?
			top = &newNode;
		} else {
			newNode.prev = end;
		}
		end = &newNode;
	}
	/*void remove(DLLNode target) {
		target.prev
	}*/
	// Check if the current list is empty
	bool empty() {
		return top == NULL;
	}	
	bool contains(DLLNode* target) {
		current = top;
		while (current != NULL && current != target) {
			current = (*current).next;
		}
	}

private:
	DLLNode* top;	//Should always point to the first node of the list
	DLLNode* end;	//Should always point to the last node of the list
};
class DLLNode {
public:
	pt::ptree data;
	DLLNode* next;
	DLLNode* prev;
};