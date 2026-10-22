#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern char lbl_80529AC8[];
extern u8 fn_80247B1C(void);
extern void fn_80232780(void *);
extern void fn_80232034(u8 *, const u8 *);
extern void fn_80247FFC(u8);
extern void fn_80237E20(void);
extern void fn_8022E910(u8, u8);
extern void fn_802321FC(int, u8, void *);
extern void fn_80247D90(u8);
extern void fn_80237C90(void *);
extern void *memset(void *, int, unsigned long);

typedef void (*CB)(int, void *);

typedef struct { u8 a; u8 b; } S2;
typedef struct { u8 d[6]; u8 st; u8 port; } S8;

void fn_80236934(u8 *arg0, u8 *arg1)
{
    u8 status;
    S2 s;
    S8 b;
    int kind;
    u32 v;
    u32 i;

    kind = 3;
    *(short *)&s = 0;
    v = *(u32 *)(arg1 + 8);
    if (arg0[0x17] != 0) {
        kind = 0xD;
    }
    s.b = arg0[0x16];
    s.a = *(u32 *)(arg1 + 8);
    if ((v & 0x700) || v == 0xF || v == 0xE || arg0[0x1A] == 0) {
        b.port = arg0[0x16];
        b.st = (v == 0xF) ? 0xC : 6;
        fn_80232034(b.d, arg0 + 8);
        fn_80247FFC(arg0[0x16]);
        (*(CB *)(lbl_80529AC8 + 0x224))(2, &b);
        fn_80237E20();
        return;
    }
    fn_8022E910(arg0[0x16], arg0[0x15]);
    fn_802321FC(0x17, arg0[0x15], arg0 + 8);
    *(u8 *)(lbl_80529AC8 + 0x22D) -= 1;
    arg0[0x1A] = 0;
    if (s.a != 0) s.a = 6;
    (*(CB *)(lbl_80529AC8 + 0x224))(kind, &s);
    if (arg0[0x17] != 0) {
        fn_80247D90(arg0[0x16]);
        fn_80237C90(arg0);
    }
    fn_80237E20();
    arg0[0x17] = 0;
    *(short *)(arg0 + 0x10) = 0;
    if (*(u8 *)(lbl_80529AC8 + 0x22D) == 0 && *(u8 *)(lbl_80529AC8 + 0x22E) != 0) {
        status = 0;
        if (fn_80247B1C() != 0) status = 6;
        for (i = 0; i < 16; i++) {
            fn_80232780(lbl_80529AC8 + (u8)i * 0x20 + 0x14);
        }
        fn_80232780(lbl_80529AC8 + 0x228);
        (*(CB *)(lbl_80529AC8 + 0x224))(1, &status);
        memset(lbl_80529AC8, 0, 0x230);
    }
}
