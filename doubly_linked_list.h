#pragma once
#include <iostream>
#include "graph.h"
using namespace std;

template <typename T>
struct Node {
    T data;
    Node <T> *prev;
    Node <T> *next;
};

template <typename T>
class linked_list {
   private:
    Node <T>* head;
    int size;

   public:
    linked_list() {
        size = 0;
        head = NULL;
    }

    // insertion
    void insert(T data)
    {
        Node <T>*temp = new Node<T>;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL) {
            head = temp;
            size++;
        } 
        else 
        {
            Node <T>*temp2 = head;
            while (temp2->next != NULL) {
                temp2 = temp2->next;
            }
            temp2->next = temp;
            temp->prev = temp2;
            size++;
        }
    }

    // deletion
    void deletion(T data) {
        Node<T>*temp = head;
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

    bool search(T val) {
        Node<T> *temp = head;
        if (head == NULL)
        {
            cout << "list is empty" << endl;
        } 
        else
        {
            while (temp !=NULL) 
            {
                if (temp->data == val)
                {
                    return true;
                }
                temp = temp->next;
            }
                return false;
        }
    }

    void display() {
        Node <T>*temp = head;
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

   

    T operator[](int i) {
        Node <T>*temp = head;
        int count = 0;
        while (count != i)
        {
            temp = temp->next;
            count++;
        }

        if (count == i)
        {
            return temp->data;
        }
    }

    void empty()
    {
        Node <T>*temp = head;
        while (temp!= NULL)
        {
            Node<T>* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};