#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;

extern void fn_80231228(void *, u8, void *, u16);
extern void fn_80231430(void *, void *);
extern void fn_802305A4(int a, s8 b);
extern u8 lbl_80525F28[0x38];

typedef struct {
    u32 pad;
    u16 x;
    u16 y;
    u16 z;
    u8 pad2;
    u8 w;
} Local;

s32 fn_80230B38(void *arg0) {
    Local sp8;
    u16 t;

    sp8.w = 0;
    sp8.x = ((u16 *)arg0)[0];
    t = ((u16 *)arg0)[1];
    sp8.y = t;
    sp8.z = lbl_80525F28[0x1F];
    lbl_80525F28[0x1E] = 2;
    fn_80231228(&sp8, lbl_80525F28[0x1F], lbl_80525F28, t);
    fn_80231430(&sp8, (void *)fn_802305A4);
    return 1;
}
