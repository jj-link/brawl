#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u8 pad[0x78]; u32 lengths[2]; u32 protocols[2]; } Context;
extern int fn_8039DAF8(u32);
extern void fn_80399CC8(void *, void *, u32);
#define W(a) (*(u32 *)(x + (a)))
#define B(a) (*(u8 *)(x + (a)))
int fn_8039AE1C(void *arg0, void *buf, u32 len, u32 proto)
{
    u8 *x = (u8 *)arg0;
    u32 sum = 0;
    u8 *p;
    u8 count;
    u32 n;
    u32 t;
    if ((W(4) & 0x100) == 0 || (W(4) & 0x200) != 0) return -7;
    if (buf == 0 || len == 0) return -5;
    if (B(0xc9) >= 2) return -6;
    if (fn_8039DAF8(proto) == 0) return -3;
    if (W(4) & 2) {
        if (proto != 0x10000 && proto != 0x10001 && proto != 0x20000 && proto != 0x30000) return -4;
    }
    if ((proto - 0x30000) == 2 && len > 0x80) return -3;
    count = B(0xc9);
    for (n = 0; n < count; n++) {
        sum += ((Context *)x)->lengths[n];
    }
    sum += len;
    if (sum >= 0x245b0) return -8;
    fn_80399CC8(x + 0x68 + (B(0xc9) * 8), buf, len);
    ((Context *)x)->lengths[B(0xc9)] = len;
    ((Context *)x)->protocols[B(0xc9)] = proto;
    B(0xc9) = B(0xc9) + 1;
    W(4) = W(4) | 0x10000;
    return 0;
}
