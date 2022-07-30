#include"apaddition.h"

/* do arbitary_precision addition */
std::string apadd( std::string __NUM1, std::string __NUM2 , const uint8_t __digit = 1 ){
    int __NUM1_len = __NUM1.length();
    int __NUM2_len = __NUM2.length();
    long long _CalcBit_Max = pow( 10 , __digit ) - 1;
    long long _CalcBit_Min = pow( 10 , __digit - 1 );
    // this two vars show the interval of each calculation bit

    long long __NUM1_ClacBit_TempArray[__NUM1_len/__digit+2];
    long long __NUM2_ClacBit_TempArray[__NUM2_len/__digit+2];
    std::string _CalcBit_String_temp;
    std::stringstream _CalcBit_TypeChange_Temp;
    long long _CalcBit_Int_Temp;

    for ( int i = 1 ; i <= __NUM1_len / __digit ; i++ )
    {
        _CalcBit_String_temp = __NUM1.substr( __NUM1.length() - __digit );
        __NUM1.erase( __NUM1.length() - __digit );
        // copy the last part to temp string and delete that part
        _CalcBit_TypeChange_Temp << _CalcBit_String_temp;
        _CalcBit_TypeChange_Temp >> _CalcBit_Int_Temp;
        // use stringstream to change that calc part from string to int
        __NUM1_ClacBit_TempArray[i] = _CalcBit_Int_Temp;
        _CalcBit_TypeChange_Temp.clear();
        _CalcBit_String_temp.clear();
        _CalcBit_Int_Temp = 0;
        // reset all
    }
    if ( __NUM1_len % __digit == 0 )
    {
        __NUM1_ClacBit_TempArray[__NUM1_len/__digit+1] = -1;
        // set a sign that the last calc bit is empty
    }
    else
    {
        _CalcBit_TypeChange_Temp << __NUM1;
        _CalcBit_TypeChange_Temp >> _CalcBit_Int_Temp;
        __NUM1_ClacBit_TempArray[__NUM1_len/__digit+1] = _CalcBit_Int_Temp;
    }
    _CalcBit_TypeChange_Temp.clear();
    _CalcBit_String_temp.clear();
    _CalcBit_Int_Temp = 0;
    // reset all

    for ( int i = 1 ; i <= __NUM2_len / __digit ; i++ )
    {
        _CalcBit_String_temp = __NUM2.substr( __NUM2.length() - __digit );
        __NUM2.erase( __NUM2.length() - __digit );
        // copy the last part to temp string and delete that part
        _CalcBit_TypeChange_Temp << _CalcBit_String_temp;
        _CalcBit_TypeChange_Temp >> _CalcBit_Int_Temp;
        // use stringstream to change that calc part from string to int
        __NUM2_ClacBit_TempArray[i] = _CalcBit_Int_Temp;
        _CalcBit_TypeChange_Temp.clear();
        _CalcBit_String_temp.clear();
        _CalcBit_Int_Temp = 0;
        // reset all
    }
    if ( __NUM2_len % __digit == 0 )
    {
        __NUM2_ClacBit_TempArray[__NUM2_len/__digit+1] = -1;
        // set a sign that the last calc bit is empty
    }
    else
    {
        _CalcBit_TypeChange_Temp << __NUM2;
        _CalcBit_TypeChange_Temp >> _CalcBit_Int_Temp;
        __NUM2_ClacBit_TempArray[__NUM2_len/__digit+1] = _CalcBit_Int_Temp;
    }
    _CalcBit_TypeChange_Temp.clear();
    _CalcBit_String_temp.clear();
    _CalcBit_Int_Temp = 0;
    // reset all

    std::stack <CLACBIT> _Calcbit_Cache;

    for ( int i = 1 ; i <= std::max( __NUM1_len / __digit + 1 , __NUM2_len / __digit + 1 ) ; i++ )
    {
        CLACBIT _CLACBITTEMP;
        ( ( __NUM1_len / __digit + 1 ) <= i ) ? _CLACBITTEMP._NUM1 = __NUM1_ClacBit_TempArray[i] : _CLACBITTEMP._NUM1 = 0;
        ( ( __NUM2_len / __digit + 1 ) <= i ) ? _CLACBITTEMP._NUM2 = __NUM2_ClacBit_TempArray[i] : _CLACBITTEMP._NUM2 = 0;
        _CLACBITTEMP._BitANS = _CLACBITTEMP._NUM1 + _CLACBITTEMP._NUM2;
        _Calcbit_Cache.push( _CLACBITTEMP );
    }

    long long _ANS_Cache;
    std::stack <std::string> _ANS_STACK;
    bool _Carry_Necessary = false;
    while ( _Calcbit_Cache.size() )
    {
        _ANS_Cache = _Calcbit_Cache.top()._BitANS;
        if ( _Carry_Necessary )
        {
            _ANS_Cache++;
        }
        _Carry_Necessary = false;
        if ( !INTER( _ANS_Cache , _CalcBit_Min , _CalcBit_Max ) )
        {
            _Carry_Necessary = true;
            _ANS_Cache -= pow( 10 , __digit );
        }
        _ANS_STACK.push( std::to_string( _ANS_Cache ) );
    }
}