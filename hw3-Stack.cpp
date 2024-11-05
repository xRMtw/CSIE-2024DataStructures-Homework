#include<bits/stdc++.h>

using namespace std;

template<class T>
class Stack {
    private:

       stack<T> s;
       int num; 

    public:

        Stack() {}
        int size() const {}
        bool empty() const {}
        const T &top() const throw( StackEmpty ) {}
        void push( const T&e ) {}
        void pull() throw( StackEmpty ) {}
        
};