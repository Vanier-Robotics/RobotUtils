#include "PWMHandle.cpp"
#include <iostream>
using namespace std;
int main(){
    PWMHandle pwm = PWMHandle(1,false,false); 
    cout << pwm.getisOutput()<<endl;
}