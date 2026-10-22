#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct Ctx {
    char pad[0x4c];
    s32 count;
    u8 *buf;
} Ctx;

typedef struct Outer {
    char pad[0x1d0];
    Ctx *ctx;
} Outer;

extern "C" {
void fn_80069C7C(Outer *arg0, u32 arg1, s8 arg2) {
    Ctx *c;

    c = arg0->ctx;
    c->buf[c->count++] = 0x19;

    c = arg0->ctx;
    c->buf[c->count++] = (u8)(arg1 >> 24);
    c->buf[c->count++] = (u8)(arg1 >> 16);
    c->buf[c->count++] = (u8)(arg1 >> 8);
    c->buf[c->count++] = (u8)arg1;

    c = arg0->ctx;
    c->buf[c->count++] = arg2;
}
}
