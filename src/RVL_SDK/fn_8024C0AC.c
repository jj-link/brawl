#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_8052CDC0[];
extern char lbl_80483780[];
extern char lbl_80483048[];
extern void fn_802319FC(int, char *, int);
extern void fn_8024FA74(void *);
extern void fn_8024F4F8(void *, u8, u16, u16);
extern void fn_8022F0E0(int);

void fn_8024C0AC(void *obj, u16 event, int arg2, u32 arg3) {
    char *a = (char *)obj;
    void (*fp)(u16, u32) = *(void (**)(u16, u32))(*(char **)(a + 0x30) + 0x18);
    u16 val = *(u16 *)(a + 0x14);

    if (lbl_8052CDC0[0] >= 4) {
        fn_802319FC(0x80003, lbl_80483780, event);
    }

    switch (event) {
    case 3:
        if (lbl_8052CDC0[0] >= 3) {
            fn_802319FC(0x80002, lbl_80483048, *(u16 *)(a + 0x14));
        }
        fn_8024FA74(obj);
        fp(val, 0);
        break;

    case 30:
        fn_8024F4F8(*(void **)(a + 0x10), *(u8 *)(a + 0x36), *(u16 *)(a + 0x14), *(u16 *)(a + 0x16));
        if (lbl_8052CDC0[0] >= 3) {
            fn_802319FC(0x80002, lbl_80483048, *(u16 *)(a + 0x14));
        }
        fn_8024FA74(obj);
        fp(val, 0);
        break;

    case 27:
        fn_8024F4F8(*(void **)(a + 0x10), *(u8 *)(a + 0x36), *(u16 *)(a + 0x14), *(u16 *)(a + 0x16));
        fn_8024FA74(obj);
        break;

    case 19:
    case 29:
        fn_8022F0E0(arg2);
        break;

    default:
        break;
    }
}
