#include <types.h>
#pragma force_active on
extern u32 *lbl_805A1168;
static inline u32 checksum(u32 *p) {
    u32 sum = 0;
    u32 i = 31;
    while (i-- != 0) {
        sum += p[0]; sum += p[1]; sum += p[2]; sum += p[3];
        sum += p[4]; sum += p[5]; sum += p[6]; sum += p[7];
        p += 8;
    }
    sum += p[0]; sum += p[1]; sum += p[2]; sum += p[3];
    sum += p[4]; sum += p[5]; sum += p[6];
    return sum;
}
s32 fn_80399BCC(void) {
    u32 *base = lbl_805A1168;
    s32 result;
    if (base[0] != 0x57634366) return -14;
    if (base[255] != checksum(base)) return -14;
    if (base[4] >= 0x20) return -14;
    result = 0;
    if (base[1] != 8) result = -27;
    return result;
}