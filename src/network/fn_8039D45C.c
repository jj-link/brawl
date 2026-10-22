#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int lbl_805A1170;

s32 fn_8039D45C(u8 *arg0, s32 arg1, s8 *arg2, u32 arg3, u32 *arg4) {
    s32 nbits = 0;
    s32 bits = 0;
    u32 count = 0;
    s8 *out = arg2;
    u8 *table = (u8 *)(lbl_805A1170 + 0x1900);
    s8 c;

    while (arg1 > 0) {
        c = (s8)table[*arg0];
        if (c >= 0 && c < 0x40) {
            nbits += 6;
            bits <<= 6;
            bits |= c;
            if (nbits >= 8) {
                if (count >= arg3) {
                    *arg4 = arg3;
                    return -8;
                }
                nbits -= 8;
                count++;
                *out++ = (s8)(bits >> nbits);
            }
        }
        arg0++;
        arg1--;
    }
    *arg4 = count;
    return 0;
}
