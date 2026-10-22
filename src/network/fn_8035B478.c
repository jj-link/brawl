#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 lbl_8048E7B8[];
void fn_8035B38C(u32* ctx, u8* data, u32 len);
void* memset(void*, int, unsigned long);

void fn_8035B478(u8* out, u32* ctx) {
    u8 bits[8];
    u32 n;
    bits[0] = ctx[4];
    bits[1] = ctx[4] >> 8;
    bits[2] = ctx[4] >> 16;
    bits[3] = ctx[4] >> 24;
    bits[4] = ctx[5];
    bits[5] = ctx[5] >> 8;
    bits[6] = ctx[5] >> 16;
    bits[7] = ctx[5] >> 24;
    n = (ctx[4] >> 3) & 0x3f;
    fn_8035B38C(ctx, lbl_8048E7B8, n < 56 ? 56 - n : 120 - n);
    fn_8035B38C(ctx, bits, 8);
    out[0] = ctx[0];
    out[1] = ctx[0] >> 8;
    out[2] = ctx[0] >> 16;
    out[3] = ctx[0] >> 24;
    out[4] = ctx[1];
    out[5] = ctx[1] >> 8;
    out[6] = ctx[1] >> 16;
    out[7] = ctx[1] >> 24;
    out[8] = ctx[2];
    out[9] = ctx[2] >> 8;
    out[10] = ctx[2] >> 16;
    out[11] = ctx[2] >> 24;
    out[12] = ctx[3];
    out[13] = ctx[3] >> 8;
    out[14] = ctx[3] >> 16;
    out[15] = ctx[3] >> 24;
    memset(ctx, 0, 0x58);
}
