#include <types.h>
#pragma force_active on

class soCommonDataAccesser {
public:
    float getParamCommonFloat(u32, u32);
};

class fnTarget {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual float vf17(void*, s32);
};

extern soCommonDataAccesser g_soCommonDataAccesser;
extern s32 lbl_27_bss_1B18;

extern "C" float fn_27_8C02C(void* p1, void* p2, s32 p3) {
    switch (p3) {
    case 0x7d0: {
        fnTarget* obj = *(fnTarget**)(*(char**)((char*)p2 + 0xd8) + 0x8);
        return obj->vf17(p2, p3);
    }
    default:
        return g_soCommonDataAccesser.getParamCommonFloat(lbl_27_bss_1B18, p3);
    }
}
