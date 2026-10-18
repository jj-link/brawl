#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct App {
    u8 pad[0xec];
    u32 flags;
};

extern "C" App* g_gfApplication;
extern "C" const float lbl_88_rodata_0[];

struct Obj {
    u8 p0[0x1d8];
    u8 mode;
    u8 p1[0x13];
    void* ptr;
    u8 p2[0xc];
    u8 state;
    u8 p3[3];
    float timer;
    float x204;
    float x208;
    u8 p4[0x18];
    float x224;
    u8 p5[0x20];
    float x248;
    float x24c;
    u8 p6[0x1c];
    float x26c;
    float x270;
    u8 p7[0xc];
    float x280;
    float x284;
    u8 p8[0xc];
    float x294;
    float x298;
    u8 p9[4];
    u8 active;
};

extern "C" void fn_88_26DC(Obj* o, float dt) {
    const float* c = lbl_88_rodata_0;

    if (g_gfApplication->flags >> 27)
        return;

    o->timer -= dt;
    if (c[0] == o->timer)
        o->timer = c[0];

    if (!o->ptr)
        return;
    if (!((*((u8*)o->ptr + 0x2c) >> 6) & 1))
        return;
    if (o->active != 1)
        return;

    switch ((int)o->state) {
    case 0:
        break;

    case 1:
        o->x248 = c[0];
        o->x24c = c[5];
        o->x294 = c[0];
        o->x298 = c[5];
        o->x280 = c[0];
        o->x284 = c[5];
        o->x26c = c[0];
        o->x270 = c[23];
        break;

    case 2:
        if (o->mode != 6 && o->mode != 7 && o->mode != 8 &&
            o->mode != 9 && o->mode != 10) {
            o->x248 = c[0];
            o->x24c = c[24];
            o->x280 = c[0];
            o->x284 = c[25];
        }
        break;

    case 3:
        o->x248 = c[0];
        o->x280 = c[0];
        o->x24c = c[11] * (c[22] - o->x208);
        o->x284 = c[25];
        o->x26c = c[0];
        o->x270 = c[23];
        break;
    }

    o->x248 += dt;
    o->x224 += dt;
    o->x26c += dt;
    o->x294 += dt;
    o->x280 += dt;
}
