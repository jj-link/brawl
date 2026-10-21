#include <types.h>
#pragma force_active on

extern "C" void fn_27_C410C(void* p);
extern "C" void fn_27_C4160(void* p, int n);
extern "C" void fn_27_C41B0(void* p, u32 x);

class Coll {
public:
    virtual void v0() = 0;
    virtual u32* v1(int i) = 0;
    virtual void v2() = 0;
    virtual int v3() = 0;
};

class Sink {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10(void* p) = 0;
};

class Self {
public:
    u32 m_0;
    Sink* m_4;
};

extern "C" void fn_27_C3D08(Self* self, void* unused, Coll* coll) {
    unsigned char sp8[0x60];
    if (self->m_4 != 0) {
        fn_27_C410C(sp8);
        int i = 0;
        while (i < coll->v3()) {
            fn_27_C41B0(sp8, *coll->v1(i));
            i++;
        }
        self->m_4->v10(sp8);
        fn_27_C4160(sp8, -1);
    }
}
