#include"apmath.h"

/* change one integer into string */
std::string DTchange( long long __Integer = 0LL ){
    std::string _ANT = "";
    while ( __Integer != 0 )
    {
        char _tc = ( char ) ( __Integer % 10 ) + 48;
        _ANT.insert( 0 , 1 , _tc );
        __Integer /= 10;
    }
    return _ANT;
}