#pragma once 
#include <iostream>

namespace Jr
{
    class Fraction
    {            
        public :
            Fraction(const int& num=0, const int& den=1);
            void simplify();
            const int getDenominator()const;
            const int getNumerator()const;
            void setDenominator(const int& );
            void setNumerator(const int& );
            Fraction getInverse()const;

            friend Fraction operator+(const Fraction&, const Fraction& );
            friend Fraction operator-(const Fraction&, const Fraction& );
            friend Fraction operator*(const Fraction&, const Fraction& );
            friend Fraction operator/(const Fraction&, const Fraction& );
            friend void operator<< (std::ostream& out, const Fraction& );
            friend void operator>> (std::istream& in, Fraction& );

        private:
            int numerator;
            int denominator;

    };        
}