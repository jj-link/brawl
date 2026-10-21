#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 a;
    u8 b;
    u32 c;
    u32 unused;
    u32 d;
    u32 e;
    u32 f;
} Params;

extern void fn_802393E4(u8, u16, Params *);

void fn_80242BFC(u8 *p)
{
    u8 a = p[0];
    u16 b = p[1] + (p[2] << 8);
    Params params;

    params.a = p[3];
    params.b = p[4];
    params.c = p[5] + (p[6] << 8) + (p[7] << 16) + (p[8] << 24);
    params.d = p[9] + (p[10] << 8) + (p[11] << 16) + (p[12] << 24);
    params.e = p[13] + (p[14] << 8) + (p[15] << 16) + (p[16] << 24);
    params.f = p[17] + (p[18] << 8) + (p[19] << 16) + (p[20] << 24);
    fn_802393E4(a, b, &params);
}
