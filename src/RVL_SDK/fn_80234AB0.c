#pragma force_active on
extern unsigned char lbl_80529858[];
extern int fn_8022EFF8(int, void*);
extern void fn_80246414(int, int);
extern void fn_8023A4FC(void (*)(void));
extern void fn_80234AAC(void);

void fn_80234AB0(void) {
    int r;
    lbl_80529858[0x7E] = 1;
    r = fn_8022EFF8(2, lbl_80529858);
    if (r != 0) {
        fn_80246414(r, 0);
    }
    fn_8023A4FC(fn_80234AAC);
}
