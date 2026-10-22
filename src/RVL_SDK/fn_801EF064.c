#pragma force_active on
extern void fn_801EE720(void);
extern int fn_801DCF5C(int, void *);
extern void fn_801DD320(int);
extern void *fn_801E0714(void);
extern void *memset(void *, int, unsigned int);
extern char lbl_804DED60[];
extern char lbl_804DED84[];
extern signed char lbl_805A0898;
extern signed char lbl_805A0899;
extern int lbl_805A08A8;
extern void *lbl_805A08AC;

void __GXFifoInit(void) {
    fn_801DCF5C(0x11, fn_801EE720);
    fn_801DD320(0x4000);
    lbl_805A08AC = fn_801E0714();
    lbl_805A08A8 = 0;
    memset(lbl_804DED84, 0, 0x24);
    memset(lbl_804DED60, 0, 0x24);
    lbl_805A0898 = 0;
    lbl_805A0899 = 0;
}
