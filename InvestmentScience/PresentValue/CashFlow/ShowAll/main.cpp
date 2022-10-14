#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int main(int argc, char** argv){
    //argv[1]: interest rate, argv[2]: cash flow at 0, [3]: ..at 1, ...
    double r = stod(argv[1]);
    double result = 0.0;
    double discount = 1;
    double c ;
    for(int i=1;i<argc;i++){
        c = stod(argv[i])/discount;
        cout <<"present value of cash flow at "<<i-1 <<" is "<< c <<endl;
        result += stod(argv[i])/discount;
        discount = discount *(1+r);

    }

}
