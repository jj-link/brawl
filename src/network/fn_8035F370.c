#include <types.h>
#include <string.h>
#pragma force_active on
extern s32 fn_8035D770();
extern u32 lbl_805349A8[];
static inline u64 mul(u32 a, u32 b) { return (u64)a * b; }
s32 fn_8035F370(u32 *arg0, u32 arg1, u32 *arg2, u32 arg3, u32 *arg4, u32 *arg5, u32 arg6) {
    u32 sp[65];
    u32 i, j;
    memset(sp, 0, 0x104);
    *arg5 = 0;
    if (lbl_805349A8[3] == 0) {
        u32 t = lbl_805349A8[2];
        lbl_805349A8[2] = t + 1;
        lbl_805349A8[0] = fn_8035D770(t);
        lbl_805349A8[3] = 1;
    }
    for (i = 0; i < arg3; ++arg2, ++i) {
        if (*arg2 != 0) {
            for (j = 0; j < arg1; ++j) {
                u64 product = mul(arg0[j], *arg2);
                u32 k = i + j;
                if (k >= arg6) {
                    if (lbl_805349A8[3] == 1) {
                        u32 now = fn_8035D770() - lbl_805349A8[0];
                        lbl_805349A8[1] += now;
                        lbl_805349A8[3] = 0;
                    }
                    return 0;
                }
                while (product) {
                    ++k;
                    product += sp[k];
                    sp[k] = (u32)product;
                    product >>= 32;
                    if (k > arg6 || (k == arg6 && product != 0)) {
                        if (lbl_805349A8[3] == 1) {
                            u32 now = fn_8035D770() - lbl_805349A8[0];
                            lbl_805349A8[1] += now;
                            lbl_805349A8[3] = 0;
                        }
                        return 0;
                    }
                }
                if (k > sp[0]) sp[0] = k;
            }
        }
    }
    while ((i = sp[0]) != 0 && sp[i] == 0) --sp[0];
    *arg5 = i;
    memcpy(arg4, &sp[1], i * 4);
    if (lbl_805349A8[3] == 1) {
        u32 now = fn_8035D770() - lbl_805349A8[0];
        lbl_805349A8[1] += now;
        lbl_805349A8[3] = 0;
    }
    return 1;
}