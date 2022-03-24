#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include <iomanip>     // for setw
#include <vector>

using namespace std; 

struct wordinfo { // a struct to keep to informations that are obtained from text and call them when they needed easily
string word;
int row_index;
int col_index;
string direction;
string time_turn;
};

bool textchecker(string text){ // a bool function that checks whether the txt file opened succesfully or not.
ifstream input;					// if it opens succesfuly, returns true, else false
bool correct_form=false;
input.open(text.c_str()); // opens txt
if(!input.fail()){
correct_form=true;
}
input.close(); // closes txt
return correct_form;
}

bool matrixfunction (wordinfo inf,vector<vector<char>> & mat) { // a bool function that checks whether the word can be inserted
																// into a matrices, if it can it returns false , else true
int size_word= inf.word.length();
vector<vector<char>>temp_mat=mat; // a matrix which is equal the main matrix, 
string w=inf.word;					// if the word can not be inserted, it clears the word's letters like it has never inserted
	bool correct_form1=false;
	int i =0;
	string direct,orient;
	direct= inf.direction;
	orient= inf.time_turn;
	int k=inf.row_index;
	int j= inf.col_index;
	while ( i < size_word && correct_form1==false)  { // while loop, it continous untill the word inserted succesfully or correct_form1 returns false
		if(i==0){  //try to place first character into the matrix                                  
		if(mat[k][j]!='-'){
				correct_form1=true;
				}
		else {
			mat[k][j]= w[0];
		}
		}
		else { // if it is not first character 
		if(direct == "r") { // try to put into direction according to input
			if( (j+1)< mat[0].size()&& mat[k][j+1]== '-' ){
				mat[k][j+1]=w[i];
				j++;
			}
			else { // if it can not, try to put into according to input CW or CCW
				if(orient== "CCW"){
					 if((k-1)<mat.size() && mat[k-1][j]== '-') {
						if((k-1)>=0){
							mat[k-1][j]=w[i];
							k--;
						}
					}
					else if( (j-1)< mat[0].size()&& mat[k][j-1]== '-' ){
						if((j-1)>=0) {
				mat[k][j-1]=w[i];
				j--;
			}
			}
					 else if( (k+1)< mat.size()&& mat[k+1][j]== '-' ){
							mat[k+1][j]=w[i];
							k++;
							}
				
					
					else{ // if it can not put into any direction that means word will not be placed
					correct_form1= true;
					}
			}
				else if (orient=="CW"){
					if( (k+1)< mat.size()&& mat[k+1][j]== '-' ){
				mat[k+1][j]=w[i];
				k++;
				}
					else if( (j-1)< mat[0].size()&& mat[k][j-1]== '-' ){
						if((j-1)>=0) {
				mat[k][j-1]=w[i];
				j--;
			}
			}
					
					else if((k-1)<mat.size() && mat[k-1][j]== '-') {
						if((k-1)>=0){
							mat[k-1][j]=w[i];
							k--;
						}
					}
					else{
					correct_form1=true;
					}
					

				}
					
		}
		
		
		
		}
		else if (direct== "l") {
			if( (j-1)< mat[0].size()&& mat[k][j-1]== '-' ){
						if((j-1)>=0) {
				mat[k][j-1]=w[i];
				j--;
			}
			}
			else{
				if(orient=="CW") {
					if((k-1)<mat.size() && mat[k-1][j]== '-') {
						if((k-1)>=0){
							mat[k-1][j]=w[i];
							k--;
						}
					}
					else if( (j+1)< mat[0].size()&& mat[k][j+1]== '-' ){
						mat[k][j+1]=w[i];
						j++;
					}
					else if( (k+1)< mat.size()&& mat[k+1][j]== '-' ){
							mat[k+1][j]=w[i];
							k++;
							}
					else{
					correct_form1=true;
					}
				}
				else if (orient== "CCW") {
					if( (k+1)< mat.size()&& mat[k+1][j]== '-' ){
							mat[k+1][j]=w[i];
							k++;
							}
					else if( (j+1)< mat[0].size()&& mat[k][j+1]== '-' ){
						mat[k][j+1]=w[i];
						j++;
					}
					if((k-1)<mat.size() && mat[k-1][j]== '-') {
						if((k-1)>=0){
							mat[k-1][j]=w[i];
							k--;
						}
					}
					else{
					correct_form1=true;
					}
				}
			}
		}
		else if(direct=="u") {
			if((k-1)<mat.size() && mat[k-1][j]== '-') {
						if((k-1)>=0){
							mat[k-1][j]=w[i];
							k--;
						}
					}
			else{
				if(orient=="CW"){
					if( (j+1)< mat[0].size()&& mat[k][j+1]== '-' ){
						mat[k][j+1]=w[i];
						j++;
					}
					else if( (k+1)< mat.size()&& mat[k+1][j]== '-' ){
							mat[k+1][j]=w[i];
							k++;
							}
					else if( (j-1)< mat[0].size()&& mat[k][j-1]== '-' ){
						if((j-1)>=0) {
				mat[k][j-1]=w[i];
				j--;
							}
							}
					else{
					correct_form1=true;
					}

				}
				else if(orient== "CCW") {
					if( (j-1)< mat[0].size()&& mat[k][j-1]== '-' ){
						if((j-1)>=0) {
				mat[k][j-1]=w[i];
				j--;
					}
					}
					else if( (k+1)< mat.size()&& mat[k+1][j]== '-' ){
							mat[k+1][j]=w[i];
							k++;
							}
					else if( (j+1)< mat[0].size()&& mat[k][j+1]== '-' ){
						mat[k][j+1]=w[i];
						j++;
					}
					else{
					correct_form1=true;
					}
				}
			}

		}
		else if(direct=="d"){
			if( (k+1)< mat.size()&& mat[k+1][j]== '-' ){
				mat[k+1][j]=w[i];
				k++;
				}
			else{
				if(orient=="CW"){
				if( (j-1)< mat[0].size()&& mat[k][j-1]== '-' ){
						if((j-1)>=0) {
				mat[k][j-1]=w[i];
				j--;
					}
					}
				else if((k-1)<mat.size() && mat[k-1][j]== '-') {
						if((k-1)>=0){
							mat[k-1][j]=w[i];
							k--;
						}
						}
				else if( (j+1)< mat[0].size()&& mat[k][j+1]== '-' ){
						mat[k][j+1]=w[i];
						j++;
					}
				else{
					correct_form1=true;
					}
				}
				else if(orient=="CCW"){
					if( (j+1)< mat[0].size()&& mat[k][j+1]== '-' ){
				mat[k][j+1]=w[i];
				j++;
					}
					else if((k-1)<mat.size() && mat[k-1][j]== '-') {
						if((k-1)>=0){
							mat[k-1][j]=w[i];
							k--;
						}
						}
					else if( (j-1)< mat[0].size()&& mat[k][j-1]== '-' ){
						if((j-1)>=0) {
				mat[k][j-1]=w[i];
				j--;
					}
					}
					else{
					correct_form1=true;
					}
				}
			}
		}

		
	}													
	i++;
} // bracket of while loop
if(correct_form1==true){ // that means word could ne be placed, so equalise the matrix with old matrix
	mat=temp_mat;
}
	return correct_form1;
	}

	void printfunction(vector<vector<char>> & mat){ // a fucntion which prints the matrix
		for(int k=0; k< mat.size();k++){
			for(int j=0; j< mat[0].size();j++){
			cout<<setw(4)<<mat[k][j];
			}
			cout<<endl;
		}
	}
	


int main() {
string text_name,line,row_num,col_num;
int row_num1,col_num1;
ifstream input_text;
bool correct_form= false;
cout<<"Please enter the name of the file: ";
cin>>text_name; // take txt name as input
input_text.open(text_name.c_str()); // open txt
if(!input_text.fail()){
correct_form=true;
}
while(correct_form==false){ // get txt input untill the correct form entered
	cout<<"File name is incorrect, please enter again: ";
	cin >> text_name;
	correct_form= textchecker(text_name);
	if(correct_form){
	input_text.open(text_name.c_str()); // open txt
	}
}
getline(input_text,line);
istringstream input2(line);
input2>> row_num>>col_num; // take number of row and column as input as string
row_num1= stoi(row_num); // turn row number into integer
col_num1=stoi(col_num); // turn column number into integer
if( row_num1 > 0 && col_num1 > 0) { // input check 
vector<vector<char>>mat(row_num1,vector<char>(col_num1,'-')); // a matrix all elements are "-"
while(getline(input_text,line)) { // read line by line
wordinfo info; // struct variable
	string temp_word;
	string cargo= "";
	int index1,index2,index3,index4;
	int wordcount = 0;
	istringstream input1(line);
	while (input1>>temp_word) {
		cargo += temp_word +" ";
		wordcount++;
	}
	cargo = cargo.substr(0,cargo.length()-1);
	
	if (wordcount != 5){ // wordcount check
	cout <<"Invalid line! Number of values is different than 5."<<endl;
	}
	else {
		index1= cargo.find(" ");
		index2= cargo.find(" ",index1+1);
		index3= cargo.find(" ",index2+1);
		index4= cargo.rfind(" ");
		info.word= cargo.substr(0,index1);
		info.row_index= stoi(cargo.substr(index1+1,(index2-index1)-1));
		info.col_index= stoi(cargo.substr(index2+1,(index3-index2)-1));
		info.direction= cargo.substr(index3+1,(index4-index3)-1);
		info.time_turn= cargo.substr(index4+1,((cargo.length()-1)-index4));
if ((info.row_index <0 || info.row_index >=row_num1) || ( info.col_index <0 || info.col_index >= col_num1)) { // row / column input check
cout << "Starting point is out of range! Point: "<< info.row_index<< ","<< info.col_index<<endl;
}
else if (info.direction != "r" && info.direction != "l" &&info.direction != "u" &&info.direction != "d") { // direction input check
cout << "Invalid input for direction! Direction: "<< info.direction<<endl;
}
else if (info.time_turn != "CW" && info.time_turn != "CCW"){ // orientation input check
cout << "Invalid input for orientation! Orientation: "<<info.time_turn<<endl;
}
else {
	bool function_result;
	function_result=matrixfunction(info,mat);
	if(function_result==false){
		cout<< '"'<<info.word<<'"'<<" was put into the matrix with given starting point: "
			<<info.row_index<<","<<info.col_index<<" direction: "<<info.direction<<" orientation: "<<info.time_turn<<endl;
		printfunction(mat);
	}
	else if(function_result){
		cout<< '"'<<info.word<<'"'<<" could not be put into the matrix with given starting point: "
			<<info.row_index<<","<<info.col_index<<" direction: "<<info.direction<<" orientation: "<<info.time_turn<<endl;
		printfunction(mat);	
	}
}// the bracket of else (without problem) 
}// the bracket of else == wordcount==5
}// the bracket of while getline
} //  the bracket of row and col num > 0
else { // if row or number input is not positive
cout <<"Invalid number for row and/or column!"<<endl;
}

return 0;
}