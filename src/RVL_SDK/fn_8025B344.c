#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern u8 lbl_8052D9C0[];
extern char lbl_804851C4[];
extern char lbl_804851FC[];

extern void fn_80231A14(s32, const char *, u16, u16);
extern void fn_802319E4(s32, const char *);
extern void *fn_8022EFF8(s32);
extern void fn_8024ABC4(u16, void *, u32);
extern s32 strlen(const char *);

void fn_8025B344(void *arg0, int arg1, u16 arg2, u8 *arg3)
{
    u8 *s;
    u8 *d;
    u8 *h;
    u8 *t;
    u8 *p;
    s32 i;
    u32 plen;
    s32 len;

    if (lbl_8052D9C0[0x4630] >= 2) {
        fn_80231A14(0xA0001, lbl_804851C4, arg2, *(u16 *)((u8 *)arg0 + 0x22));
    }

    p = fn_8022EFF8(2);
    if (p == 0) {
        if (lbl_8052D9C0[0x4630] >= 1) {
            fn_802319E4(0xA0000, lbl_804851FC);
        }
        return;
    }

    *(u16 *)(p + 4) = 9;
    h = p + 0x11;
    d = h;
    *d++ = 1;
    *d++ = (u8)(arg1 >> 8);
    *d++ = (u8)arg1;
    t = d;
    d += 2;
    *d++ = (u8)(arg2 >> 8);
    *d++ = (u8)arg2;

    if (arg3 != 0) {
        s = arg3;
        i = 0;
        while (i < strlen((const char *)arg3)) {
            *d = *s;
            i++;
            s++;
            d++;
        }
    }

    len = d - h;
    plen = (d - t) - 2;
    t[0] = (u8)(plen >> 8);
    t[1] = (u8)plen;
    *(u16 *)(p + 2) = (u16)len;
    fn_8024ABC4(*(u16 *)((u8 *)arg0 + 0x22), p, plen);
}
