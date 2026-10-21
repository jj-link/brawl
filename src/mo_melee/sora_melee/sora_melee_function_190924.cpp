#include <types.h>
#pragma force_active on

class fnA {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18(u32 a) = 0;
    virtual void v19(u32 a) = 0;
};

class fnS {
public:
    u32 pad0;
    u32 pad1;
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
};

extern "C" void fn_27_190924(void* unused, u8* p) {
    fnA* inner = *(fnA**)(*(u8**)(p + 0xd8) + 0x64);
    inner->v18(0x12000001);
    inner->v19(0x12000019);
    inner->v19(0x1200001a);
    fnS* sub = *(fnS**)(*(u8**)(p + 0xd8) + 0x9c);
    sub->s6();
}
