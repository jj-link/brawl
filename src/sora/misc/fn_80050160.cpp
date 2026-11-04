#pragma force_active on
extern "C" void fn_80050020(void *);
extern "C" void fn_8004FF3C(void *, int);
extern "C" void fn_8004D674(void *, int, void *);
extern "C" void *fn_8004E5C4(void *);
extern "C" void *g_GameGlobal;
extern "C" unsigned int lbl_8042B858[];
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void fn_80050160(void *arg) {
    fn_80050020((char *)arg + 8);
    int cnt = 0;
    void *off = (char *)arg + 0x98;
    void *base = arg;
    void *src = *(void **)((char *)g_GameGlobal + 0x10);
    do {
        fn_8004FF3C(off, cnt);
        *(u8 *)((char *)base + 0xb6) = 0;
        *(u8 *)((char *)base + 0xb7) = (u8)lbl_8042B858[*((u8 *)((char *)src + 0xd7))];
        *(u8 *)((char *)base + 0x9a) = (u8)cnt;
        *(u8 *)((char *)base + 0xa0) = (u8)cnt;
        *(u8 *)((char *)base + 0x9f) = *(u8 *)((char *)src + 0xbf);
        u8 val = *(u8 *)((char *)src + 0xd0);
        *(u8 *)((char *)base + 0xb0) = val;
        if (val != 0x78) {
            fn_8004D674(g_GameGlobal, val, (char *)off + 0xc);
        }
        cnt++;
        off = (char *)off + 0x5c;
        base = (char *)base + 0x5c;
        src = (char *)src + 0x5c;
    } while (cnt < 7);
    void *tmp = fn_8004E5C4(g_GameGlobal);
    *(u8 *)((char *)((void **)g_GameGlobal)[2] + 0x60) = *(u8 *)((char *)tmp + 0x2E4);
    tmp = fn_8004E5C4(g_GameGlobal);
    *(u8 *)((char *)((void **)g_GameGlobal)[2] + 0x61) = *(u8 *)((char *)tmp + 0x2E5);
    ((u16 ** )g_GameGlobal)[1][0] = 0;
    ((u16 ** )g_GameGlobal)[1][1] = 0;
    ((u16 ** )g_GameGlobal)[1][2] = 0;
    ((u16 ** )g_GameGlobal)[1][3] = 0;
    ((signed char *)arg)[0] = -1;
    ((u8 *)arg)[1] = 1;
    ((signed char *)arg)[2] = -1;
}