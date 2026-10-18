#pragma force_active on
struct Interface {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual int s6(int) = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual void s15() = 0;
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual int s19(int) = 0;
};

typedef unsigned int U32;
typedef char* P;

extern "C" int fn_96_E090(void* self) {
    Interface* a = (Interface*)(*(U32*)(*(U32*)(*(U32*)(P(self) + 0x60) + 0xD8) + 0x64));
    if (a->s19(0x12000042) == 0)
        return -1;
    Interface* b = (Interface*)(*(U32*)(*(U32*)(*(U32*)(P(self) + 0x60) + 0xD8) + 0x64));
    return b->s6(0x10000049);
}
