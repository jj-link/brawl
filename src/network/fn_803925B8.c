#pragma force_active on
typedef struct S { int a0; char pad[0xa8]; int ac; } S;
extern int fn_803A8E70(int, int, int);
extern int fn_80392420(int, int, int, int);

int fn_803925B8(const S *s, int a1, int a2, int a3, int a4) {
    int r;
    if (s->ac > 0) {
        r = fn_803A8E70(s->ac, a2, a3);
    } else {
        r = fn_80392420(a1, a2, a3, a4);
    }
    if (r < 0) {
        if (s->a0 != 0) return -0x3EA;
        if (s->ac > 0) {
            if ((unsigned)(r + 7) <= 1) return 0;
        } else if (r == -0x38) {
            return 0;
        }
        return -0x3E9;
    }
    return r;
}