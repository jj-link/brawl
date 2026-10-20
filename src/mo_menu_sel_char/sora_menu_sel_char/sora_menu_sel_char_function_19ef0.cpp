#include <types.h>
#pragma force_active on

class MenuChar {
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
    virtual void v11(u32 a, void* b);
    virtual void v12();
    virtual void v13(void* a);
    u8 _pad[0xE0];
    u32 data;
};

struct MenuSelChar {
    u8 _pad1[0x40];
    MenuChar* obj;
    void* ctx;
    u8 _pad2[0x88];
    u8 state;
    u8 _pad3[0xB];
    u8 active;
};

extern "C" void fn_10_19EF0(MenuSelChar* self, u8 val) {
    self->active = val;
    u8 saved = self->state;
    self->obj->v13(self->ctx);
    if (saved != 0 && self->active == 0) {
        self->obj->v11(self->obj->data, self->ctx);
    }
    self->state = saved;
}
