#pragma force_active on
extern int fn_801DCF5C(int, void *);
extern void fn_801F0C64(void);
extern void fn_801F0D2C(void);
extern void fn_801E0704(void *);
extern void fn_801DD320(int);
extern unsigned char lbl_805A08B8;
extern unsigned short *__peReg;

void __GXPEInit(void) {
    fn_801DCF5C(0x12, fn_801F0C64);
    fn_801DCF5C(0x13, fn_801F0D2C);
    fn_801E0704(&lbl_805A08B8);
    fn_801DD320(0x2000);
    fn_801DD320(0x1000);
    __peReg[5] |= 0xF;
}