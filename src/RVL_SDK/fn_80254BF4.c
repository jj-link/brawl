#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void *fn_8022EFF8(int);
extern s8 fn_802560DC(int, void *);
extern void fn_80256858(void *, void *);
void fn_80254BF4(void *arg0, int arg1, int arg2)
{
    u8 *p;
    u8 *pkt;
    int flag;
    int v = 1;
    if (((u8 *)arg0)[0x6D] != 0) v = 0;
    flag = (v << 1) & 0xFE;
    pkt = fn_8022EFF8(2);
    if (pkt != 0) {
        *(u16 *)(pkt + 4) = 9;
        p = pkt + 0x11;
        p[0] = (u8)(flag | 1 | ((arg1 << 2) & 0x3FC));
        p[1] = (u8)((((-arg2 | arg2) >> 31) & 0x10) | 0xF);
        p[2] = 1;
        p[3] = fn_802560DC(3, p);
        *(u16 *)(pkt + 2) = 4;
        fn_80256858(arg0, pkt);
    }
}