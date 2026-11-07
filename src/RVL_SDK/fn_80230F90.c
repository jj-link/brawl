#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    s32 unk0;
    u8 pad4[0xC];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 pad13[0x9];
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    s32 unk20;
    u8 pad24[7];
    u8 unk2B;
    u8 pad2C[0x34];
} State;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Packet;

extern State lbl_80525F60;

extern Packet* fn_8022EFF8(int);
extern void fn_8022F0E0(Packet*);
extern u16 fn_8022F250(void);
extern s32 fn_802291D4(int, int, int, int, int, int);
extern void fn_80230CE0(void);

void fn_80230F90(void) {
    Packet* p;
    u8* aligned;

    do {
        p = fn_8022EFF8(lbl_80525F60.unk1C);
    } while (p == 0);

    p->unk0 = 0x1000;
    aligned = (u8*)(((u32)p + 0x27) & ~31);
    p->unk2 = 0;
    p->unk4 = aligned - ((u8*)p + 8);

    if (fn_802291D4(
            lbl_80525F60.unk0,
            lbl_80525F60.unk12,
            (fn_8022F250() - 0x28) - p->unk4,
            (int)aligned,
            (int)fn_80230CE0,
            (int)p) != 0) {
        fn_8022F0E0(p);
    }

    lbl_80525F60.unk2B = 1;
}