#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    char pad14[6];
    u8 unk1A[6];
    u8 unk20;
    char pad21[0x4f];
    u8 unk70;
    char pad71[7];
    u8 unk78;
    u8 unk79;
} State;
extern State lbl_80529918;
extern int fn_8023C974(int);
extern u8 fn_80238D34(int);
extern void fn_80233B74(int, int, const char *);
extern int fn_8023F404(void (*)(int, int, const char *));
extern void fn_80232034(u8 *, const u8 *);
extern void fn_802337D0(int);
extern void *fn_8022EE58(u16);
extern void fn_802324E0(void *);
void fn_80233970(void) {
    short *p;
    int n = fn_8023C974(lbl_80529918.unk4);
    lbl_80529918.unk4 = n;
    if (n != 0) {
        if (fn_80238D34(n + 2))
            lbl_80529918.unk78 = 0;
        else
            lbl_80529918.unk78 = 1;
        lbl_80529918.unk79 = 0;
        fn_8023F404(fn_80233B74);
        lbl_80529918.unk70 = 0;
        lbl_80529918.unk10 = 0;
        lbl_80529918.unk20 = 0;
        lbl_80529918.unkC = lbl_80529918.unk8;
        fn_80232034(lbl_80529918.unk1A, (u8 *)(lbl_80529918.unk4 + 2));
        fn_802337D0(lbl_80529918.unk4 + 2);
    } else {
        lbl_80529918.unk8 = 0;
        p = fn_8022EE58(0x110);
        if (p != 0) {
            *p = 0x207;
            fn_802324E0(p);
        }
    }
}