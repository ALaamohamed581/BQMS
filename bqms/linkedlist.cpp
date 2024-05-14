// data_structres.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class node {
public:
	node* Prev, * next;
	int Data;
	string mode = "active";
	node(int data) {
		this->Data = data;
		next = Prev = NULL;
	}
};

class linked_list {
public:
	node* head, * tail;
	static int  counte;
	linked_list() {
		head = tail = NULL;
		counte++;
		cout << counte;
	}

	void add(int data) {
		node* nodee = new node(data);
		if (head == NULL)
		{
			head = tail = nodee;
		}
		else {
			tail->next = nodee;
			nodee->Prev = tail;
			tail = nodee;
		}
	}
	void display() {
		node* current = head;
		while (current != NULL)
		{

			cout << current->Data << "\n";
			current = current->next;


		}


	};
	node GetNodeByData(int data)
	{

		node* current = head;
		node* n1 = new node(data);
		while (current != NULL)
		{
			if (n1->Data == current->Data)
				n1 = n1->next;

			delete n1;
			return *current, 1;

			current = current->next;
		}

		return NULL;
	}
	/*void InsertAfter(int data, int afterData) {
		node* n1 = GetNodeByData(data);
		node* current = head;
		while (current != NULL)

		{
			if (n1->Data == current->Data) {
				n1->Data = afterData;
				current->Prev->next = n1;
				n1->next = current->next;
				n1 = current;


			}
			current = current->next;


		}
	};*/
	void InsertAfter(int data, int afterData) {
		node* n1 = new node(afterData);

		node* current = head;

		while (current != NULL) {
			/*if (current->Prev==NULL) {;
			node* a = current;
				node* b = head->next;
				a->next = n1;
				n1->Prev = a;
				b->Prev = n1;
				n1->next = b;



				current = current->next;


			}*/

			if (data == current->Data) {
				node* a = current;
				node* b = current->next;
				a->next = n1;
				n1->Prev = a;
				b->Prev = n1;
				n1->next = b;

				current = current->next;

			}
			else if (data == tail->Data)
			{

				n1->next = NULL;
				tail->next = n1;

			}
			current = current->next;
		}
	};

	int GetDataByIndex(int index) {
		node* current = head;
		int currentIndex = 0;
		while (current != NULL)
		{
			if (index == currentIndex) {
				return current->Data;
			}
			else {
				current = current->next;
				currentIndex++;
			}

		}
		return NULL;
	}

	node is_found(int data) {
		node* current = head;
		while (current != NULL) {
			if (data == current->Data) {
				cout << "found";
				return current->Data;
			}
			current = current->next;
		}
	}

	linked_list* Reverse() {
		linked_list r;
		node* current = tail;
		while (current->Prev != NULL) {

			r.add(current->Data);

			current = current->Prev;
			if (current->Prev == NULL) {
				r.add(current->Data);
			}
		}
		cout << "reversed";
		r.display();
		return 0;


	}
	void InPlaceRevers() {

		node* current = tail;
		while (current->Prev != NULL)
		{


			current->next = current->Prev;
			if (current->Prev == head) {
				cout << current->Data;
				current = head;

			}
			cout << current->Data;

			current = current->Prev;


		}

	}
	int size() {
		int size = 0;
		node* curret = head;
		while (curret != NULL)
		{
			size++;
			curret = curret->next;
		}
		return size;
	}
	void bublesort() {
		int it = 0;
		int s = size();
		int itrtitions = 0;
		node* current = head;

		for (int j = 0; j < s - 2; j++)
		{
			current = head;
			for (int i = 0; i < s - 1; i++)
			{
				if (current->Data > current->next->Data) {

					swap(current->Data, current->next->Data);

				}


				current = current->next;
				it++;
			}

			current = current->next;


		}

		cout << it << "\n";

	}
	int BinarySearch(int data)
	{
		int minIndex = 0, maxIndex = size() - 1;
		int midIndex;

		while (minIndex <= maxIndex)
		{

			midIndex = (minIndex + maxIndex) / 2;

			if (data == GetDataByIndex(midIndex)) {
				cout << "found;";
				return 1;
			}

			else if (data > GetDataByIndex(midIndex)) {
				cout << "not found biiger";
				minIndex = midIndex + 1;
			}

			else if (data < GetDataByIndex(midIndex)) {
				cout << "not found smaller";
				maxIndex = midIndex - 1;
			}
		}

		return 0;
	}



	void serever() {

	}
};



//
//int main()
//{
//
//	linked_list m;
//	linked_list q;
//	linked_list w;
//	linked_list e;
//	linked_list r;
//	linked_list t;
//	linked_list f;
//	linked_list c;
//	m.add(1);
//	m.add(2);
//	m.add(3);
//	m.add(4);
//	m.add(5);
//
//	m.GetNodeByData(3);
//	m.display();
//	///*m.is_found(10);*/
//	////m.InsertAfter(	1, 5);
//	//m.display();
// //m.Reverse();
//	//m.bublesort();
//	//m.GetDataByIndex(2);
//	//m.BinarySearch(50);
//
// //m.InPlaceRevers();
//	//m.GetDataByIndex(3);
//
//
//
//
//
//
//}
//
