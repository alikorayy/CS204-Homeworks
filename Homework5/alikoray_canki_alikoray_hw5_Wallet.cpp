#include <iostream>
#include "alikoray_canki_alikoray_hw5_Wallet.h"
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

Wallet::Wallet() //constructor
{
size = 0;
w_array=NULL;
}

//destructor
Wallet::~Wallet()
{
size=0;
delete[] w_array;
}
//copy constructor-deep copy
Wallet::Wallet(const Wallet & copy)
{
size= copy.size;
w_array= new Money[size];

for (int i=0; i<size;i++){
w_array[i]=copy.w_array[i];
}
}

Wallet Wallet::operator+(const Money &copy)const{ //creates newWallet and adds the currency and amount on it 
bool correct_form=false;
int index;
for (int i =0; i<size;i++){ // loop for understanding whether this currency was exist in my wallet 
	if(w_array[i].currency==copy.currency){
	correct_form=true;
	index=i;
	}		
}

if(correct_form){ // if it was exist change its amount and create a new wallet
	Wallet newWallet;
	newWallet=*this;
	newWallet.w_array[index].amount += copy.amount;
	return newWallet;
}
else{ // if not create new wallet with size+1, copy the previous wallet and add the new currency and its amount
	Wallet newWallet;
	newWallet.size=size+1;
	newWallet.w_array= new Money[newWallet.size];
	for (int i=0; i<size;i++){
		newWallet.w_array[i]=w_array[i];
	}
	newWallet.w_array[size].amount=copy.amount;
	newWallet.w_array[size].currency=copy.currency;
	return newWallet;
	}
}
/* Begin: code taken from MathVector.cpp */
const Wallet & Wallet::operator=(const Wallet &rhs){ 
	
if (this != &rhs){

size=0;
delete[] w_array;

size=rhs.size;
w_array= new Money[size];
}
for (int i=0;i<size;i++){
w_array[i]=rhs.w_array[i];
}
return *this;
}
/* End: code taken from MathVector.cpp */
Wallet Wallet::operator+( const Wallet &rhs)const{ // an operator which creates an new object and fill the new object with the sum of left and right hand sides items
int index;                                         // and return the new object
Wallet result;
int count1=0;
for (int i=0;i<size;i++){ // a loop for deciding how many common currencies those two Wallets have
	for(int k=0;k<rhs.size;k++){
		if(rhs.w_array[k].currency==w_array[i].currency){
		count1++;
		}
	}
}
result.size=rhs.size+size-count1; // set the size of new Wallet
result.w_array= new Money[result.size]; // set new array for new wallet
for (int i=0; i<size;i++){ // copy the lhs's arrays' items into the newWallet
result.w_array[i]=w_array[i];
}
int t=size;
	for(int k=0;k<rhs.size;k++){ // copy the rhs's arrays's items into the newWallet
		bool correct_form=false;
		for(int j=0;j<size;j++){
			if(rhs.w_array[k].currency==result.w_array[j].currency){ // if both lhs and rhs have the same currenct return true
			correct_form=true;
			index=j;
			}	
		}
		if(correct_form==false){ // if return false keep continue to add to the rhs' item to the newWallet 
		result.w_array[t]=rhs.w_array[k];
		t++;
		}
		else if(correct_form==true){ // if return true just change the existing currencies' amount
			result.w_array[index].amount+=rhs.w_array[k].amount;
		}
		
	}
return result; // return the newWallet
}

const Wallet & Wallet::operator+=(const Wallet &rhs){ // an operator which summs rhs and lhs and assigns the resulting wallet to the lhs
Wallet copyWallet;
copyWallet=*this; // assign copyWallet to the lhs 
int index;
int count1=0;
for (int i=0;i<size;i++){ // find the common currencies between lhs and rhs
	for(int k=0;k<rhs.size;k++){
		if(rhs.w_array[k].currency==w_array[i].currency){
		count1++;
		}
	}
}
size=size+rhs.size-count1; // set the new size of lhs
delete[] w_array; // delete lhs
w_array= new Money[size]; // set new size of lhs' array
for(int i=0;i<copyWallet.size;i++){ // same thing in + operator between lhs and rhs wallet
w_array[i]=copyWallet.w_array[i];
}
int t=copyWallet.size;
for(int k=0;k<rhs.size;k++){ // same thing in + operator between lhs and rhs wallet
		bool correct_form=false;
		for(int j=0;j<copyWallet.size;j++){
			if(rhs.w_array[k].currency==w_array[j].currency){
			correct_form=true;
			index=j;
			}	
		}
		if(correct_form==false){
			w_array[t]=rhs.w_array[k];
			t++;
		}
		else if(correct_form==true){
			w_array[index].amount+=rhs.w_array[k].amount;
		}
		
	}

return *this; // return lhs wallet
}

int Wallet::getSize() // member function which returns the size of wallet
{
	return size;
}
Money* Wallet::getArray() // member function which returns the array of the wallet
{
return w_array;
}

bool operator == (Wallet& lhs,Wallet& rhs){ // a bool operator decides whether the lhs and rhs are the exactly same or not

	if(lhs.getSize()!=rhs.getSize()){ // if they have not exactly same size return false
return false;
}
else{
	bool correct_form1=true;
	int size_left=lhs.getSize();
	int size_right=rhs.getSize();
	int i=0;
	while(i<size_left&&correct_form1==true){ // a loop checks whether all the lhs's array's currencies and amounts are same az rhs'
		correct_form1=false;
		int k=0;
		while(k<size_right){
			if(lhs.getArray()[i].currency==rhs.getArray()[k].currency){ // if the lhs and rhs have the same currency
				if(lhs.getArray()[i].amount==rhs.getArray()[k].amount){ // if the lhs and rhs have same amount return true
					correct_form1=true;
				}
			}

			k++;
		}
		i++;
	}
	return correct_form1;
}

}
bool operator >= (Wallet& lhs,Money rhs){ // a bool operator returns true if a currency in the wallet which has a higher amount than Money struct
	int size_left=lhs.getSize();
	int i=0;
	bool correct_form1=false;
	while(i<size_left&&correct_form1==false){
		if(lhs.getArray()[i].currency==rhs.currency){
			if(lhs.getArray()[i].amount>=rhs.amount){
				correct_form1=true;
			}
		}
	i++;
	}
	return correct_form1;
}

bool operator <= (const Money lhs,Wallet& rhs){ // a bool operator which returns true if a currency in the money struct which has a lower amount than Wallet object  
	int size_right= rhs.getSize();
	int i=0;
	bool correct_form1=false;
	while(i<size_right&&correct_form1==false){
		if(rhs.getArray()[i].currency==lhs.currency){
			if(lhs.amount <=rhs.getArray()[i].amount){
			correct_form1=true;
			}
		}
	i++;
	}
	return correct_form1;
}

ostream &  operator << (ostream & os,Wallet wt){ // an operator which helps to print the currencies and amounts
ostringstream ostr;
int wt_size=wt.getSize();
for (int i=0;i<wt_size;i++){
	ostr<<wt.getArray()[i].currency<<" "<<wt.getArray()[i].amount<<" ";
		if(i!=wt_size-1){
		ostr<<"-"<<" ";
		}
}

os << ostr.str();
    return os;
}

Wallet Wallet::operator-(const Money &rhs)const{ // an operator which creates newWallet and assign lhs to it, after that it will reduce the amount of money 
bool correct_form=false;                         // according to rhs                        
int index;
for (int i =0; i<size;i++){                  //if the currency that wanted to be reduced is exist in wallet return true
	if(w_array[i].currency==rhs.currency){
	correct_form=true;
	index=i;
	}		
}
Wallet newWallet;
if(correct_form){ 
	if(w_array[index].amount>rhs.amount){ // if wallet has more amount just reduce the currency 
		newWallet=*this;
		newWallet.w_array[index].amount -= rhs.amount;
	}
	else if(w_array[index].amount<rhs.amount){ // if the wallet does not have enough money, return the same wallet
		newWallet=*this;
	}
	else if(w_array[index].amount==rhs.amount){ // if you have the same amount return a newWallet that doesnt have this currency
		bool index_match=false;
		newWallet.size=size-1;
		newWallet.w_array= new Money[newWallet.size];
		for (int i=0; i<size;i++){
			if(w_array[i].currency==rhs.currency){
				index_match=true;
			}
			if(index_match==false&&w_array[i].currency!=rhs.currency){
				newWallet.w_array[i]=w_array[i];
			}
			else if(index_match&&w_array[i].currency!=rhs.currency){
				newWallet.w_array[i-1]=w_array[i];
			}
		
	}
	}
}
else if(correct_form==false){ // if you dont have this currency in your wallet return the same wallet
newWallet=*this;
}
return newWallet; // return newWallet
}

