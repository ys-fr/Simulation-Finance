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

void SingleQueueDynamics(double Intensity[3], double t){
    //Intensity: [0]=LO, [1]=CO, [2]=MO
    double A = *max_element(Intensity,Intensity+2), a;
    double V = rand_pl(1.5);
    double dt = (0.01) / max(A, V*Intensity[2]);
    Intensity[1] += Intensity[0];
    int step = ((int)t/dt)+1;
    t = 0.0;
    double T=0.0, V1=V;
    for(int i=0;i < step;i++){
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
        if(V==0){
            cout<<V1<<","<<t-T<<endl;
            V=rand_pl(1.5);
            V1 = V;
        }
        dt = 0.01/max(A,V*Intensity[2]);
    }
}

int main(int argc, char** argv){
    // dx/dt = c* x(t) + Poisson(lambda, h)
    double Intensity[3];
    Intensity[0] = stod(argv[1]);
    Intensity[1] = stod(argv[2]);
    Intensity[2] = stod(argv[3]);
    double t = stod(argv[4]);
    SingleQueueDynamics(Intensity,t);
}