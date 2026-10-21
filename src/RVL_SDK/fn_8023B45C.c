#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x61C];
    void* callback;
    u8 pad620[0x30];
    u8 busy;
    u8 pad651[0x216F];
    u8 level;
} State;

extern State lbl_80529CF8;
extern char lbl_80480DB4[];
extern char lbl_80480DF4[];

extern void fn_80231A14(u32, const char*, void*, u16);
extern void fn_802319E4(u32, const char*);
extern void* fn_8022EE58(u16);
extern void fn_80246EE4(void*, void*, u16, u32);

int fn_8023B45C(void* data, u16 size, u32 arg, void* callback)
{
    void* packet;

    if (lbl_80529CF8.level >= 4) {
        fn_80231A14(0xD0003, lbl_80480DB4, data, size);
    }

    if (lbl_80529CF8.busy) {
        if (lbl_80529CF8.level >= 4) {
            fn_802319E4(0xD0003, lbl_80480DF4);
        }
        return 2;
    }

    packet = fn_8022EE58((u16)(size + 11));
    if (packet != 0) {
        lbl_80529CF8.callback = callback;
        if (callback != 0) {
            lbl_80529CF8.busy = 1;
        }

        fn_80246EE4(packet, data, size, arg);

        if (callback != 0) {
            return 1;
        }
        return 0;
    }

    return 3;
}
