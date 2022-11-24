#pragma once
#include <iostream>
#include "graph.h"
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
class linked_list {
   private:
    Node* head;
    int size;

   public:
    linked_list() {
        size = 0;
        head = NULL;
    }

    // insertion
    void insert(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL) {
            head = temp;
            size++;
        } else {
            Node* temp2 = head;
            while (temp2->next != NULL) {
                temp2 = temp2->next;
            }
            temp2->next = temp;
            temp->prev = temp2;
            size++;
        }
    }

    // deletion
    void deletion(int data) {
        Node* temp = head;
        if (head == NULL) {
            cout << "list is empty" << endl;
        } else {
            while (temp->data != data) {
                temp = temp->next;
            }
            if (temp->prev == NULL) {
                head = temp->next;
                temp->next->prev = NULL;
                delete temp;
                size--;
            } else if (temp->next == NULL) {
                temp->prev->next = NULL;
                delete temp;
                size--;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                size--;
            }
        }
    }

    bool search(int data) {
        Node* temp = head;
        if (head == NULL) {
            cout << "list is empty" << endl;
        } else {
            while (temp->data != data) {
                temp = temp->next;
            }
            if (temp->data == data) {
                return true;
            } else {
                return false;
            }
        }
    }

    void display() {
        Node* temp = head;
        if (head == NULL) {
            cout << "list is empty" << endl;
        } else {
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    int get_size() { return size; }

    int operator[](int i) {
        Node* temp = head;
        int count = 0;
        while (count != i) {
            temp = temp->next;
            count++;
        }
        return temp->data;
    }
};