#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    s32 unk0;
    u8 pad4[0xD];
    u8 unk11;
    u8 pad12[0xA];
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    s32 unk20;
    u8 pad24[5];
    u8 unk29;
    u8 pad2A[0x36];
} State;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Packet;

extern State lbl_80525F60;
extern s32 lbl_8059ED98;

extern void fn_8023052C(void);
extern int fn_80230508(void);
extern void fn_80230F90(void);
extern Packet* fn_8022EFF8(int);
extern void fn_8022F0E0(Packet*);
extern u16 fn_8022F250(void);
extern void fn_80230DF4(void);
extern s32 fn_80229248(s32, u8, s32, void*, void (*)(void), Packet*);

void fn_80231430(s32 unused, s32 arg)
{
    u8* aligned;
    Packet* p;

    if (lbl_80525F60.unk29 != 4 ||
        lbl_80525F60.unk1C == 0xFF ||
        lbl_80525F60.unk1D == 0xFF)
        return;

    {
        fn_8023052C();
        lbl_80525F60.unk20 = arg;
        lbl_80525F60.unk29 = 2;
        fn_80230508();
        fn_80230F90();

        do {
            p = fn_8022EFF8(lbl_80525F60.unk1D);
        } while (p == 0);

        p->unk0 = 0x1100;
        aligned = (u8*)(((u32)p + 0x27) & ~31);
        p->unk2 = 0;
        p->unk4 = aligned - ((u8*)p + 8);

        if (fn_80229248(
                lbl_80525F60.unk0,
                lbl_80525F60.unk11,
                (fn_8022F250() - 0x28) - p->unk4,
                aligned,
                fn_80230DF4,
                p) != 0) {
            fn_8022F0E0(p);
        }

        lbl_8059ED98 = 0;
    }
}
