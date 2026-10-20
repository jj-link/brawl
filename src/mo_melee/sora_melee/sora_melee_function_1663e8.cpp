#include <types.h>
#pragma force_active on

struct Sub {
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
    virtual float get(u32 id);
    virtual void set(u32 id, float v);
};

extern "C" int fn_27_1663E8(void* unused, u8* self) {
    u32 id = 0x21000005;
    Sub* s1 = *(Sub**)(*(u8**)(self + 0xd8) + 0x64);
    float f = -s1->get(id);
    Sub* s2 = *(Sub**)(*(u8**)(self + 0xd8) + 0x64);
    s2->set(id, f);
    return 0;
}
