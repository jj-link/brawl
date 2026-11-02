#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    int m_00;
    void *m_04;
    void *m_08;
    void *m_0c;
    void *m_10;
    int m_14;
    int m_18;
    int m_1c;
    void *m_20;
    int m_24;
    int m_28;
    u8 m_2c;
    u8 m_2d;
    u8 pad1[0x64 - 0x2e];
    int m_64;
    void *m_68;
    void *m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    u8 pad2[0x11d8 - 0x98];
    u8 m_11d8;
} Obj;

typedef struct {
    u8 pad[0x24];
    int m_24;
} Arg;

extern Obj *lbl_805A0F88;
extern char lbl_80489E48[];
extern char lbl_80533730[];
extern char lbl_805337B0[];
extern char lbl_80535BE0[];
extern char lbl_80535CE0[];
extern void fn_8033B134(void);
extern void fn_8033BA3C(void);
extern void fn_8033BA40(void);
extern void fn_8033C018(void);
extern void fn_80340A48(void);

extern void fn_80335638(int, const char *, ...);
extern void *fn_80335390(int, int);
extern void *memset(void *, int, u32);
extern u32 strlen(const char *);
extern void DWC_ClearError(void);
extern void fn_80338600(void *, void *, void *, int, int, void *, void *, int);
extern void fn_80336AF0(void *, void *, void *, int, int);
extern void fn_8033CBEC(void *, void *, void *, void *, void *, void *, int, int);
extern void fn_8034E59C(void *);
extern void fn_8034F028(void *, const char *, u32);

void DWC_InitFriendsMatch(int p0, Arg *p1, int p2, int p3, const char *p4, int p5, int p6, int p7, int p8) {
    u32 len;
    fn_80335638(4, lbl_80489E48);
    lbl_805A0F88 = fn_80335390(4, 0x11e0);
    memset(lbl_805A0F88, 0, 0x11e0);
    DWC_ClearError();
    lbl_805A0F88->m_00 = 0;
    lbl_805A0F88->m_04 = fn_80340A48;
    lbl_805A0F88->m_08 = fn_8033BA3C;
    lbl_805A0F88->m_0c = fn_8033BA40;
    lbl_805A0F88->m_10 = fn_8033C018;
    lbl_805A0F88->m_14 = p5 ? p5 : 0x2000;
    lbl_805A0F88->m_18 = p6 ? p6 : 0x2000;
    lbl_805A0F88->m_1c = 0;
    lbl_805A0F88->m_20 = p1;
    lbl_805A0F88->m_24 = 0;
    lbl_805A0F88->m_28 = 0;
    lbl_805A0F88->m_2c = 0;
    lbl_805A0F88->m_2d = 0;
    lbl_805A0F88->m_11d8 = 0;
    lbl_805A0F88->m_64 = 0;
    lbl_805A0F88->m_68 = lbl_80535BE0;
    lbl_805A0F88->m_6c = lbl_80535CE0;
    lbl_805A0F88->m_70 = 0;
    lbl_805A0F88->m_74 = 0;
    lbl_805A0F88->m_78 = 0;
    lbl_805A0F88->m_7c = 0;
    lbl_805A0F88->m_80 = 0;
    lbl_805A0F88->m_84 = 0;
    lbl_805A0F88->m_88 = 0;
    lbl_805A0F88->m_8c = 0;
    lbl_805A0F88->m_90 = 0;
    lbl_805A0F88->m_94 = 0;
    memset(lbl_80533730, 0, 0x80);
    memset(lbl_805337B0, 0, 0x100);
    fn_80338600((char *)lbl_805A0F88 + 0x98, p1, (char *)lbl_805A0F88 + 0x1c, p2, p1->m_24, (char *)lbl_805A0F88 + 0x2e, fn_8033B134, 0);
    fn_80336AF0((char *)lbl_805A0F88 + 0x300, (char *)lbl_805A0F88 + 0x1c, (char *)lbl_805A0F88 + 0x2e, p7, p8);
    fn_8033CBEC((char *)lbl_805A0F88 + 0x360, (char *)lbl_805A0F88 + 0x1c, (char *)lbl_805A0F88 + 4 - 4, (char *)lbl_805A0F88 + 4, lbl_80535BE0, lbl_80535CE0, p7, p8);
    fn_8034E59C((char *)lbl_805A0F88 + 0x8c0);
    if (strlen(p4) < 0x100) {
        len = strlen(p4);
    } else {
        len = 0xff;
    }
    fn_8034F028(lbl_80535CE0, p4, len);
    lbl_80535CE0[len] = 0;
}
