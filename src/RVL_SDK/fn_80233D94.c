#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0[6];
    u8 unk6[0x20];
    u8 unk26;
    u8 pad27[0xFE - 0x27];
    u8 unkFE;
    u8 unkFF;
    u8 unk100;
} Msg;

typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x20];
} Arg;

extern void fn_80232034(u8 *dst, const u8 *src);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern unsigned char lbl_80529994[];

void fn_80233D94(Arg *arg0) {
    Msg msg;

    fn_80232034(msg.unk0, lbl_80529994 + 0xF8);
    msg.unkFE = lbl_80529994[0xFE];
    msg.unkFF = lbl_80529994[0xFF];
    msg.unk100 = lbl_80529994[0x100];
    if (arg0 != 0 && arg0->unk0 == 0) {
        memcpy(msg.unk6, arg0->unk4, arg0->unk2 < 0x20 ? arg0->unk2 : 0x20);
        msg.unk26 = 0;
    } else {
        msg.unk6[0] = 0;
    }
    ((void (*)(int, void *, void *))(*(void **)(lbl_80529994 + 0x50)))(2, &msg, lbl_80529994);
}
