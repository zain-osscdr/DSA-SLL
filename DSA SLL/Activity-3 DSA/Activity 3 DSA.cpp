#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int value){
	data = value;
	next = nullptr;
	}
};


class LinkedList{
	public:
	Node* head;
	LinkedList(){
		head = nullptr;
	}

	void insertAtHead(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		cout <<"Number Inserted At Head"<<endl;
	}

	void insertAtTail(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp;
			temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
			cout << "Number Inserted at Tail" << endl;
	}
	}

	void display() {
		Node* temp =head;

		while (temp != nullptr){
			cout << temp->data<<"->";
			temp = temp->next;
		}
			cout << "Null"<<endl;
		if (head == nullptr) {
			cout << "List Empty"<<endl;
		}
	}


	void insertbefore(int value, int newData) {
		if (head == nullptr) {
			cout << "Empty List"<<endl;
			cout<<" Insertion Not possible"<<endl;
			return;
		}
		if (head->data == value) {
			Node* newNode = new Node(newData);
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr && temp->next->data != value) {
			temp = temp->next;
		}
		if (temp->next == nullptr) {
			cout << "Value Not Found" << endl;
			return;
		}
		Node* newNode = new Node(newData);
		newNode->next = temp->next;
		temp->next = newNode;
	}

	void insertAfter(int value, int newData) {
		if (head == nullptr) {
			cout << "Empty List"<<endl;
			cout<<" Insertion Not possible"<<endl;
			return;
		}
		if (head->data == value) {
			Node* newNode = new Node(newData);
			Node* temp = head;
			newNode->next = temp->next;
			temp->next = newNode;

			return;
		}
		Node* temp = head;
		while (temp != nullptr && temp->data != value) {
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "Value Not Found" << endl;
			return;
		}
		Node* newNode = new Node(newData);

			newNode->next = temp->next;

		temp->next = newNode;
	}

	void searchValue(int key) {
		Node* temp = head;
		bool flag = false;
		while (temp != nullptr) {
			if (temp->data == key) {
				flag = true;
				break;
			}
			temp = temp->next;
		}
		if (!flag){
			cout <<"Not Found"<<endl;
		}
		else if (flag) {
			cout << "Element Found" << endl;
		}
	}

	void valueUpdate(int old,int updated) {
		Node* temp = head;
		bool flag = false;
		while (temp != nullptr) {
			if (temp->data == old) {
				temp->data = updated;
				flag = true;
				break;
			}
			temp = temp->next;
		}
		if (!flag) {
			cout<<old<<" <-  Value not in the List"<<endl;
		}
		else if (flag) {
			cout << "Updated"<<endl;
		}
	}

	void deleteAtPosition(int p) {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		if (p < 1) {
			cout << "Invalid Node" << endl;
			return;
		}
		if (p == 1) {

			Node* del=head;
			head = head->next;
			delete del;
			return;
		}

		Node* temp = head;
		int count = 1;
		while (temp->next != nullptr && count < p-1) {
			count++;
			temp = temp->next;
		}
		if (temp==nullptr||temp->next == nullptr) {
			cout << "Out Of Range Index " << endl;
			return;
		}
		Node* del = temp->next;
		temp->next = del->next;
		delete del;
	}

	void deleteBefore(int value) {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		if (head->data == value) {
			cout << "Can't delete before head" << endl;
			return;
		}
		if (head->next!=nullptr && head->next->data == value) {
			Node* del = head;
			head = head->next;
			delete del;
			return;
		}
		Node* temp = head;
		Node* prev = nullptr;
		while (temp->next != nullptr && temp->next->data != value) {
			prev = temp;
			temp = temp->next;
		}
		if (temp->next==nullptr) {
			cout << "Value Dont Exist" << endl;
			return;

		}
		if (prev != nullptr) {

			prev->next = temp->next;
			delete temp;
		}
	}

	void deleteAfter(int value) {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		Node* temp = head;
		while (temp != nullptr && temp->data != value) {
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "No Record" << endl;
			return;

		}
		if (temp->next == nullptr) {

			cout << "No Nodes After This Data " << endl;
			return;
		}
		Node* del = temp->next;
		temp->next = del->next;
		delete del;

	}


	void Reverse() {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		Node* prev = nullptr;
		Node* temp = head;
		Node* next = nullptr;
			while (temp != nullptr) {
				next = temp->next;
				temp->next = prev;
				prev = temp;
				temp = next;
			}
			head = prev;
			temp = head;
			while (temp!= nullptr) {
				cout << temp->data << "->";
				temp = temp->next;
			}
			cout << "null";
}

void deleteMiddle() {
		if (head == nullptr) {
			cout << "Middle does't Exist" << endl;
			return;
		}
		int count = 0;
		int middle = 0;
		Node* temp = head;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		middle = (count - 1) / 2;
		temp = head;
		int count2 = 0;
		while (temp->next != nullptr && count2 < middle-1) {
			count2++;
			temp = temp->next;

		}
		if (temp->next == nullptr) {
			cout << "Middle does't Exist"<<endl;
			return;
		}
		Node* del = temp->next;
		temp->next = temp->next->next;
		delete del;


		}

	void deleteDuplicate() {
		bool flag = true;
		if (head == nullptr) {
			cout << "Nothing to delete "<<endl;
			return;
		}

		Node* temp = head;

		while (temp->next != nullptr ) {
			if (temp->next->data == temp->data) {
				Node* toDel = temp->next;
				temp->next = temp->next->next;
				flag = false;
				delete toDel;

			}
			else {
				temp = temp->next;
			}
		}
		if (flag) {
			cout << " No Value Found "<<endl;
		}
	}

};



int main()
{
    cout<<"My Name : Muhammad Zain-ul-Abideen "<<endl;
    cout<<"ID: F2023065161    SeCTION : W-5"<<endl;
    cout<<"Lets Start Single Link List"<<endl;
	LinkedList List;
	List.insertAtHead(40);
	List.insertAtHead(50);
	List.insertAtTail(11);
	List.insertAtTail(50);
	List.display();

	cout<<"We are Calling Insert Before Function To Insert 4 Before 10 "<<endl;
	List.insertbefore(11, 4);
	List.display();

	cout<<"We are Calling Insert After Function To Insert 40 After 50 "<<endl;
	List.insertAfter(40, 50);
	List.display();




	cout<<"We are Calling delete before Function To delete Before Node Of 20  "<<endl;
	List.deleteBefore(11);
	List.display();

	cout<<"We are Calling delete after Function To delete After Node Of 4  "<<endl;
	List.deleteAfter(11);
	List.display();

	cout<<"Now We Are Deleting Middle Node Of The List : "<<endl;
	List.deleteMiddle();
	List.display();

	cout<<"Now All Duplicate Values Will Be Deleted  : "<<endl;
	List.deleteDuplicate();
	List.display();

	cout<<"Now We Are Going To update Node Value 60 To 20 : "<<endl;
	List.valueUpdate(40, 20);

	cout<<"Now We Are Going To search Node Value  20 : "<<endl;
	List.searchValue(11);


	cout<<"Now We Are Going To Reverse our Link List"<<endl;

	List.Reverse();
	cout<<" "<<endl;

    cout<<"Enter The Node Position To Delete : Range(1-Onwords)" << endl;
	int p;
	cin >> p;
    cout<<"The List After Deletion Is : "<<endl;
	List.deleteAtPosition(p);
	List.display();
}
