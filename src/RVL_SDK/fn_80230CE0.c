#include <types.h>
#pragma force_active on
#pragma opt_propagation off

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Packet;

typedef struct {
    s32 unk0;
    u8 pad4[0x18];
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[0xB];
    u8 unk29;
    u8 pad2A[1];
    u8 unk2B;
    u8 pad2C[0x34];
} State;

extern State lbl_80525F60;
extern u8 lbl_80525FC0[];

extern void fn_8022F0E0(Packet*);
extern void fn_8022FC5C(u8);
extern Packet* fn_8022EFF8(u32);
extern void fn_801D81C4(void*, s32, s32, s32, void (*)(void), void*);
extern void fn_802318EC(void);
extern void fn_80230F90(void);
extern void *memcpy(void *, const void *, u32);

void fn_80230CE0(s32 arg0, Packet* arg1) {
    Packet* temp;
    Packet* p;

    lbl_80525F60.unk2B = 0;
    if (lbl_80525F60.unk29 != 2) {
        fn_8022F0E0(arg1);
        fn_8022FC5C(lbl_80525F60.unk1C);
        lbl_80525F60.unk1C = 0xFF;
        return;
    }
    p = 0;
    if (arg1 != p) {
        if (arg0 <= 0) {
            fn_8022F0E0(arg1);
        } else {
            temp = fn_8022EFF8(2);
            if (temp == 0) {
                fn_8022F0E0(arg1);
            } else {
                u32 size = (u16)arg0;
                arg1->unk2 = arg0;
                arg1->unk0 = 0x1000;
                memcpy(temp, arg1, ((size + arg1->unk4 + 8) & ~3) + 4);
                fn_801D81C4(temp, 0, 0, 0, fn_802318EC, lbl_80525FC0 + 0x1000);
                fn_8022F0E0(arg1);
            }
        }
    }
    fn_80230F90();
}
