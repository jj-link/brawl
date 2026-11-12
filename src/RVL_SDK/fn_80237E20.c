#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_802319E4(int id, void *p);
extern void fn_80231A2C(int id, void *p, u8 a, u8 b, u8 c);
extern void fn_80231A44(int id, void *p, u16 a, u8 b, u8 c, u8 d);
extern u8 lbl_80480638[];
extern u8 lbl_80529AC8[];
extern u8 lbl_805A0D30;

void fn_80237E20(void) {
    u8 *base;
    u8 *e1;
    u8 *e2;
    unsigned int i;

    base = lbl_80480638;
    if (lbl_805A0D30 >= 5) {
        fn_802319E4(0x504, base + 0x1E4);
    }
    i = 0;
    do {
        if (lbl_805A0D30 >= 5) {
            e1 = lbl_80529AC8 + (((u8)i) << 5);
            fn_80231A2C(0x504, base + 0x220, (u8)i, e1[0x28], e1[0x26]);
        }
        if (lbl_805A0D30 >= 5) {
            e2 = lbl_80529AC8 + (((u8)i) << 5);
            fn_80231A44(0x504, base + 0x244, *(u16 *)(e2 + 0x1E), e2[0x2C], e2[0x23], e2[0x22]);
        }
        i++;
    } while (i < 0x10);
    if (lbl_805A0D30 >= 5) {
        fn_802319E4(0x504, base + 0x280);
    }
}