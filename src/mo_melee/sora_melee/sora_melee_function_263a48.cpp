#include <types.h>
#pragma force_active on

class fnInner {
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
    virtual void v10(u32 arg);
};

extern "C" {
void fn_27_263A48(u8* self, u32 arg) {
    if (arg == 1) {
        u8* a = *(u8**)(self + 0x180);
        fnInner* b = *(fnInner**)(a + 0x90);
        b->v10(0);
    } else {
        u8* a = *(u8**)(self + 0x180);
        fnInner* b = *(fnInner**)(a + 0x90);
        b->v10(1);
    }
}
}
