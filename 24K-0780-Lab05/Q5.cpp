#include<iostream>

using namespace std;

int sumDigits(int num){
    if(num==0) return 0;
    return num%10 + sumDigits(num/10);
}

int nestedSum(int num){
    if(num<10 && num>=0) return num;
    return nestedSum(sumDigits(num));
}

int main(){
    int num;
    cout<< "Enter a number: ";
    cin>>num;
    cout<< "The nested sum of digits is: "<< nestedSum(num)<<endl;
}
