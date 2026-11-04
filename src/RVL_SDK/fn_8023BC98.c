#pragma force_active on
extern void fn_802568BC(void *, int, int, void *, int, int);
extern void *memset(void *, int, unsigned long);
extern unsigned char lbl_80529CF8[];

void fn_8023BC98(void) {
    *(void **)(lbl_80529CF8 + 0x1678) = lbl_80529CF8 + 0x6D4;
    memset(lbl_80529CF8 + 0x658, 0, 0x1020);
    *(short *)(lbl_80529CF8 + 0x670) = 1;
    *(short *)(lbl_80529CF8 + 0x674) = 2;
    *(short *)(lbl_80529CF8 + 0x678) = 0x1002;
    fn_802568BC(*(void **)(lbl_80529CF8 + 0x1678), 0xFA0, 1, lbl_80529CF8 + 0x674, 0, 0);
}