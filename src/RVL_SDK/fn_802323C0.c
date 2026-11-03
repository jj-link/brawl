#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef u8 (*Handler)(u16 *);

extern void fn_8022F0E0(u16 *);
extern void fn_802319FC(s32, void *, s32);
extern void fn_80234A90(void);
extern char lbl_8047FC68[];
extern char lbl_8047FC7C[];
extern unsigned char lbl_80529858[0x90];
extern unsigned char lbl_805A0D30;

void fn_802323C0(u16 *arg0) {
    u8 var_r31;
    u16 key;
    s32 r5;
    Handler *obj;

    var_r31 = 1;
    if (lbl_805A0D30 >= 4) {
        fn_802319FC(0x503, lbl_8047FC68, *arg0);
    }
    key = *arg0;
    r5 = (s32)key >> 8;
    if (lbl_80529858[0x7E] != 0) {
        if (key == 0x101) {
            fn_80234A90();
        }
        fn_8022F0E0(arg0);
        return;
    }
    if ((u8)r5 < 0x1A && (obj = ((Handler **)lbl_80529858)[(u8)r5]) != 0) {
        var_r31 = (*obj)(arg0);
    } else if (lbl_805A0D30 >= 2) {
        fn_802319FC(0x501, lbl_8047FC7C, (u8)r5);
    }
    if (var_r31 != 0) {
        fn_8022F0E0(arg0);
    }
}
