#pragma once
#include <string>
#include "DLinkedList.cpp"
class DLinkedList {
public:
	DLLNode* current;
	void insert(DLLNode curr, std::string s);
	void add(std::string id); 
	//void remove();
	bool empty(); 
//private:
	DLLNode* top;	//Should always point to the first node of the list
	DLLNode* end;	//Should always point to the last node of the list
};
class DLLNode {
public:
	std::string data;
	DLLNode* next;
	DLLNode* prev;
}; 
class DLLNode {
public:
	std::string data;
	DLLNode* next;
	DLLNode* prev;
};