#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;

extern "C" void fn_27_247D98(void*);
extern "C" float lbl_27_rodata_40C8;
extern "C" char lbl_27_data_4FA48[];

struct S {
    u8 pad0[0x2C];
    u8 flags;
    u8 pad1[0x0F];
    void* data;
    u8 unk40;
    u8 pad3[0x8B];
    float fcc;
    u8 pad4[4];
    u8 b[5];
    u32 dc;
    u32 e0;
    u32 e4;
    u32 e8;
    u32 ec;
    u32 f0;
    s8 f4;
    u8 pad5[3];
    u32 f8;
};

extern "C" void* fn_27_250F50(void* self) {
    S* s = static_cast<S*>(self);
    fn_27_247D98(self);
    u8 v = s->flags;
    v &= ~2;
    float f = lbl_27_rodata_40C8;
    s->data = lbl_27_data_4FA48;
    s->fcc = f;
    s->b[0] = 0;
    s->b[1] = 0;
    s->b[2] = 0;
    s->b[3] = 0;
    s->b[4] = 0;
    s->dc = 0x96;
    s->e0 = 0;
    s->e4 = 0x78;
    s->e8 = 0;
    s->ec = 0;
    s->f0 = 0xF0;
    s->f4 = -1;
    s->f8 = 0;
    s->unk40 = 0;
    s->flags = v;
    return self;
}
