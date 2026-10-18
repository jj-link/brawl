#include <types.h>
#pragma force_active on

class VObj {
public:
    virtual void v0(u32, u32);
    virtual void v1(u32, u32);
    virtual void v2(u32, u32);
    virtual void v3(u32, u32);
    virtual void v4(u32, u32);
    virtual void v5(u32, u32);
    virtual void v6(u32, u32);
    virtual void v7(u32, u32);
    virtual void v8(u32, u32);
    virtual void v9(u32, u32);
    virtual void v10(u32, u32);
    virtual void v11(u32, u32);
    virtual void v12(u32, u32);
    virtual void v13(u32, u32);
};

extern "C" u32 getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);

extern "C" void fn_27_192438(void*, void* self) {
    u8* s = reinterpret_cast<u8*>(self);
    VObj* obj = *reinterpret_cast<VObj**>(*reinterpret_cast<u8**>(s + 0xd8) + 0x40);
    obj->v10(0, 0);
    VObj* obj2 = *reinterpret_cast<VObj**>(*reinterpret_cast<u8**>(s + 0xd8) + 0x20);
    u32 c = getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xA803, 0);
    obj2->v13(c, 0);
}
