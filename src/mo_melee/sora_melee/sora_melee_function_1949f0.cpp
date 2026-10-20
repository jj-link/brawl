#include <types.h>
#pragma force_active on

extern "C" float fn_27_194828(u32 p, u32 a, u32 b, u32 c);
extern void* g_ftManager;

class VirtFloatGetter {
public:
    virtual float m0();
    virtual float m1();
    virtual float m2();
    virtual float m3();
    virtual float m4();
    virtual float m5();
    virtual float m6();
    virtual float m7();
    virtual float m8();
    virtual float m9();
    virtual float m10();
    virtual float m11();
    virtual float m12();
    virtual float m13();
    virtual float getFloat();
};

extern "C" float fn_27_1949F0(u32 p) {
    u32 ptr1 = *(u32*)(p + 0xd8);
    u32 ptr2 = *(u32*)(ptr1 + 0xc4);
    VirtFloatGetter* obj = (VirtFloatGetter*)ptr2;
    float f = obj->getFloat();
    if (((u8*)g_ftManager)[0x68] == 1) {
        f *= fn_27_194828(p, 0xD25, 0xD27, 0xD26);
    }
    return f;
}
