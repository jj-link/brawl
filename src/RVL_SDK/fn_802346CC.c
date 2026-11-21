#include <types.h>
#pragma force_active on

extern u8 *lbl_8059EDAC;
extern u8 lbl_80529A98[];
extern u8 lbl_805298E8[];
extern u8 lbl_805A0D30;
extern void fn_80232034(u8 *dst, const u8 *src);
extern void fn_80231A2C(int a, char *b, int c, int d, int e);
extern char lbl_8047FD64[];
extern char lbl_8047FDA0[];

void fn_802346CC(u32 a0, u8 a1, u8 a2, const u8 *a3) {
    u8 i, j, k, n;
    int found;
    u8 *base, *p, *e;

    if (a0 == 0) {
        base = lbl_8059EDAC;
        n = base[1];
        for (i = 1; i <= n; i++) {
            p = base + i * 3;
            if ((a2 == p[1] || p[1] == 0xFF) && a1 == p[0] && p[2] == 1) {
                found = 0;
                for (j = 1; j <= base[1]; j++) {
                    if (base[j * 3 + 2] == 2) {
                        for (k = 0; k < lbl_80529A98[0]; k++) {
                            if (lbl_80529A98[k * 9 + 7] == base[j * 3])
                                found = 1;
                        }
                    }
                }
                if (found == 0) {
                    ((i - 1) * 9 + lbl_805298E8)[7] = a2;
                    ((i - 1) * 9 + lbl_805298E8)[6] = a1;
                    fn_80232034((i - 1) * 9 + lbl_805298E8, a3);
                    ((i - 1) * 9 + lbl_805298E8)[8] = 1;
                    if (lbl_805A0D30 >= 4)
                        fn_80231A2C(0x503, lbl_8047FD64, ((i - 1) * 9 + lbl_805298E8)[7], ((i - 1) * 9 + lbl_805298E8)[6], ((i - 1) * 9 + lbl_805298E8)[8]);
                }
                return;
            }
        }
    } else if (a0 == 1) {
        for (i = 1; i <= lbl_8059EDAC[1]; i++) {
            p = lbl_8059EDAC + i * 3;
            if ((a2 == p[1] || p[1] == 0xFF) && a1 == p[0]) {
                e = &lbl_805298E8[(i - 1) * 9];
                e[8] = 0;
                if (lbl_805A0D30 >= 4)
                    fn_80231A2C(0x503, lbl_8047FDA0, e[7], e[6], e[8]);
                return;
            }
        }
    }
}
