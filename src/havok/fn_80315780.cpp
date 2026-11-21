#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern "C" void fn_80315780(u8* arg0) {
    u8* p4 = arg0 + 4;
    u8* e = p4;
    u8 f[16];
    u32 offs[16];
    u8* pf;
    u32* po;
    u16* dst;
    u16* src;
    u8* base;
    s32 i;
    s32 n;
    s32 kept;
    u32 off;

    *(u32*)&f[0] = 0;
    *(u32*)&f[4] = 0;
    *(u32*)&f[8] = 0;
    *(u32*)&f[12] = 0;

    for (i = 0; i < arg0[2]; i++) {
        s32 t = e[0] + e[1];
        f[e[4] >> 4] = 1;
        f[e[5] >> 4] = 1;
        if (t >= 3) {
            f[e[6] >> 4] = 1;
        }
        if (t == 4) {
            f[e[7] >> 4] = 1;
        }
        e += 8;
    }

    base = arg0 + 4;
    src = (u16*)(base + ((arg0[2] * 8) & 0x7F8));
    dst = src;
    kept = 0;
    n = arg0[0] + arg0[1];
    po = offs;
    pf = f;
    off = 0;
    for (i = 0; i < n; i++) {
        *po = off;
        if (*pf != 0) {
            kept++;
            off += 0x10;
            *dst = *src;
            dst++;
        }
        po++;
        pf++;
        src++;
    }

    {
        u8 v = (u8)((offs[arg0[0]] >> 4) & 0xFF);
        arg0[0] = v;
        arg0[1] = (u8)(kept - v);
    }

    for (i = 0; i < arg0[2]; i++) {
        p4[4] = (u8)offs[p4[4] >> 4];
        p4[5] = (u8)offs[p4[5] >> 4];
        p4[6] = (u8)offs[p4[6] >> 4];
        p4[7] = (u8)offs[p4[7] >> 4];
        p4 += 8;
    }
}
