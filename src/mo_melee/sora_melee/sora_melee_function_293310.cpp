#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE000(s16* dest, s16* src);

class B {
public:
    virtual void s0();
    virtual void* get(s32 index);
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
    virtual void apply(void** p);
};

extern "C" {
void fn_27_293310(u8* self, s16* flag, Sink* sink) {
    s32 n = ((B*)(self + 0x10))->count();
    for (s32 i = 0; i < n; i++) {
        s16 tmp;
        fn_27_FE000(&tmp, (s16*)((B*)(self + 0x10))->get(i));
        if (tmp & *flag) {
            void* p = ((B*)(self + 0x10))->get(i);
            sink->apply(&p);
        }
    }
}
}
