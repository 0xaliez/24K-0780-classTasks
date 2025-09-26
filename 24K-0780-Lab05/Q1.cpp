#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int guess(int n){

	
	int p1, p2;
	
	cout<<"Player 1 guess: ";
	cin>>p1;
	
	cout<<"Player 2 guess: ";
	cin>>p2;
	
	if(p1 == n || p2 == n){
		(p1 == n)? cout<<"p1 won" : cout<<"p2 won";
		return 1; 
	}
	
	if(p1 > n){
		cout<<"Player 1 guess was higher than the number."<<endl;
	} else {
		cout<<"Player 1 guess was lower than the number."<<endl;
	}

	if(p1 == n || p2 == n){
		(p1 == n)? cout<<"p1 won" : cout<<"p2 won";
		return 1; 
	}
	
	if (p2 > n) {
		cout<<"Player 2 guess was higher than the number."<<endl;
	} else {
		cout<<"Player 2 guess was lower than the number."<<endl;

	}
	
	guess(n);
}

int main(){
	
	srand(time(0)); 
    int n = (rand() % 100) + 1;
    cout<<"The number is: "<<n<<endl;
	guess(n);
}
