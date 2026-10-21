#include <types.h>
#pragma force_active on

struct Handler {
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
    virtual void v11(void*, void*);
    virtual void v12();
    virtual void v13(void*);
    u8 pad[0xe0];
    void* data;
};

struct Aux {
    u8 pad[0x1dc];
    s32 value;
};

struct Self {
    u8 pad0[0x40];
    Handler* obj;
    void* ctx;
    u8 pad1[0x54];
    Aux* aux;
    u32 unused;
    u32 count;
    u8 pad2[0x28];
    u8 result;
    u8 pad3[0xb];
    u8 flag;
};

extern "C" void fn_10_1A408();

extern "C" void fn_10_19E3C(Self* self) {
    s32 value = self->aux->value;
    u8 result;

    if (value >= 0) {
        if (self->count <= 3 && value >= 0)
            result = 1;
        else
            result = 0;
    } else {
        fn_10_1A408();
        result = 0;
    }

    self->obj->v13(self->ctx);

    if (result != 0 && self->flag == 0)
        self->obj->v11(self->obj->data, self->ctx);

    self->result = result;
}
