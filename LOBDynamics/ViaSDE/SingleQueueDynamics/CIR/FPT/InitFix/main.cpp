#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<omp.h>
#include<string>
using namespace std;

random_device seed_gen;
mt19937 engine(seed_gen());


double uniform_random(){
    double x;
    uniform_real_distribution<> dist(0.0,1.0);
    x=dist(engine);
    return x;
}
int uniform_random_int(int x){
    int xx;
    uniform_int_distribution<> dist(0.0,x-1);
    xx=dist(engine);
    return xx;
}
int rand_pl(double alpha){
    double s = (1- uniform_random());
    double x= pow(s,1/alpha);
    x= 1/x + 1;
    return x;
}

using namespace std;

void SingleQueueDynamics(double Intensity[3], int N, int MaxInit){
    //Intensity: [0]=LO, [1]=CO, [2]=MO
    double A = *max_element(Intensity,Intensity+2), a;
    double V = rand_pl(1.5);
    double dt = (0.01) / max(A, V*Intensity[2]);
    Intensity[1] += Intensity[0];
    #pragma omp parallel for
    for(int I=1;I<MaxInit+1;I++){
        vector<double> result(N);
        for(int i=0;i<N;i++){
            double V = I;
            double t=0.0;
            while(V!=0){
                a = uniform_random();
                if(a < dt*Intensity[0]){
                    //LO
                    V+=1;
                }
                else if(a<dt*Intensity[1]){
                    //MO
                    V-=1;
                }
                else if(a< (dt*Intensity[1]) + (dt*Intensity[2]*V) ){
                    //CO
                    V-=1;
                }
                t+=dt;
                dt = 0.01/max(A,V*Intensity[2]);
            }
            cout<<I<<","<<t<<endl;
        }
    }
}

int main(int argc, char** argv){
    // dx/dt = c* x(t) + Poisson(lambda, h)
    double Intensity[3];
    Intensity[0] = stod(argv[1]);
    Intensity[1] = stod(argv[2]);
    Intensity[2] = stod(argv[3]);
    int N = stod(argv[4]);
    int MaxInit = stod(argv[4]);
    SingleQueueDynamics(Intensity,N,MaxInit);
}