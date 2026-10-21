#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE028(s16* dst, const s16* src);

class Member {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
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
    virtual void apply(void** p);
};

class Outer {
public:
    virtual void v0();
    u8 pad[0x10 - 4];
    Member mem;
};

extern "C" {
void fn_27_F1E48(Outer* self, s16* mask, Sink* sink) {
    s32 n = self->mem.count();
    for (s32 i = 0; i < n; i++) {
        s16 v;
        fn_27_FE028(&v, (const s16*)self->mem.get(i));
        if (v & *mask) {
            void* p = self->mem.get(i);
            sink->apply(&p);
        }
    }
}
}
