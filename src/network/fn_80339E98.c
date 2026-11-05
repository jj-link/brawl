#pragma force_active on
typedef unsigned char u8;

typedef struct {
    u8 pad0[0x24];
    int m_24;
    int m_28;
    u8 pad1[0x78 - 0x2c];
    int m_78;
    int m_7c;
} Obj;

extern Obj *lbl_805A0F88;
extern char lbl_8048A0BC[];
extern char lbl_80489F10[];

extern int fn_80335238(void);
extern void fn_80335638(int, const char *, ...);
extern void fn_80336E84(void *, void *, void (*)(void), int, int, int, int, int);
extern void fn_8033B1D4(void);

int fn_80339E98(int a0, int a1, int a2, int a3, int a4, int a5, int a6) {
    int state;

    fn_80335638(4, lbl_8048A0BC);
    if (fn_80335238() != 0 || (state = lbl_805A0F88->m_24, state < 3) || state == 4) {
        fn_80335638(4, lbl_80489F10);
        return 0;
    }
    lbl_805A0F88->m_78 = a1;
    lbl_805A0F88->m_7c = a2;
    lbl_805A0F88->m_28 = lbl_805A0F88->m_24;
    lbl_805A0F88->m_24 = 4;
    fn_80336E84((u8 *)lbl_805A0F88 + 0xE4, (u8 *)lbl_805A0F88 + 0x1E4, fn_8033B1D4, 0, a3, a4, a5, a6);
    return 1;
}
