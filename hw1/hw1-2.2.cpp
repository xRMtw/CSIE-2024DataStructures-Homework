#include<bits/stdc++.h>

using namespace std;

class quadraticEq {
    public:
        quadraticEq () {
            a = 0;
            b = 0;
            c = 0;
        }

        int judgeRootNum () {
            double discriminant = b*b-4*a*c;

            if ( discriminant > 0 ) {
                return 1;
            }
            else if ( discriminant < 0 ) {
                return -1;
            }
            else {
                return 0;
            }
        }

        int geta () const { return a; }
        int getb () const { return b; }
        int getc () const { return c; }

        void CounttheAnswer () {

            double discriminant = b*b-4*a*c;
            double ans1 = 0 ,ans2 = 0;

            if ( judgeRootNum() == 1 ) {

                ans1 = ( -b + sqrt( discriminant ) ) / ( 2*a );
                ans2 = ( -b - sqrt( discriminant ) ) / ( 2*a );
                cout << "two real roots:" << ans1 << " " << ans2  << endl;
            
            }
            else if ( discriminant < 0 ) {

                cout << "two complex roots" << endl;
            
            }
            else {

                ans1 = ( -b + sqrt( discriminant ) ) / 2*a;
                cout << "single(repeated) roots:" << ans1 << endl;
            
            }
        }

        quadraticEq operator+ ( const quadraticEq &o ) {
            
            quadraticEq temp;

            temp.a = geta() + o.geta();
            temp.b = getb() + o.getb();
            temp.c = getc() + o.getc();

            return temp;
            
        }

        quadraticEq operator- ( const quadraticEq &o ) {
            
            quadraticEq temp;

            temp.a = geta() - o.geta();
            temp.b = getb() - o.getb();
            temp.c = getc() - o.getc();

            return temp;
        }

        bool operator== ( const quadraticEq &o ) {
            bool x ,y ,z;

            x = ( ( geta() == o.geta() )? 1 : 0 );
            y = ( ( getb() == o.getb() )? 1 : 0 );
            z = ( ( getc() == o.getc() )? 1 : 0 );

            return( x && y && z );
            
        }

        bool operator!= ( const quadraticEq &o ) {
            bool x ,y ,z;

            x = ( ( geta() != o.geta() )? 1 : 0 );
            y = ( ( getb() != o.getb() )? 1 : 0 );
            z = ( ( getc() != o.getc() )? 1 : 0 );

            return( x || y || z );
            
        }

        friend istream& operator>>( istream& in, quadraticEq& o ) {
            
            cout << "Enter coefficients a, b, and c:";
            in >> o.a >> o.b >> o.c;
            return in;
        }

        friend ostream& operator<<( ostream& out, const quadraticEq& o ) {
            
            if ( o.b < 0 && o.c < 0) {

                out << o.a << "x^2 " << o.b << "x  " << o.c << " = 0" << endl;
                return out;

            }
            else if ( o.b < 0 && o.c > 0 ) {

                out << o.a << "x^2 " << o.b << "x + " << o.c << " = 0" << endl;
                return out;

            }
            else if ( o.b > 0  && o.c < 0 ) {

                out << o.a << "x^2 + " << o.b << "x " << o.c << " = 0" << endl;
                return out;

            }
            else {

                out << o.a << "x^2 + " << o.b << "x + " << o.c << " = 0" << endl;
                return out;

            }

        }

    private:
        double a ,b ,c;
};

int main () {

    quadraticEq f ,g;

    cin >> f; 
    cin >> g;
    
    cout << f;
    f.CounttheAnswer();

    cout << endl;
    cout << g;
    g.CounttheAnswer();

    cout << endl;
    cout << ( f + g );
    ( f + g ).CounttheAnswer();

    cout << endl;
    cout << ( f - g );
    ( f - g ).CounttheAnswer();

}