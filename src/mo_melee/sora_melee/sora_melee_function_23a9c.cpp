#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 size();
};

class Owner {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void work(s32 index);

    u8 pad[0x58];
    Inner* m_inner;
};

extern "C" {
void fn_27_23A9C(Owner* self) {
    s32 n = self->m_inner->size();
    for (s32 i = 0; i < n; i++) {
        self->work(i);
    }
}
}
