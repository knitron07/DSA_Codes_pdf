#include<iostream>
using namespace std;
//Find minimum number of people must contain in hall 
//so that probability of people getting same birth is 50%
int birthDayPradox(float percentage){
    int people=0;
    float x=1;
    float num=365;
    float denom=365;

    if(percentage == 1)
    return 366;

    while(x>1-percentage)
    {
        x=x*(num/denom);
        num--;
        people++;

        cout<<"People "<<people<<" and x="<<x<<endl;
    }
    
    return people;
}

int main(){
    cout<<birthDayPradox(0.5)<<endl;
    return 0;
}