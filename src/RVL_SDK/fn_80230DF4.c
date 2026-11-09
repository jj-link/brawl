#pragma force_active on
#pragma opt_propagation off
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct { s32 unk0; u8 pad4[0xD]; u8 unk11; u8 pad12[0xA]; u8 unk1C; u8 unk1D; u8 pad1E[2]; s32 unk20; u8 pad24[5]; u8 unk29; u8 pad2A[0x36]; } State;
typedef struct { u16 unk0, unk2, unk4, unk6; } Packet;
extern State lbl_80525F60;
extern char lbl_80526FC0[];
extern void fn_801D81C4(void *, void *, int, int, void (*)(void), void *);
extern int fn_802318EC(int);
extern void fn_8022F0E0(Packet*);
extern void fn_8022FC5C(u8);
extern Packet* fn_8022EFF8(u32);
extern u32 fn_8024D0F0(Packet*);
extern int fn_8024D2C0(void);
extern s32 fn_80229248(s32, u8, s32, void*, void (*)(void), Packet*);
extern u16 fn_8022F250(void);
extern void *memcpy(void *, const void *, unsigned long);
void fn_80230DF4(s32 arg0, Packet* arg1);
void fn_80230DF4(s32 arg0, Packet* arg1) {
    u8* aligned;
    Packet* p2;
    u32 val;
    Packet* p;
    u32 z;
    if (lbl_80525F60.unk29 != 2) {
        fn_8022F0E0(arg1);
        fn_8022FC5C(lbl_80525F60.unk1D);
        lbl_80525F60.unk1D = 0xFF;
        goto done;
    }
    if (arg0 <= 0) {
        fn_8022F0E0(arg1);
    } else {
        arg1->unk2 = arg0;
        p = fn_8022EFF8(3);
        if (p == 0) {
            fn_8022F0E0(arg1);
        } else {
            memcpy(p, arg1, ((arg1->unk2 + arg1->unk4 + 8) & ~3) + 4);
            val = fn_8024D0F0(p);
            z = 0;
            if (val != z) {
                if (fn_8024D2C0() & 0xFF) {
                    fn_801D81C4((void *)val, (void *)0, 0, 0, (void (*)(void))fn_802318EC, lbl_80526FC0 + 0x1000);
                }
            }
            fn_8022F0E0(arg1);
        }
    }
    do { p2 = fn_8022EFF8(lbl_80525F60.unk1D); } while (p2 == 0);
    p2->unk0 = 0x1100;
    aligned = (u8*)(((u32)p2 + 0x27) & ~31);
    p2->unk2 = 0;
    p2->unk4 = (u16)(aligned - ((u8*)p2 + 8));
    if (fn_80229248(lbl_80525F60.unk0, lbl_80525F60.unk11, (fn_8022F250() - 0x28) - p2->unk4, aligned, (void (*)(void))fn_80230DF4, p2) != 0) {
        fn_8022F0E0(p2);
    }
done: ;
}