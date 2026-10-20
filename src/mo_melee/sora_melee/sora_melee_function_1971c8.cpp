#include <types.h>
#pragma force_active on

class wnPikminPikmin;

template <class T, int N>
class soArrayList {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 size();
    s32 insertSub(s32 index, s32 len);
    void push(const T& value);
};

template <class T, int N>
void soArrayList<T, N>::push(const T& value) {
    s32 idx = insertSub(size() - 1, -1);
    if (idx >= 0) {
        *(T*)((char*)this + idx * 12 + 12) = value;
    }
}

template void soArrayList<wnPikminPikmin*, 10>::push(wnPikminPikmin* const& value);
