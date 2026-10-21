#include <types.h>
#pragma force_active on

class acCmdInterpreterStackData;

template <typename T, int N>
class soArrayVector {
public:
    int getTopIndex() const;
};

template <typename T, int N>
int soArrayVector<T, N>::getTopIndex() const {
    return *(const int*)((const char*)this + 8) >> 30;
}

template class soArrayVector<acCmdInterpreterStackData, 1>;
