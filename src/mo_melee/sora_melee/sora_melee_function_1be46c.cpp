#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE140(short* dest, short* src);

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Visitor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void apply(void** p);
};

class Outer {
public:
    virtual void v0();
    u8 m_pad[0xC];
    Inner inner;
};

extern "C" {
void fn_27_1BE46C(Outer* self, short* mask, Visitor* visitor) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        short bits;
        fn_27_FE140(&bits, (short*)self->inner.get(i));
        if (bits & *mask) {
            void* p = self->inner.get(i);
            visitor->apply(&p);
        }
    }
}
}
