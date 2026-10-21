#include <types.h>
#pragma force_active on

extern "C" void fn_27_10EB4C(s16* dest, const void* src);

class Member {
public:
    virtual void v2();
    virtual void* get(s32 index);
    virtual void v4();
    virtual s32 count();
};

class Sink {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void apply(void** p);
};

class Owner {
public:
    u8 pad[0x10];
    Member mem;
};

extern "C" {
void fn_27_10E530(Owner* self, s16* mask, Sink* sink) {
    s32 n = self->mem.count();
    for (s32 i = 0; i < n; i++) {
        s16 flag;
        fn_27_10EB4C(&flag, self->mem.get(i));
        if (flag & *mask) {
            void* p = self->mem.get(i);
            sink->apply(&p);
        }
    }
}
}
