#include <types.h>
#pragma force_active on

extern "C" void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);

class soVirtObj {
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
    virtual void slot13(float f, u32 v);
};

extern "C" void fn_27_18A6E4(void* unused, void* self) {
    void* c = getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xA80E, 0);
    float f = *(float*)((u8*)c + 4);
    soVirtObj* inner = *(soVirtObj**)(*(u8**)((u8*)self + 0xd8) + 0x64);
    inner->slot13(f, 0x21000004);
}
