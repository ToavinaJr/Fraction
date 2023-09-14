#include "fraction.hpp"
#include <algorithm>
#include <iostream>

namespace Jr
{
    /**********************************************/

    Fraction::Fraction(const int& num, const int& den) {
        setNumerator(num);
        if ( den != 0) {
            setDenominator(den);
        }
        else {
            std::cerr << "Denominator can not be zero " << std::endl;
            exit(EXIT_FAILURE);
        }
        simplify();
    }

    /**********************************************/

    const int  Fraction::getNumerator()const{
        return numerator;
    }

    /**********************************************/

    const int  Fraction::getDenominator()const{
        return denominator;
    }

    /**********************************************/

    void Fraction::setNumerator(const int& num) {
        numerator = num;
    }

    /**********************************************/

    void Fraction::setDenominator(const int& den) {
        denominator = den;
    }

    /**********************************************/

    void Fraction::simplify() {
        int gcd = std::__gcd(numerator, denominator);
        setNumerator( numerator / gcd );
        setDenominator( denominator / gcd);
    }

    /**********************************************/

    Fraction Fraction::getInverse()const{
        if( getNumerator() != 0)
            return Fraction(getDenominator(), getNumerator());
        else {
            std::cerr << "This is an inversible fraction " << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    /**********************************************/
    
    Fraction operator+(const Fraction& a, const Fraction& b) {
        return Fraction(a.getNumerator() * b.getDenominator()+b.getNumerator()*a.getDenominator(),
                        a.getDenominator() * b.getDenominator());
    }

    /**********************************************/
    
    Fraction operator-(const Fraction& a, const Fraction& b) {
        return Fraction(a.getNumerator() * b.getDenominator() - b.getNumerator()*a.getDenominator(),
                        a.getDenominator() * b.getDenominator());
    }

    /**********************************************/
    
    Fraction operator*(const Fraction& a, const Fraction& b) {
        return Fraction(a.getNumerator() * b.getNumerator(),
                        a.getDenominator() * b.getDenominator());
    }

    /**********************************************/
    
    Fraction operator/(const Fraction& a, const Fraction& b) {
        return Fraction(a.getNumerator() * b.getDenominator(),
                        a.getDenominator() * b.getNumerator());
    }    

    /**********************************************/
    
    void operator<< (std::ostream& out,const Fraction& a) {
        if (a.getNumerator()==0){
            out << 0;
        }
        else {
            if (a.getDenominator() != 0) {
                if ( a.getDenominator() == 1)
                    out << a.getNumerator();
                else
                    out << a.getNumerator() << " / " << a.getDenominator() ;
            }
        }
    }

    /**********************************************/

    void operator>> (std::istream& in, Fraction& a) {
        int temp;
        std::cout << "Put the numerator : ";
        in >> temp;
        a.setNumerator(temp);

        do {
            std::cout << "Put the denominator (The denominator can not be zero) : ";
            in >> temp;
            a.setDenominator(temp);
        }while (temp == 0);
        
    }

    /**********************************************/
}