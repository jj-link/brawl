#include <types.h>
#pragma force_active on

class wnPikminPikmin;

class soArrayListInner {
public:
    virtual void iv0();
    virtual void iv1();
    virtual void iv2();
    virtual void iv3();
    virtual u32 check();
    virtual void iv5();
    virtual void iv6();
    virtual void iv7();
    virtual void iv8();
    virtual void iv9();
    virtual void iv10();
    virtual void iv11();
    virtual void iv12();
    virtual void onOverflow();

    int x;
    int y;
};

class soArrayListBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 getArrayIndex(s32 index);
};

struct soArrayListElem {
    void* p;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

template <typename T, int N>
class soArrayList : public soArrayListBase {
public:
    int m_pad[3];
    soArrayListInner m_inner;
    soArrayListElem m_elems[N];
};

extern "C" soArrayListElem* fn_27_2BB560(soArrayListBase* self, s32 index);

extern "C" soArrayListElem* fn_27_2BB560(soArrayListBase* self, s32 index) {
    self->getArrayIndex(index);
    soArrayList<wnPikminPikmin*, 10>* list = (soArrayList<wnPikminPikmin*, 10>*)self;
    if (list->m_inner.check() != 1 && index >= 0) {
        list->m_inner.onOverflow();
    }
    return &list->m_elems[index];
}
