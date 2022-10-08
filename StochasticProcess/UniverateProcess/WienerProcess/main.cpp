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
double uniform_random_gauss(double mu, double sigma){
    std::normal_distribution<> dist(mu, sigma);
    return  dist(engine);
}

void Wiener(double c, double sigma, double t){
    double dt = (0.01)*max(1/abs(sigma), 1/c);
    double sqt = sqrt(dt);
    int step = ((int)t/dt)+1;
    double a = 0.,x0=1.0;
    t = 0.0;
    for(int i=0;i < step;i++){
        a = uniform_random_gauss(0.,1.);
        x0 = x0 +c*(x0)*dt + sqt*a*sigma;
        t+=dt;
        cout<<t<<","<<x0<<endl;
    }
}

int main(int argc, char** argv){
    // dx/dt = c* x(t) + Poisson(lambda, h)
    double c = stod(argv[1]);
    double sigma = stod(argv[2]);
    double t = stod(argv[3]);
    
    Wiener(c,sigma,t);
}