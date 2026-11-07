#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef signed int s32;

extern char lbl_80529CF8[];
extern char lbl_80480B7C[];
extern void fn_80232020(void *);
extern void fn_802319FC(s32, const char *, s32);

typedef void (*BtmCallback)(void *);

struct BtmEvent {
    u8  f0;
    u8  f1;
    u16 pad;
    s32 f4;
    s32 pad2;
    s32 fc;
    s32 f10;
    s32 f14;
    s16 f18;
    s8  f1A;
};

void fn_802393E4(s8 arg0, s16 arg1, u8 *arg2) {
    struct BtmEvent ev;
    BtmCallback callback = *(BtmCallback *)(lbl_80529CF8 + 0x618);

    fn_80232020(lbl_80529CF8 + 0x600);
    *(s32 *)(lbl_80529CF8 + 0x618) = 0;

    if (callback != 0) {
        ev.f1A = arg0;
        ev.f18 = arg1;
        if (arg2 != 0) {
            ev.f0 = arg2[0];
            ev.f1 = arg2[1];
            ev.f4 = *(s32 *)(arg2 + 4);
            ev.fc = *(s32 *)(arg2 + 0xC);
            ev.f10 = *(s32 *)(arg2 + 0x10);
            ev.f14 = *(s32 *)(arg2 + 0x14);
        }
        if ((u8)lbl_80529CF8[0x27C0] >= 5) {
            fn_802319FC(0xD0004, lbl_80480B7C, *(s32 *)(arg2 + 0x14));
        }
        callback(&ev);
    }
}
