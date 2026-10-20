#include <types.h>
#pragma force_active on

class fnBaseVtbl {
public:
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
};

class fnGetSrc : public fnBaseVtbl {
public:
    virtual u32* getSrc() = 0;
};

class fnGetDst : public fnBaseVtbl {
public:
    virtual u32* getDst(void* arg) = 0;
};

extern "C" {
void fn_27_DC380(void* self, void* unused, void* arg) {
    u32* src = ((fnGetSrc*)self)->getSrc();
    u32* dst = ((fnGetDst*)self)->getDst(arg);
    *dst = *src;
}
}
