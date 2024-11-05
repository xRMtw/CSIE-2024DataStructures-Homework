#include<bits/stdc++.h>

using namespace std;

class A {
    public:
        virtual void setX ( int a ) { x = a; }
        int getX ()  { return x; }

    protected:
        int x;
};

class B : public A {
    public:

    protected:
        int x;
};

class C : public B {

    public:
        virtual void setX ( int a ) {
            A::setX ( a );
        }

    protected:
        int x;
};

int main () {

    C c;
    int n;
    cin >> n;
    c.setX( n );
    cout << c.getX();
    
}

