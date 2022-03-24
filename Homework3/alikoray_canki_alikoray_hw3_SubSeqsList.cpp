#include <iostream>
#include "alikoray_canki_alikoray_hw3_SubSeqsList.h"

using namespace std;

SubSeqsList::SubSeqsList()
{
hHead = NULL;
}

bool SubSeqsList::IsExistList(int num) const{ // check whether the number is exist in linklist. If it is return true,
	SubSeqHeadNode *ptr;
	SubSeqNode *ptr1;
	bool correct_form1=false;
	if(hHead==NULL){
	correct_form1=false;
	}
	else{
	ptr= hHead;
	while(ptr!=NULL){
		ptr1=ptr->sHead;
		while(ptr1!=NULL){
			if(ptr1->value==num){
			correct_form1=true;
		}
		ptr1=ptr1->next;
	}
		ptr=ptr->next;
	}
	}
	return correct_form1;
}
void SubSeqsList::Insert2List (int num) { // a function that insert the number to the sHead linkedlist if the requirement
SubSeqHeadNode *ptr;                      // conditions are met
SubSeqNode *ptr1;
if(hHead==NULL){
SubSeqNode *temp1= new SubSeqNode(num,NULL);
SubSeqHeadNode*temp= new SubSeqHeadNode(1,temp1,NULL);
hHead=temp;
}
else{
ptr=hHead;
SubSeqHeadNode *prev1;
while(ptr!=NULL){
	bool fitchecker=true;
	ptr1=ptr->sHead;
	SubSeqNode *prev2;
	while(ptr1!=NULL&&fitchecker==true){ // if  fitchecker true that means number can be add
	fitchecker= checkascending(num,ptr1);
	prev2=ptr1;
	ptr1=ptr1->next;
	}
	if(fitchecker){
	SubSeqHeadNode *copyptr= new SubSeqHeadNode((ptr->size+1),NULL,NULL); // create an copy node
	SubSeqHeadNode *temp3 = ptr->next;
	copyptr->next=temp3; // connect the copy node to the main linkedlist
	ptr->next=copyptr;
	SubSeqNode *ptr2=NULL;
	ptr1=ptr->sHead;
	if(copyptr->size<=2){ // if copy node's size is smaller than 2 add manually
	if(copyptr->sHead==NULL||copyptr->sHead->next==NULL){
	SubSeqNode *adder= new SubSeqNode(num,NULL);
	if(copyptr->sHead==NULL){ // if copyptr is empty, add it the number and change its sHead
		SubSeqNode *temp4= new SubSeqNode(ptr1->value,ptr1->next);
		copyptr->sHead=temp4;
		ptr2=copyptr->sHead;
	}
	if(copyptr->sHead->next==NULL){ // if copyptr has 1 item just add to the end of it
	ptr2->next=adder;
	} 
	}
	}
	else if(copyptr->size>2){ // if copy ptr has more than 2 item, create an loop, first copy the existed linkedlist
		SubSeqNode *prevxd; 
		while(ptr1!=NULL){
		if(copyptr->sHead==NULL){
		SubSeqNode *temp4= new SubSeqNode(ptr1->value,NULL);
		copyptr->sHead=temp4;
		ptr2=copyptr->sHead;
	}
		else{
			SubSeqNode *temp4= new SubSeqNode(ptr1->value,ptr1->next); 
		ptr2->next=temp4;
		ptr2=ptr2->next;
		}
		prevxd=ptr1;
		ptr1=ptr1->next;
		prevxd=ptr1;
		
		
	}
	
	SubSeqNode *adder= new SubSeqNode(num,NULL); // after that add to the number end of the linked list
	ptr2->next=adder;
	}
	}
	
	if(fitchecker==false){
	prev1=ptr;
	ptr=ptr->next;
	}
	else if(fitchecker){
		ptr=ptr->next;
		prev1=ptr;
		ptr=ptr->next;
	}
	}
// only add the number subsequence 
SubSeqHeadNode *copyptr2= new SubSeqHeadNode(1,NULL,NULL); // create an linked list which has an single item and its num
SubSeqHeadNode *temp5 = prev1->next;						// add it to the end of the main list
copyptr2->next=temp5;
prev1->next=copyptr2;
SubSeqNode *adder2= new SubSeqNode(num,NULL);
copyptr2->sHead=adder2;
}
}

bool SubSeqsList::checkascending(int num,SubSeqNode *ptr1)const{
bool correct_form=true; //check whether the items of linklist is smaller than num
if(ptr1->value > num){
correct_form=false;	
}
return correct_form;
}

void SubSeqsList::DeleteList(int num){ // if linkedlist has an item which has a value=num, its being deleted and the linklist 
SubSeqHeadNode *ptr;					// is being reconnected
SubSeqHeadNode *prev1=NULL;
	SubSeqNode *ptr1;
	if(hHead->next==NULL){ // if linklist has only 1 item we will make linklist NULL
	hHead=NULL;
	}
	 else {           // if linkedlist has an item which has a value=num, its being deleted and the linklist
		 ptr=hHead;   // is being reconnected
		while(ptr!=NULL){
		bool changer= false;
		ptr1=ptr->sHead;
		bool correct_form=false;
		while(ptr1!=NULL&&correct_form==false){
			if(ptr1->value==num){
				ptr1=ptr->sHead;
				ClearList(ptr1);
				correct_form=true;
				if(ptr==hHead){
					hHead=hHead->next;
					delete ptr;
					ptr=hHead;
					changer=true;
				}
				else{
					SubSeqHeadNode *deleted_node;
					deleted_node=ptr;
					prev1->next=deleted_node->next;
					delete deleted_node;
					ptr=prev1;

				
				}
		}
			if(correct_form==false){
		ptr1=ptr1->next;
			}

	}	
		if(changer==false){
		prev1=ptr;
		ptr=ptr->next;
		}
	}
	}
}
/* Begin: code taken from linkedlist.cpp */
void SubSeqsList::ClearList(SubSeqNode *head){ // clear the linklist which have a name sHead
	// clears and prints the items of linkedlist
	SubSeqNode *ptr;
	while(head!=NULL)
	{
		ptr=head;
		head=head->next;
		delete ptr;
	}
}
/* End: code taken from linkedlist.cpp */
void SubSeqsList::LinkedListPrinter(){ // print the linkedlist
SubSeqHeadNode *ptr;
	SubSeqNode *ptr1;
	if(hHead==NULL){
	cout<<"List is empty!"<<endl;
	}
	else{
	ptr= hHead;
	while(ptr!=NULL){
		cout<<ptr->size<<" | ";
		ptr1=ptr->sHead;
		while(ptr1!=NULL){
		cout<<ptr1->value;
		if(ptr1->next!=NULL){
			cout<<" --> ";
		}
		ptr1=ptr1->next;
	}
		cout<<endl;
		ptr=ptr->next;
	}
	}
}
void SubSeqsList::SortingList(){ // sorts the linklist in ascending format
SubSeqHeadNode *ptr;
SubSeqHeadNode *temp20;
SubSeqHeadNode *ptrnext;
SubSeqNode *ptr1;
SubSeqNode *ptr1next;
bool correct_form1=false;
if(hHead==NULL){ 
	correct_form1=true;
}
else if(hHead->next==NULL){
correct_form1=true;
}
else{
	ptr=hHead;
	ptrnext=ptr->next;
	while(ptr!=NULL){
		while(ptrnext!=NULL){
			if(ptrnext->size < ptr->size){ // if ptrnext's size smaller than ptr's size then change their size and sHeads
				int temp31=ptr->size;
				SubSeqNode *temp313= ptr->sHead;
				ptr->size=ptrnext->size;
				ptr->sHead=ptrnext->sHead;
				ptrnext->size=temp31;
				ptrnext->sHead=temp313;

			}
			else if(ptr->size==ptrnext->size){// if their size are equall
				ptr1=ptr->sHead;
				ptr1next=ptrnext->sHead;
				bool correct_form2=false;
				while(ptr1!=NULL&&correct_form2==false){ 
					if(ptr1next->value == ptr1->value){
						correct_form2=false;
					}
					else{
					if(ptr1next->value < ptr1->value){ // ptrnext's value is smaller than ptr's value then change their size and sHeads
					int temp31=ptr->size;
					SubSeqNode *temp313= ptr->sHead;
					ptr->size=ptrnext->size;
					ptr->sHead=ptrnext->sHead;
					ptrnext->size=temp31;
					ptrnext->sHead=temp313;
					}
					correct_form2=true;
					}
					ptr1=ptr1->next;
					ptr1next=ptr1next->next;
				}
			}
			ptrnext=ptrnext->next;
		}
		ptr=ptr->next;

		if(ptr!=NULL){
		ptrnext=ptr->next;
		}
	}

}
}

void SubSeqsList::DeleteWholeList(){
SubSeqHeadNode *ptr;
SubSeqNode *ptr1;
// clears and prints the items of linkedlist
	while(hHead!=NULL){
		while(hHead->sHead!=NULL){
			ptr1=hHead->sHead;
			hHead->sHead=hHead->sHead->next;
			delete ptr1;
		}
		ptr=hHead;
		hHead=hHead->next;
		delete ptr;
	}
}
