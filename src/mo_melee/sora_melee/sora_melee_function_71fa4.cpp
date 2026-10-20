#include <types.h>
#pragma force_active on

struct Field {
    s32 m_0;
    s32 m_4;
};

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual Field* getField(s32 idx);
    virtual void vf23();
    virtual s32 getIndex();
};

class Outer {
public:
    u8 m_00[0x20];
    Inner* m_20;
};

extern "C" void fn_27_71FA4(Outer* self, s32 unused, s32 value) {
    Field* f;
    s32 idx = self->m_20->getIndex();
    if (idx < 0) {
        f = 0;
    } else {
        f = self->m_20->getField(idx);
    }
    if (f != 0) {
        f->m_4 = value;
    }
}
