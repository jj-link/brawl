#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_20E4;

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setA(u32 a, float b);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void setB(u32 a);
};

struct Sub {
    char pad[0x64];
    Inner* inner;
};

struct Arg {
    char pad[0xd8];
    Sub* sub;
};

extern "C" void fn_27_169ECC(void*, Arg* p) {
    p->sub->inner->setA(0x11000000, lbl_27_rodata_20E4);
    p->sub->inner->setB(0x12000003);
}
