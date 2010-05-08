#include<iostream>
#include<list>
using namespace std;

class Rational{/*{{{*/
    private:
        int p,q; // r=q/p
    public:
        static int test();
        Rational(){}
        int getP()const{return p;}
        int getQ()const{return q;}
        int setP(int P){p=P;}
        int setQ(int Q){q=Q;}
        Rational(int Q,int P){setP(P);setQ(Q);}
        int isInf(){return q==0;}
        int friend operator==(const Rational & A,const Rational & B);
        int friend operator!=(const Rational & A,const Rational & B);
        int friend operator>(const Rational & A,const Rational & B);
        int friend operator<=(const Rational & A,const Rational & B);
        int friend operator<(const Rational & A,const Rational & B);
        int friend operator>=(const Rational & A,const Rational & B);
};

int operator==(const Rational & A,const Rational &B){/*{{{*/
    return A.q*B.p==A.p*B.q;
}/*}}}*/

int operator!=(const Rational & A,const Rational & B){/*{{{*/
    return !(A==B);
}/*}}}*/

int operator>(const Rational & A, const Rational & B){/*{{{*/
    return A.q*B.p > A.p*B.q;
}/*}}}*/

int operator<=(const Rational & A, const Rational & B){/*{{{*/
    return !(A>B);
}/*}}}*/

int operator<(const Rational & A, const Rational & B){/*{{{*/
    return A.q*B.p < A.p*B.q;
}/*}}}*/

int operator>=(const Rational & A, const Rational & B){/*{{{*/
    return !(A<B);
}/*}}}*/

int Rational::test(){/*{{{*/
    cout<<"testing class Rational"<<endl;
    Rational A(2,3),B(4,5);
    if(A>=B){
        cout<<"error 1"<<endl;
        return 1;
    }
    if(A==B){
        cout<<"error 2"<<endl;
        return 2;
    }
    cout<<"all tests passed !"<<endl;
    return 0;
}/*}}}*//*}}}*/

class Vector{/*{{{*/
    private:
        int x,y;
    public:
        static int test();
        Vector(){}
        Vector(int X,int Y){x=X;y=Y;}
        int getX()const{return x;}
        void setX(int X){x=X;}
        int getY()const{return y;}
        void setY(int Y){y=Y;}
        Vector & operator+=(const Vector &rhs);
        Vector & operator-=(const Vector &rhs);
        friend const Vector operator+(const Vector &A,const Vector &B);
        friend const Vector operator-(const Vector &A,const Vector &B);
        friend const int dot(const Vector &A,const Vector &B);
        int squareOfNorm() const;
        friend const Rational squareOfCosine(const Vector & A, const Vector & B);
};

Vector & Vector::operator+=(const Vector &rhs){/*{{{*/
    x+=rhs.x;
    y+=rhs.y;
    return *this;
}/*}}}*/

Vector & Vector::operator-=(const Vector &rhs){/*{{{*/
    x-=rhs.x;
    y-=rhs.y;
    return *this;
}/*}}}*/

const Vector operator+(const Vector &A,const Vector &B){/*{{{*/
    Vector result=A;
    result+=B;
    return result;
}/*}}}*/

const Vector operator-(const Vector &A,const Vector &B){/*{{{*/
    Vector result=A;
    result-=B;
    return result;
}/*}}}*/

const int dot(const Vector &A,const Vector &B){/*{{{*/
    return A.x*B.x+A.y*B.y;
}/*}}}*/

int Vector::squareOfNorm() const {/*{{{*/
    return x*x+y*y;
}/*}}}*/ 

const Rational squareOfCosine(const Vector & A, const Vector & B){/*{{{*/
    return Rational(dot(A,B)*dot(A,B),A.squareOfNorm()*B.squareOfNorm());
}/*}}}*/

int Vector::test(){/*{{{*/
    cout<<"testing class Vector"<<endl;
    //test constructor
    Vector A(1,2);
    if(A.getX()!=1||A.getY()!=2){
        cout<<"error 1"<<endl;
        return 1;
    }
    //test setter
    A.setX(3);
    A.setY(4);
    if(A.getX()!=3||A.getY()!=4){
        cout<<"error 2"<<endl;
        return 1;
    }
    //test '+' operator
    A=Vector(3,4);
    Vector B=A,C;
    C=A+B;
    if(C.getX()!=6||C.getY()!=8){
        cout<<"error 3"<<endl;
        return 1;
    }
    //test '-' operator
    A=Vector(4,5);B=Vector(3,4);
    C=A-B;
    if(C.getX()!=1||C.getY()!=1){
        cout<<"error 4"<<endl;
        return 1;
    }
    //test function dot
    A=Vector(3,4);B=Vector(6,8);
    if(dot(A,B)!=3*6+4*8){
        cout<<"error 5"<<endl;
        return 1;
    }
    //test function squareOfNorm
    if(A.squareOfNorm()!=3*3+4*4){
        cout<<"error 6"<<endl;
        return 1;
    }

    //test function squareOfCosine
    A=Vector(2,3);
    B=Vector(5,6);
    if(squareOfCosine(A,B)!=Rational(28*28,13*61)){
        cout<<"error 7"<<endl;
        return 1;
    }

    cout<<"all tests passed !"<<endl;
    return 0;
}/*}}}*//*}}}*/

enum Power{off,on};

class Kingdom{
    private:
        list<Vector> sites;
        list<Vector> boundary;
        Power power;
    public:
        Kindom(){}
        
};


int main(){
    Rational::test();
    Vector::test();
    return 0;
}

// vim:fdm=marker
