#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct D { u8 pad[4]; s32 err; u8 pad2[0x25]; u8 k; } D;
typedef struct S { u8 pad[0x1808]; u8 f; u8 pad2[0x1C7]; D* d; } S;
extern s32 fn_80261274(S*);
extern s32 fn_80261004(u16*, S*);

s32 fn_80262CF0(S* a) {
    u16 sp;
    s32 r;
    if (a->d->k == 1) return 0;
    if (a->f == 0) {
        r = fn_80261274(a);
        if (r < 0) return r;
        r = fn_80261004(&sp, a);
        if (r < 0 && r != -0x90) return r;
        if (sp != 0xFFD9 && sp != 0xFFDC) {
            a->d->err = -0x21;
            return 0;
        }
    }
    return 0;
}
