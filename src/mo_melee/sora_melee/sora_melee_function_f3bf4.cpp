#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE078(s16* a, s32 b);

class Lst {
public:
    virtual void s0();
    virtual s32 get(s32 index);
    virtual void s2();
    virtual s32 count();
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
    virtual void apply(s32* p);
};

class Owner {
public:
    u8 pad[0x10];
    Lst lst;
};

extern "C" {
void fn_27_F3BF4(Owner* self, s16* flags, Sink* sink) {
    s32 n = self->lst.count();
    for (s32 i = 0; i < n; i++) {
        s16 sp8;
        fn_27_FE078(&sp8, self->lst.get(i));
        if (sp8 & *flags) {
            s32 item = self->lst.get(i);
            sink->apply(&item);
        }
    }
}
}
