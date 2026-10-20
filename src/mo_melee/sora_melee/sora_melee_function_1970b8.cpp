#include <types.h>
#pragma force_active on

class wnPikminPikmin;

struct soArrayListElem {
    u32 a;
    u32 b;
    u32 c;
};

template <typename T, int N>
class soArrayList {
public:
    virtual void vfunc2() const;
    virtual void vfunc3() const;
    virtual void vfunc4() const;
    virtual void vfunc5() const;
    virtual u32 isBusy() const;
    virtual void vfunc7() const;
    virtual void vfunc8() const;
    virtual void vfunc9() const;
    virtual void vfunc10() const;
    virtual void vfunc11() const;
    virtual void vfunc12() const;
    virtual void vfunc13() const;
    virtual void vfunc14() const;
    virtual void onOverflow() const;

    s32 getArrayIndex(s32 index) const;
    const soArrayListElem* at(s32 index) const;

private:
    s32 m_x;
    s32 m_y;
    soArrayListElem m_data[N];
};

template <typename T, int N>
const soArrayListElem* soArrayList<T, N>::at(s32 index) const {
    s32 idx = getArrayIndex(index);
    if (isBusy() != 1 && idx >= 0) {
        onOverflow();
    }
    return &m_data[idx];
}

template class soArrayList<wnPikminPikmin*, 10>;
