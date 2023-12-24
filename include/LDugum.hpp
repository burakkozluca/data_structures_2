#ifndef LDugum_hpp
#define LDugum_hpp

#include "AVLAgaci.hpp"

using namespace std;

class LDugum
{
public:
    LDugum(AVLAgaci agac);
    AVLAgaci agac;
    LDugum* sonraki;
    LDugum* onceki;
};

#endif