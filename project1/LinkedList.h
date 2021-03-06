#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Ant.h"
#include <iostream>

class Node
{
	friend class LinkedList; // Allow LinkedList to access private vars

	private:
		Ant *ant;
		Node *next;

	public:
		Node(Ant* a);
		Ant* getAnt() { return this->ant; }
};

class LinkedList
{
	private:
		Node *head;

	public:
		LinkedList();
		~LinkedList();
		LinkedList(Ant* a);
		LinkedList(const LinkedList &old);

		Ant* getAnt(int ant_id);
		bool updateAnt(int ant_id, Ant* new_ant);
		bool removeAnt(int ant_id);
		void addAnt(Ant* a);
		void operator<<(Ant* new_ant);
};

#endif
