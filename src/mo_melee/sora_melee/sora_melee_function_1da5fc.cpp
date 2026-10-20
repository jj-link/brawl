#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4();
};

extern "C" s32 fn_27_1DA5FC(u8* self) {
    u8* a = *(u8**)(self + 0x60);
    u8* b = *(u8**)(a + 0xD8);
    fn27Obj* c = *(fn27Obj**)(b + 0x54);
    return c->v4();
}
