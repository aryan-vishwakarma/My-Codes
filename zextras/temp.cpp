#include <iostream>
using namespace std;
struct A
{
    int a, b;
};
ostream &operator<<(ostream &out, A &a)
{
    out << a.a << "\n"
        << a.b << "\n";
}
istream &operator>>(istream &in, A &a)
{
    in >> a.a >> a.b;
}
template <class T>
void disp(T a)
{
    cout << a;
}
template <class T>
void swapp(T &a, T &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
int main()
{
    cout << "Enter two numbers:\n";
    A a;
    cin >> a;
    disp(a);
    swapp(a.a, a.b);
    cout << a;
}