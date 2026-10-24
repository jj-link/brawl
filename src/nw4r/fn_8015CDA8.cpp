#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
extern char lbl_804645A8[];
void fn_8015CCA8(void*, s32, s32);
s32 fn_801F6210(void*, void*);
}

struct Obj {
    void* vtbl;
    u8 flag4;
    u8 pad5[3];
    u32 x8, xC, x10, x14, x18, x1C, x20;
    u8 x24;
    u8 pad25[3];
    u8 pad28[0x34];
    u32 x5C, x60;
    Obj* x64;
    u32 x68;
    u8 x6C, x6D, x6E;
};

extern "C" Obj* fn_8015CDA8(Obj* self, void* arg) {
    self->x6C = 0;
    self->vtbl = lbl_804645A8;
    self->x14 = 0;
    self->x18 = 0;
    self->x6D = 0;
    self->x6E = 0;
    self->flag4 = 0;
    self->x68 = 2;
    self->xC = 0;
    self->x10 = 0;
    self->x8 = 0;
    self->x1C = 0;
    self->x24 = 0;
    self->x20 = 0;
    self->x64 = self;

    if (self->x14)
        ((void (*)(Obj*))self->x14)(self);

    if (fn_801F6210(arg, &self->pad28) != 0) {
        self->x14 = self->x5C;
        fn_8015CCA8(&self->x14, 0, 0);
        self->x6D = 1;
        self->x6E = 1;
        self->flag4 = 1;
    }

    return self;
}
