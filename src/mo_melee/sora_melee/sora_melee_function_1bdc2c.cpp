#include <types.h>
#pragma force_active on

class B {
public:
    virtual void s0() = 0;
    virtual void* get(s32 index) = 0;
    virtual void s2() = 0;
    virtual s32 count() = 0;
};

class Sink {
public:
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void apply(void** p) = 0;
};

extern "C" {
void fn_27_1BDC2C(u8* self, Sink* sink) {
    s32 n = ((B*)(self + 0x10))->count();
    for (s32 i = 0; i < n; i++) {
        void* p = ((B*)(self + 0x10))->get(i);
        sink->apply(&p);
    }
}
}
