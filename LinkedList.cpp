# Linked List 

# implementation in cpp

class Node{
public:
	int data;
	Node* next;
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	};
};

int main(){
	Node* newnode = new Node(5);  newnode is pointer with type Node and adress given
	newnode->next = new Node(6);
	cout<<newnode->next->data;
}
