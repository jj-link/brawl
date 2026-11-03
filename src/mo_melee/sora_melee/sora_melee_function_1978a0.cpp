#include <types.h>
#pragma force_active on
class wnPikminPikmin;
template <typename T> struct Unit {
    u8 flags;
    T element;
    s8 prev;
    s8 next;
};
template <typename T, int N> class soArrayList {
    u32 vtable;
    signed int freeIndex : 5;
    signed int topIndex : 5;
    signed int lastIndex : 5;
    signed int size : 5;
    Unit<T> units[N];
public:
    s32 getArrayIndex(s32) const;
    s32 shiftFreeArrayIndex(s32);
    s32 insertSub(s32, s32);
};
template <typename T, int N>
s32 soArrayList<T,N>::insertSub(s32 pos, s32 where) {
    s32 prev = -1;
    if (pos >= 0) {
        prev = getArrayIndex(pos);
        if (prev < 0) return -1;
    }
    s32 idx = shiftFreeArrayIndex(where);
    if (idx < 0) return -1;
    s32 next = -1;
    if (prev < 0) next = topIndex;
    else if (units[prev].next >= 0) next = units[prev].next;
    if (prev >= 0) units[prev].next = idx;
    else topIndex = idx;
    units[idx].prev = prev;
    if (next >= 0) units[next].prev = idx;
    else lastIndex = idx;
    units[idx].next = next;
    units[idx].flags |= 0x80;
    return idx;
}
template s32 soArrayList<wnPikminPikmin*,10>::insertSub(s32,s32);
