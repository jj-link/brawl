#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char lbl_80529AC8[];
extern char lbl_8047FE30[];
extern u8 lbl_805A0D30;

extern void fn_80231A2C(int, char *, void *, int, u16);
extern void fn_80232780(void *);
extern void fn_80237600(void *, int, u8 *);
extern void fn_80237D10(void *, u8, int, void *, u8, u8);
extern u8 fn_80237DCC(void *, u8);
extern u8 fn_80247C00(void *, u16, u8 *);

void fn_80235E04(int arg0, u16 arg1, u8 *arg2) {
    u8 *temp_r31;
    u8 sp9;
    u8 sp8;
    u8 temp_r3;

    sp8 = 0x10;
    temp_r31 = *(u8 **)(lbl_80529AC8 + 0x210);
    if (arg0 == 0) {
        if (temp_r31[0x14] != 0) {
            arg1 = arg1 | 0x8000;
        }
        if (lbl_805A0D30 >= 4) {
            fn_80231A2C(0x503, lbl_8047FE30, temp_r31, arg0, arg1);
        }
        if (fn_80237DCC(temp_r31, arg2[0x64]) != 0) {
            if (temp_r31[0x16] == 0xFF) {
                temp_r3 = fn_80247C00(temp_r31 + 8, arg1, &sp9);
                sp8 = temp_r3;
                if (temp_r3 == 0) {
                    *(u8 *)(lbl_80529AC8 + sp9 + 0x214) = temp_r31[0x12];
                    fn_80237D10(temp_r31, sp9, arg1, arg2 + 0x68, arg2[0x64], temp_r31[0x15]);
                } else {
                    temp_r31[0x15] = 0;
                }
            }
        } else {
            sp8 = 0xFF;
        }
    }
    fn_80232780(lbl_80529AC8 + 0x228);
    fn_80237600(temp_r31, 0x1707, &sp8);
}
