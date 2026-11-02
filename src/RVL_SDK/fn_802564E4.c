#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319FC(u32, void *, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_80252784(void *, int, int);
extern u8 lbl_80484B18[];
extern u8 lbl_8052D5A8[];

void fn_802564E4(u8 *arg0) {
    u16 i;

    for (i = 0; i < 0x3D; i++) {
        if (arg0[0x24 + i] != 0) {
            arg0[0x74] = 0;
            return;
        }
    }

    if (arg0[0x74] != 0) {
        arg0[0x74] = 0;
        fn_80252784(arg0, 8, 0);
        return;
    }
    if (lbl_8052D5A8[0x414] >= 4) {
        fn_802319FC(0x90003, lbl_80484B18, 2);
    }
    *(void **)(arg0 + 0x10) = arg0;
    fn_80231FB0(arg0, 0xB, 2);
}
