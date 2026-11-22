#include <types.h>
#pragma force_active on

extern "C" void fn_8015ECB8(void*, int);
extern "C" float fn_80160F5C(void*, int, int, int);

extern "C" float fn_801605B0(u8* arg0, int a, int b) {
    u8 buf[0x68];
    float f31;
    float fb;
    float fa;
    s32 r6;
    s32 t0;

    buf[0x00] = arg0[0x00];
    buf[0x01] = arg0[0x01];
    buf[0x02] = arg0[0x02];
    buf[0x03] = arg0[0x03];
    buf[0x04] = arg0[0x04];
    buf[0x05] = arg0[0x05];
    buf[0x06] = arg0[0x06];
    buf[0x07] = arg0[0x07];
    buf[0x08] = arg0[0x08];
    buf[0x09] = arg0[0x09];
    buf[0x0A] = arg0[0x0A];
    buf[0x0B] = arg0[0x0B];
    buf[0x0C] = arg0[0x0C];
    buf[0x0D] = arg0[0x0D];
    buf[0x0E] = arg0[0x0E];
    buf[0x0F] = arg0[0x0F];
    buf[0x10] = arg0[0x10];
    buf[0x11] = arg0[0x11];
    buf[0x12] = arg0[0x12];
    buf[0x13] = arg0[0x13];
    buf[0x14] = arg0[0x14];
    buf[0x15] = arg0[0x15];
    buf[0x16] = arg0[0x16];
    buf[0x17] = arg0[0x17];
    buf[0x18] = arg0[0x18];
    buf[0x19] = arg0[0x19];
    buf[0x1A] = arg0[0x1A];
    buf[0x1B] = arg0[0x1B];
    buf[0x1C] = arg0[0x1C];
    buf[0x1D] = arg0[0x1D];
    buf[0x1E] = arg0[0x1E];
    buf[0x1F] = arg0[0x1F];
    *(s32*)(buf + 0x20) = *(s32*)(arg0 + 0x20);
    t0 = *(s32*)(arg0 + 0x24);
    r6 = *(s32*)(arg0 + 0x28);
    *(s32*)(buf + 0x24) = t0;
    *(s32*)(buf + 0x28) = r6;
    r6 = *(s32*)(arg0 + 0x2C);
    t0 = *(s32*)(arg0 + 0x30);
    *(s32*)(buf + 0x2C) = r6;
    *(s32*)(buf + 0x30) = t0;
    t0 = *(s32*)(arg0 + 0x34);
    *(s32*)(buf + 0x34) = t0;
    r6 = *(s32*)(arg0 + 0x38);
    t0 = *(s32*)(arg0 + 0x3C);
    *(s32*)(buf + 0x38) = r6;
    *(s32*)(buf + 0x3C) = t0;
    buf[0x40] = arg0[0x40];
    buf[0x41] = arg0[0x41];
    buf[0x42] = arg0[0x42];
    buf[0x43] = arg0[0x43];
    *(f32*)(buf + 0x44) = *(f32*)(arg0 + 0x44);
    *(s32*)(buf + 0x48) = *(s32*)(arg0 + 0x48);
    *(f32*)(buf + 0x4C) = *(f32*)(arg0 + 0x4C);
    *(f32*)(buf + 0x50) = *(f32*)(arg0 + 0x50);
    *(f32*)(buf + 0x54) = *(f32*)(arg0 + 0x54);
    *(s32*)(buf + 0x58) = *(s32*)(arg0 + 0x58);
    *(s32*)(buf + 0x5C) = *(s32*)(arg0 + 0x5C);
    *(s32*)(buf + 0x60) = *(s32*)(arg0 + 0x60);

    f31 = fn_80160F5C(buf, a, b, r6);
    fb = *(f32*)(buf + 0x30);
    fa = *(f32*)(buf + 0x2C);
    *(f32*)(arg0 + 0x2C) = fa;
    *(f32*)(arg0 + 0x30) = fb;
    fn_8015ECB8(buf, 0);
    return f31;
}
