#include<bits/stdc++.h>
using namespace std;

class Newton{
private:
    double x,next,tol,a,b;
    double f(double x){
        // return x*x*x-2*x-5;
        return x*sin(x)+cos(x);
    }
    double fp(double x){
        return x*cos(x); 
        // return 3*x*x-2;
    }
    void genRandom(){
        srand((time(0)));
        do{
            a = (rand()%100-50)/10.0;
            b = (rand()%100-50)/10.0;

        }
        while(f(a)*f(b)>=0);
        if(f(a)>f(b))swap(a,b);
        if(abs(f(a)-0)<abs(f(b)-0))x = a;
        else x = b;
    } 
public:
    Newton(double x, double tol){
        this->x = x;
        this->tol = tol;
        // genRandom();
       
    }
    double root(){
        next = x-(f(x)/fp(x));
        while(abs(f(next))>tol){
            x = next;
            next = x-(f(x)/fp(x));
            
        }
        return next;
    }
};

int main(){
    Newton naughty = Newton(3.1416,0.001);
    // Newton naughty = Newton(0.0.001);  //2.09
    cout<<naughty.root();
}
// class newton{
// private: 
//     double xx,tol;
//     double f(double x){
//         // return x*x*x-2*x-5;
//         return x*sin(x)+cos(x);
//     }
//     double fp(double x){
//         // return 3*x*x-2;
//         return x*cos(x);
//     }
//     double next(double x){
//         return x-(f(x)/fp(x));
//     }
// public:
//     newton(double tol){
//         this->tol = tol;
//         xx =3.1416;
//     }
//     double root(){
//         double x1 = next(xx);
//         int i =2;
//         while(abs(x1-xx)>tol){
//             cout<<x1<<" ";
//             xx = x1;
//             x1 = next(xx);
//         }
//         return x1;
//     }
// };
// int main(){
//     newton nt = newton(0.001);
//     cout<<nt.root();
//     return 0;
// }