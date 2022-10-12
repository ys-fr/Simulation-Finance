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

void JointQueueDynamics(double Intensity[6], double t){
    //Intensity: [0]=sell LO, [1]=sell CO, [2]=sell MO
    //Intensity: [3]=buy LO, [4]=buy CO, [5]=buy MO
    double dt = (0.01) / (*max_element(Intensity,Intensity +6));
    Intensity[1] += Intensity[0];
    Intensity[2] += Intensity[1];
    Intensity[3] += Intensity[2];
    Intensity[4] += Intensity[3];
    Intensity[5] += Intensity[4];

    int step = ((int)t/dt)+1;
    int Vb = rand_pl(1.5),Vs = rand_pl(1.5);
    double a;
    double price = 0.0;
    t = 0.0;
    for(int i=0;i < step;i++){
        a = uniform_random();
        if(a < dt*Intensity[0]){
            //LO
            Vs+=1;
        }
        else if(a<dt*Intensity[1]){
            //MO
            Vs-=1;
        }
        else if(a<dt*Intensity[2]){
            //CO
            Vs-=1;
        }
        else if(a<dt*Intensity[3]){
            //LO
            Vb+=1;
        }
        else if(a<dt*Intensity[4]){
            //CO
            Vb-=1;
        }
        else if(a<dt*Intensity[5]){
            //MO
            Vb-=1;
        }
                
        t+=dt;
        cout<<t<<","<<Vb<<","<<Vs<<","<<price<<endl;
        if(Vs==0){
            Vs=rand_pl(1.5);
            price+=1.0;
        }
        if(Vb==0){
            Vb=rand_pl(1.5);
            price-=1.0;
        }
    }
}

int main(int argc, char** argv){
    // dx/dt = c* x(t) + Poisson(lambda, h)
    double Intensity[6];
    Intensity[0] = stod(argv[1]);
    Intensity[1] = stod(argv[2]);
    Intensity[2] = stod(argv[3]);
    Intensity[3] = stod(argv[4]);
    Intensity[4] = stod(argv[5]);
    Intensity[5] = stod(argv[6]);
    double t = stod(argv[7]);
    JointQueueDynamics(Intensity,t);
}