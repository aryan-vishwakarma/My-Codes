#include<iostream>
using namespace std;
class abc
{
    public:
    int a;
    abc(int t){
        a=t;
    }
    abc(abc &t){
        a=t.a;
        cout<<a<<endl;
    }
    ~abc(){
        cout<<"Hey..."<<endl;
    }
};
void doo(){
    static abc p(10);
}
int main()
{
    doo();
}