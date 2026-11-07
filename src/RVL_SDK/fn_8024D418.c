#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 lbl_8052CDC0[];
extern char lbl_80483A78[];
extern void fn_8022F0E0(void *);
extern void fn_8022F63C(void *, void *);
extern void fn_802319FC(int, const char *, int);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E7C4(u16);
void fn_8024D418(u8 *p) {
    u8 *data = p + *(u16 *)(p + 4);
    int handle = (data[8] + (data[9] << 8)) & 0xfff;
    u8 *ctx = fn_8024E7C4(handle);
    if (ctx == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319FC(0x80001, lbl_80483A78, handle);
        fn_8022F0E0(p);
    } else if (*(int *)(ctx + 4) == 4) {
        *(u16 *)(p + 6) = 0;
        fn_8022F63C(ctx + 0x44, p);
        ctx[0x40] = 0;
        fn_8024CB94(ctx, 0, 0);
    } else {
        fn_8022F0E0(p);
    }
}