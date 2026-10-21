#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE1B8(s16* out, const s16* in);

class Inner {
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

extern "C" {
void fn_27_FA8C0(u8* self, s16* mask, Sink* sink) {
    s32 n = ((Inner*)(self + 0x10))->count();
    for (s32 i = 0; i < n; i++) {
        s16 flags;
        fn_27_FE1B8(&flags, (const s16*)((Inner*)(self + 0x10))->get(i));
        if (flags & *mask) {
            void* p = ((Inner*)(self + 0x10))->get(i);
            sink->apply(&p);
        }
    }
}
}
