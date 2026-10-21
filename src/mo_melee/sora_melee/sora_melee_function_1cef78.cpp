#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void s0() = 0;
    virtual s16* get(s32 index) = 0;
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
    virtual void apply(s16** p) = 0;
};

extern "C" void fn_27_FE168(s16* dst, s16* src);

extern "C" {
void fn_27_1CEF78(u8* self, s16* arg1, Sink* sink) {
    s32 n = ((Inner*)(self + 0x10))->count();
    s16 sp8;
    s16* spC;
    for (s32 i = 0; i < n; i++) {
        s16* p = ((Inner*)(self + 0x10))->get(i);
        fn_27_FE168(&sp8, p);
        if (sp8 & *arg1) {
            spC = ((Inner*)(self + 0x10))->get(i);
            sink->apply(&spC);
        }
    }
}
}
