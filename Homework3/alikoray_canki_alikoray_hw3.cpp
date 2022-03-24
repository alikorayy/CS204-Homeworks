#include <iostream>
#include "alikoray_canki_alikoray_hw3_SubSeqsList.h"
#include <string>
#include<sstream>

using namespace std;

int main(){
string num_inputs;
int num;
cout<<"Please enter the numbers in a line: ";
getline(cin, num_inputs);// takes the numbers that will be put into linkedlist
cout<<endl;
if(num_inputs==""){ // if nothing is entered
cout<<endl;
cout<<"FINAL CONTENT"<<endl;
cout<<"List is empty!"<<endl;
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
	if(line_check==false){ // if no any number is entered
		cout<<endl;
cout<<"FINAL CONTENT"<<endl;
cout<<"List is empty!"<<endl;
}
	else{
istringstream input(num_inputs);
SubSeqsList linklist;
while(input>>num){
bool isexist;
if(num>=0){ // if number is bigger than 0
isexist =linklist.IsExistList(num);
if(isexist==false){ // if isexist func returns false
	cout<<"Subsequence(s) containing "<<num<<" has/have been added"<<endl;
linklist.Insert2List(num);
}
else{ // if it returns true
cout<<num<< " is already in the list!"<<endl;
}
}
else if(num<0){ // if num is smaller than 0 that means number will be delete the current number or will not be added
	num= -1*(num);
	isexist =linklist.IsExistList(num);
	if(isexist==true){ // if it is exist delete the linkedlists which has an items as num
	cout<<"All subsequence(s) containing "<< num<<" has/have been deleted"<<endl;
	linklist.DeleteList(num);
	}
	else{ // cout an error and ignore it 
	cout<<"There is no subsequence that contains "<<num<<" to be deleted"<<endl;
	}
}
}
linklist.SortingList();
cout<<endl;
cout<<"FINAL CONTENT"<<endl;
linklist.LinkedListPrinter();
linklist.DeleteWholeList();
	}
	}
return 0;
}