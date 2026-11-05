#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern int lbl_805A0FA8;
extern const char lbl_8048CC10[];

void fn_8034C674(unsigned int arg0, int arg1) {
    fn_80335638(0x40, lbl_8048CC10, arg0 >> 24, (arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF, arg1);
    *(int *)(lbl_805A0FA8 + 0x30) = (int)arg0;
    *(short *)(lbl_805A0FA8 + 0x2e) = (short)arg1;
}