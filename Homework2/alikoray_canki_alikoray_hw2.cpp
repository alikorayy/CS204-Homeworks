#include <iostream>
#include <string>
#include<sstream>

using namespace std;
struct node
{
int value;
node *next;
//default constructor
node::node ()
	:value(0), next(NULL)
{}
// constructor
node::node (int i,node *n)
	:value(i), next(n)
{}
};

bool orderchecker(string input){ // checks if the first word is A or D 
bool correct_form1=false;
if(input=="A" || input=="D"){
		correct_form1=true;
}
return correct_form1;
}

bool checklist(node* head, int num){ // checks whether the value is in linkedlist or not if yes, returns true else, false 
	node *ptr;
	bool correct_form1=false;
	if(head==NULL){
	correct_form1=false;
	}
	else{
	ptr= head;
	while(ptr!=NULL){
		if(ptr->value==num){
			correct_form1=true;
		}
		ptr=ptr->next;
	}
	}
	return correct_form1;
}
/* Begin: code taken from ptrfunc.cpp */
int DeleteOneNode (node * toBeDeleted, node * & head) // a fucntion that returns the deleted number
/* pre: toBeDeleted points to the node to be deleted from the list
   post: deletes the node pointed by toBeDeleted, updates head if changes */
{
	node * ptr;
	int deleted_num;	
	if (toBeDeleted == head)  //if the node to be deleted is the first node
	{
		head = head->next;
		deleted_num=toBeDeleted->value;
	}
	else  //if the node to be deleted is in the middle or at the end
	{
		ptr = head;
		while (ptr->next != toBeDeleted)
			ptr = ptr->next;
		//after while ptr point to the node just before toBeDeleted

		//connect the previous node to the next node and delete
		ptr->next = toBeDeleted->next;
		deleted_num=toBeDeleted->value;
		delete toBeDeleted;
	}
	return deleted_num;
}
/* End: code taken from ptrfunc.cpp */

void addnum2list(node * &head,int num,string orderinput){ // function that add number to the linked list
	string deleted_string= "";
	int deleted_num;
	node* ptr=NULL,*tail=NULL,*prev_node=NULL,*temp1=NULL;

	if(head==NULL){ // if head =null it directly add to the linkedlist and make number head
		node* temp= new node;
		temp ->value=num;
		temp ->next= NULL;
		head=temp;
		cout<<"Deleted nodes: None"<<endl;
		cout<<"Appended: "<<head->value<<endl;
		cout<<"List content: "<<head->value<<endl<<endl;
	}
	else{ // if head is not null process continues accordingly to orderinput
		cout<<"Deleted nodes: ";
		ptr=head;
		if(orderinput=="A"){ // if input is A goes here
			while(ptr!=NULL){ // untill the end of the linked list the loop continues
				if(head->next!=NULL&&head->value>num){ // if next item of the head is not null and the value of head bigger than num
					deleted_num=DeleteOneNode(ptr,head);
					deleted_string+= ".";
					cout<<deleted_num<<" ";
					ptr=head;
					prev_node=ptr;
				}
				else if((ptr->next!=NULL)&&(ptr->next->value)>num){ // if next item of the ptr is not null and the  next value of ptr is bigger than num
					deleted_num=DeleteOneNode(ptr->next,head);  // delete element which is bigger than num and remember the previous element of linked list
					deleted_string+= ".";
					cout<<deleted_num<<" ";
					prev_node=ptr;
				}
				else if((ptr->next==NULL)&&(ptr->value)>num){ // if ptr is the last item of element index and if its value is bigger than num
					prev_node=ptr;
					deleted_num=DeleteOneNode(ptr,head); // delete element which is bigger than num, head will be NULL  
					deleted_string+= "."; // create a temp node to insert the value of input
					cout<<deleted_num<<" "; // equal head to temp
					node* temp2= new node;
					temp2 ->value=num;
					temp2 ->next= NULL;
					head=temp2;
					ptr=head;
				}
				if(ptr->next==NULL||(ptr->next->value)<num){  
					if(head->value<=num){
				prev_node=ptr;
				ptr=ptr->next; // helps to move in linked list 
					}
				}
			
			}
		}
		else if(orderinput=="D") { // same things will be applied here
			while(ptr!=NULL){
				if(head->next!=NULL&&head->value<num){
					deleted_num=DeleteOneNode(ptr,head);
					deleted_string+= ".";
					cout<<deleted_num<<" ";
					ptr=head;
					prev_node=ptr;
				}
				else if((ptr->next!=NULL)&&(ptr->next->value)<num){
					deleted_num=DeleteOneNode(ptr->next,head);
					deleted_string+= ".";
					cout<<deleted_num<<" ";
					prev_node=ptr;
				}
				else if((ptr->next==NULL)&&(ptr->value)<num){
					prev_node=ptr;
					deleted_num=DeleteOneNode(ptr,head);
					deleted_string+= ".";
					cout<<deleted_num<<" ";
					node* temp2= new node;
					temp2 ->value=num;
					temp2 ->next= NULL;
					head=temp2;
					ptr=head;
				}
				if(ptr->next==NULL||(ptr->next->value)>num){
					if(head->value>=num){
				prev_node=ptr;
				ptr=ptr->next;
					}
				}
			}
		}
		tail=prev_node;
		if(tail->value!=num){
		temp1=new node;
		temp1->value=num;
		tail->next=temp1;
		tail=temp1;
	}
		if(deleted_string==""){
			cout<<"None";
		}
		cout<<endl;
		cout<<"Appended: "<<tail->value<<endl;
		cout<<"List content: ";
		node * ptr1 = head;
		while (ptr1 != NULL) 
		{
		cout << ptr1 ->value << " ";
		ptr1 = ptr1->next;
		}
		cout<<endl<<endl;
	}
}
/* Begin: code taken from linkedlist.cpp */
void ClearList(node *head)
// clears and prints the items of linkedlist
{
	cout<<"All the nodes are deleted at the end of the program: ";
	node *ptr;
	int number;
	while(head!=NULL)
	{
		ptr=head;
		number=ptr->value;
		cout<<number<<" ";
		head=head->next;
		delete ptr;
	}
}
/* End: code taken from linkedlist.cpp */
int main () {

	string order_input,num_inputs;
	int num;
	node* head= NULL;
	node* temp= NULL;
	bool cflist,correct_form=false;
	cout<<"Please enter the order mode (A/D): ";
	cin>>order_input;
	if(order_input=="A" || order_input=="D"){
		correct_form=true;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	 else{
	 cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	while(correct_form==false){ // asks for input from the user untill the first word is A or D 
	cout<<"Please enter the order mode again (A/D): ";
	cin>>order_input;
	correct_form=orderchecker(order_input);
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}

cout<<"Please enter the numbers in a line: ";
getline(cin, num_inputs); // takes the numbers that will be put into linkedlist
if(num_inputs==""){ // if input is empty 
cout<<"The list is empty at the end of the program and nothing is deleted"<<endl;
}
else{
	int input_length= num_inputs.length(),i =0;
	bool line_check=false;
	while(i<input_length && line_check==false){
		if(isdigit(num_inputs[i])){
			line_check=true;
		}
		i++;
	}
	if(line_check==false){
		cout<<"The list is empty at the end of the program and nothing is deleted"<<endl;
	}
	else{
istringstream input(num_inputs);
while(input>>num){
	cout<<"Next number: "<<num<<endl;
cflist=checklist(head,num);
if(cflist){
	cout<< num<< " is already in the list!"<<endl;
	cout<<"List content: ";
		node * ptr1 = head;
		while (ptr1 != NULL) 
		{
		cout << ptr1 ->value << " ";
		ptr1 = ptr1->next;
		}
		cout<<endl<<endl;
}// curly bracket of cflist== true
else if(cflist==false){
addnum2list(head,num,order_input);
}// curly bracket of cflist==false
}// curly bracket of while input>> num
ClearList(head);
cout<<endl;
}
}// curly bracket of else

return 0;
}