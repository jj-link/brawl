#include <types.h>
#pragma force_active on

struct wnPikminPikmin;

template <typename ElementTy, typename IndexTy>
struct soArrayListEnumerator {
    void* _vptr;
    s32 _isNull;
    void* m_units;
    s32 m_next;
    s32 getNext() const { return m_next; }
};

template <typename T, s32 C>
class soArrayList {
public:
    void eraseSub(s32 idx);
    void erase(const soArrayListEnumerator<T, signed char>& enm);
};

template <typename T, s32 C>
void soArrayList<T, C>::erase(const soArrayListEnumerator<T, signed char>& enm) {
    eraseSub(enm.getNext());
}

template void soArrayList<wnPikminPikmin*, 10>::erase(const soArrayListEnumerator<wnPikminPikmin*, signed char>&);
