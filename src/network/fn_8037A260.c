#include <types.h>
#include <string.h>
#pragma force_active on
extern char lbl_805A4998, lbl_805A4999, lbl_805A499A, lbl_805A499B, lbl_805A499C, lbl_805A499D;
extern s32 fn_803A7AF4(s32);
typedef struct Obj {
    unsigned char pad0[0xa0];
    void (*fnA0)(s32, s32);
    void (*fnA4)(u8 *, s32, s32);
    unsigned char pad1[0x64];
    s32 field10C;
} Obj;
static inline int matches(u8 *p, s32 n) {
    u8 magic[6];
    int i;
    int ok = 1;
    magic[0] = lbl_805A4998;
    magic[1] = lbl_805A4999;
    magic[2] = lbl_805A499A;
    magic[3] = lbl_805A499B;
    magic[4] = lbl_805A499C;
    magic[5] = lbl_805A499D;
    if (n >= 10) {
        for (i = 0; i < 6; i++) {
            if (magic[i] != p[i]) { ok = 0; break; }
        }
    } else ok = 0;
    return ok;
}
void fn_8037A260(Obj *arg0, u8 *arg1, s32 arg2) {
    s32 sp8;
    if (matches(arg1, arg2)) {
        memcpy(&sp8, arg1 + 6, 4);
        if (arg0->fnA0 != 0) {
            arg0->fnA0(fn_803A7AF4(sp8), arg0->field10C);
        }
    } else {
        if (arg0->fnA4 != 0) arg0->fnA4(arg1, arg2, arg0->field10C);
    }
}