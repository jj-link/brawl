#include <types.h>
#pragma force_active on

extern "C" void fn_8011097C(void*);
extern "C" void fn_80110CEC(void*);

struct Sub {
    u8 pad[0x2C];
    u8 flags;
};

struct Self {
    u8 pad0[8];

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
    virtual void v13();
    virtual void v14();
    virtual void action();

    u8 pad1[0x20];
    s32 state;
    Sub* sub;
    u8 pad2[4];
    u8 flags;
};

extern "C" void fn_27_25D80(Self* self) {
    if (self->state == 0 || self->sub == 0)
        return;

    Sub* c = self->sub;
    if ((self->flags >> 4) & 1) {
        if (!((c->flags >> 7) & 1))
            fn_8011097C(c);
    }

    Sub* d = self->sub;
    if ((d->flags >> 7) & 1) {
        if (!((d->flags >> 2) & 1)) {
            self->action();
            fn_80110CEC(self->sub);
        }
    }
}
