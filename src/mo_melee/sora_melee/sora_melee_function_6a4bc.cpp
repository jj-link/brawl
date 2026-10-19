#include <types.h>
#pragma force_active on

extern u8 lbl_27_bss_110[0x10];
extern "C" void fn_27_6F380(void* a, void* b);

class So {
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
    u8 pad[0x28];
    void* member;
};

extern "C" void fn_27_6A4BC(So* self) {
    fn_27_6F380(lbl_27_bss_110, &self->member);
    self->v5();
    self->v7();
}
