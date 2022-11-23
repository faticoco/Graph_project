#pragma once
#include<iostream>
#include"graph.h"
using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
};
class linked_list {

private:
	Node* head;
	int size;
public:
	linked_list()
	{
		size = 0;
		head = NULL;
	}

	//insertion
	void insert(int data)
	{
		Node* temp = new Node;
		temp->next =temp->prev= NULL;
		temp->data = data;

		if (head == NULL)
		{
			head = temp;
		}
		else if (head->next == NULL)
		{
			head->next = temp;
			temp->prev = head;
		}
		else
		{

			Node* temp1 = head;
			while (temp1->next != NULL)
			{
				temp1 = temp1->next;
			}
			temp->prev = temp1;
			temp1->next = temp;
		}
		size++;
	}

	//deletion
	void deletion(int data)
	{
		Node* temp1 = head;
		while (temp1->next !=NULL)
		{
			if (temp1->data == data)
			{
				Node* temp2 = temp1->prev;
				Node* temp3 = temp1->next;
				delete temp1;
				temp2->next = temp3;
				temp3->prev = temp2;
				size--;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
	}


	bool search(int data)
	{
		Node* temp1 = head;
		while (temp1->next != NULL)
		{
			if (temp1->data == data)
			{
				return true;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
		return false;
	}


	void display()
	{
		Node* temp1 = head;
		while (temp1->next != NULL)
		{
			cout << temp1->data<<" ";
		    temp1 = temp1->next;
		}
	}

	int get_size()
	{
		return size;
	}

	int operator[](int i)
	{
		Node* temp1 = head;
		int counter = 0;
		while (temp1->next != NULL)
		{
			cout << temp1->data << " ";
			temp1 = temp1->next;
			counter++;
			if (counter == i)
			{
				return temp1->data;
			}
		}
	}
};