#include<iostream>
#include<string>
using namespace std;


int main(int argc, char** argv){
    //argv[1]: interest rate, argv[2]: period, argv[3]: initial condition
    double r = stod(argv[1]);
    double t = stod(argv[2]);
    double init = stod(argv[3]);
    for(int i=0;i<=t;i++){
        cout <<init<<endl;
        init = init*(1+r);
    }
    

}
