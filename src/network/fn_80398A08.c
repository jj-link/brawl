#pragma force_active on
typedef unsigned int u32;
typedef long long s64;
extern void OSSleepTicks(s64);
extern int fn_8020AA78(void *, int, int);
extern int fn_8039940C(int, int, void *);
extern int fn_803C3920(int, int, int, int);
extern int fn_803C3F48(const char *);
extern char lbl_8059FCC8[4];

int fn_80398A08(int a, int b, char *c) {
    int op = *(int *)(c + 4);
    int r;
    u32 i;
    switch (op) {
    case 1:
    case 9:
    case 0x101:
        return -7;
    case 10:
    case 0x10a:
        return fn_8039940C(a, b, c);
    }
    if (op & 0x100) {
        r = fn_803C3920(*(int *)(c + 0x98), a, b, 0);
        if (r != 0) {
            if (r == 5) {
                switch (fn_803C3F48(lbl_8059FCC8)) {
                case -5:
                case -15:
                    return -0x2e;
                case -4:
                    return -0x26;
                default:
                    return -0x12;
                }
            }
            return -0x12;
        }
        return 0;
    }
    i = 0;
    do {
        r = fn_8020AA78(c + 0xc, a, b);
        if ((u32)(r + 3) > 1) break;
        OSSleepTicks(1000 * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
        i++;
    } while (i < 3);
    if (r == -4) return -0x26;
    if (r < 0) {
        switch (r) {
        case -5:
        case -15:
            return -0x2e;
        case -4:
            return -0x26;
        default:
            return -0x12;
        }
    }
    return 0;
}