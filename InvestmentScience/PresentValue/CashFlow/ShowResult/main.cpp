#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int main(int argc, char** argv){
    //argv[1]: interest rate, argv[2]: cash flow at 0, [3]: ..at 1, ...
    double r = stod(argv[1]);
    double result = 0.0;
    double discount = 1;
    for(int i=1;i<argc;i++){
        result += stod(argv[i])/discount;
        discount = discount *(1+r);
    }
    cout << result<<endl;

}
