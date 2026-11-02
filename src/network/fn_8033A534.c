#pragma force_active on
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 unk0;
    u8 pad4[0x20];
    s32 unk24;
    s32 unk28;
    u8 pad2c;
    u8 unk2D;
    u8 pad2e[0x36D - 0x2E];
    u8 unk36D;
    u8 pad36e[0x377 - 0x36E];
    u8 unk377;
    u8 pad378[0x514 - 0x378];
    s32 unk514;
} Obj;

extern void fn_80335638(int, const char *, ...);
extern int fn_80335238(void);
extern void fn_8033C0D4(void);
extern void fn_80342328(int);
extern void fn_80374BD4(s32);
extern char lbl_80489E48[];
extern Obj *lbl_805A0F88;

s32 fn_8033A534(void) {
    const char *base = lbl_80489E48;
    fn_80335638(4, base + 0x414);
    if (lbl_805A0F88 == 0 || fn_80335238() != 0 || (lbl_805A0F88->unk24 != 5 && lbl_805A0F88->unk24 != 6)) {
        fn_80335638(4, base + 0xC8);
        return -1;
    }
    if ((lbl_805A0F88->unk377 == 2 || lbl_805A0F88->unk514 == 0xB) && lbl_805A0F88->unk36D == 0) {
        fn_80335638(0x100, base + 0x3FC);
        fn_80342328(1);
        fn_8033C0D4();
        lbl_805A0F88->unk514 = 0;
        lbl_805A0F88->unk28 = lbl_805A0F88->unk24;
        lbl_805A0F88->unk24 = 3;
        return 1;
    }
    lbl_805A0F88->unk2D = 1;
    fn_80374BD4(lbl_805A0F88->unk0);
    lbl_805A0F88->unk2D = 0;
    lbl_805A0F88->unk514 = 0;
    return 0;
}
