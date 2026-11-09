#include <types.h>
#pragma force_active on
extern u8 lbl_8052CDC0[];
extern char lbl_80483048[];
extern char lbl_80483408[];
extern void fn_8022F0E0(void *);
extern void fn_802319FC(int, char *, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_8024EAE8(void *, int, int);
extern void fn_8024F424(void *);
extern void fn_8024FA74(void *);

void fn_8024B6CC(u8 *obj, u16 event, u8 *arg) {
    void (*callback)(u16, int) = *(void (**)(u16, int))(*(u8 **)(obj + 0x30) + 0x18);
    u16 id = *(u16 *)(obj + 0x14);
    if (lbl_8052CDC0[0] >= 4)
        fn_802319FC(0x80003, lbl_80483408, event);
    switch (event) {
    case 3:
        if (lbl_8052CDC0[0] >= 3)
            fn_802319FC(0x80002, lbl_80483048, *(u16 *)(obj + 0x14));
        fn_8024FA74(obj);
        callback(id, 0);
        break;
    case 21:
        if (arg == 0 || *(u16 *)(arg + 10) == 0) {
            fn_8024EAE8(obj, 0, 0);
            *(u32 *)(obj + 4) = 5;
            fn_80231FB0(obj + 0x18, 3, 30);
        } else {
            fn_8024EAE8(obj, *(u16 *)(arg + 10), *(u16 *)(arg + 12));
            fn_80231FB0(obj + 0x18, 3, 120);
        }
        break;
    case 22:
        fn_8024EAE8(obj, *(u16 *)(arg + 10), *(u16 *)(arg + 12));
        fn_8024FA74(obj);
        break;
    case 30:
        fn_8024EAE8(obj, 2, 0);
        if (lbl_8052CDC0[0] >= 3)
            fn_802319FC(0x80002, lbl_80483048, *(u16 *)(obj + 0x14));
        fn_8024FA74(obj);
        callback(id, 0);
        break;
    case 19:
    case 29:
        fn_8022F0E0(arg);
        break;
    case 26:
        fn_8024F424(obj);
        *(u32 *)(obj + 4) = 7;
        fn_80231FB0(obj + 0x18, 3, 30);
        break;
    }
}