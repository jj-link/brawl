#include <types.h>
#pragma force_active on

class Member {
public:
    virtual void v0();
    virtual void* getItem(s32 index);
    virtual void v2();
    virtual s32 getCount();
};

class Sink {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void apply(void** p);
};

class Owner {
public:
    u8 pad[0x10];
    Member mem;
};

extern "C" void fn_27_714A4(s16* out, const void* src);

extern "C" {
void fn_27_31954C(Owner* self, s16* mask, Sink* sink) {
    s32 n = self->mem.getCount();
    for (s32 i = 0; i < n; i++) {
        s16 tmp;
        fn_27_714A4(&tmp, self->mem.getItem(i));
        if (tmp & *mask) {
            void* p = self->mem.getItem(i);
            sink->apply(&p);
        }
    }
}
}
