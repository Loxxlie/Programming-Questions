#pragma once

#include "stdafx.h"

class Node
{
public:
	Node(int x);
	Node(int list[], int length);
	Node();

	void appendToEnd(Node* node);
	void printList();

	int data;
	Node* next;
};

Node::Node() : data(0), next(nullptr) {};
Node::Node(int x) : data(x), next(nullptr) {};
Node::Node(int list[], int length){
	data = list[0];
	Node* temp = this;
	for (int i = 1; i < length; i++){
		Node* newNode = new Node(list[i]);
		temp->next = newNode;
		temp = temp->next;
	}
}
void Node::appendToEnd(Node* node){
	Node* temp = this;
	while (temp->next != nullptr){
		temp = temp->next;
	}
	temp->next = node;
};
void Node::printList(){
	std::cout << "Printing List: " << std::endl << "  ";
	Node* temp = this;
	while (temp != nullptr){
		std::cout << " " << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << "NULL" << std::endl;
}


void delDuplicates(Node* head){
	Node* cur = head;
	while (cur->next != nullptr){
		if (cur->next->data == head->data){
			Node* temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
		}
		cur = cur->next;
	}
	if (head->next != nullptr)
		delDuplicates(head->next);
}

Node* kthToLast(Node* head, int k){
	assert(head != nullptr && k > 0);
	int length = 1;
	Node* temp = head;
	while (temp->next != nullptr){
		temp = temp->next;
		length++;
	}
	if (k > length){
		std::cout << "The desired " << k << "th from last runs off the front of list of length " << length << "/n";
		return nullptr;
	}
	else{
		length = length - k;
		Node* result = head;
		for (int i = 0; i < length; i++)
			result = result->next;
		return result;
	}
}

void deleteNode(Node* node){
	assert(node != nullptr);
	if (node->next != nullptr){
		node->data = node->next->data;
		Node* temp = node->next;
		node->next = node->next->next;
		delete temp;
	}
	else{
		Node* temp = node;
		node = nullptr;
		delete temp;
	}
}

Node* weirdAdd(Node* a, Node* b){
	a->printList(); b->printList();
	std::cout << "Starting weirdAdd" << std::endl;
	assert(a != nullptr && b != nullptr);
	Node* result = new Node();
	Node* aItr = a; Node* bItr = b; bool carryover = false;
	while (aItr != nullptr && bItr != nullptr){
		std::cout << "     Performing " << aItr->data << " + " << bItr->data << std::endl;
		int tempsum = aItr->data + bItr->data;
		std::cout << "     Result = " << tempsum << std::endl;
		if (carryover) { tempsum++; carryover = false; std::cout << "     Detected carryover, result now " << tempsum << std::endl; }
		assert(tempsum <= 19 && tempsum >= 0);
		if (tempsum >= 10){
			std::cout << "     Result above 10, marking carryover." << std::endl;
			carryover = true;
			Node* newNode = new Node(tempsum - 10);
			std::cout << "     Adding node with data = " << newNode->data << " to final list" << std::endl;
			result->appendToEnd(newNode);
		}
		else{
			Node* newNode = new Node(tempsum);
			std::cout << "     Adding node with data = " << newNode->data << " to final list" << std::endl;
			result->appendToEnd(newNode);
		}
		aItr = aItr->next; bItr = bItr->next;
		std::cout << "    Final List is as follows" << std::endl;
		result->printList();
	}
	if (aItr == nullptr && bItr != nullptr){
		std::cout << "     Reached end of list1, continuing with list2" << std::endl;
		while (bItr != nullptr){
			int tempsum;
			if (carryover) tempsum = bItr->data + 1; else tempsum = bItr->data;
			std::cout << "     Result = " << tempsum << std::endl;
			if (tempsum >= 10){
				std::cout << "     Result above 10, marking carryover." << std::endl;
				carryover = true;
				Node* newNode = new Node(tempsum - 10);
				std::cout << "     Adding node with data = " << newNode->data << " to final list" << std::endl;
				result->appendToEnd(newNode);
			}
			else{
				Node* newNode = new Node(tempsum);
				std::cout << "     Adding node with data = " << newNode->data << " to final list" << std::endl;
				result->appendToEnd(newNode);
			}
			bItr = bItr->next;
			std::cout << "    Final List is as follows" << std::endl;
			result->printList();
		}
	}
	else if (aItr != nullptr && bItr == nullptr){
		std::cout << "     Reached end of list2, continuing with list1" << std::endl;
		while (aItr != nullptr){
			int tempsum;
			if (carryover) tempsum = aItr->data + 1; else tempsum = aItr->data;
			if (tempsum >= 10){
				carryover = true;
				Node* newNode = new Node(tempsum - 10);
				std::cout << "     Adding node with data = " << newNode->data << " to final list" << std::endl;
				result->appendToEnd(newNode);
			}
			else{
				Node* newNode = new Node(tempsum);
				std::cout << "     Adding node with data = " << newNode->data << " to final list" << std::endl;
				result->appendToEnd(newNode);
			}
			aItr = aItr->next;
			std::cout << "    Final List is as follows" << std::endl;
			result->printList();
		}
	}
	Node* temp = result->next;
	delete result;
	return temp;
}