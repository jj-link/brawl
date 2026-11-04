#include <types.h>
#pragma force_active on

typedef struct State {
    s32 unk0;
    u8 pad4[0xC];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 pad14[0xC];
    s32 unk20;
    u8 pad24[4];
    u8 unk28;
    u8 unk29;
    u8 pad2A[2];
    void *pool;
    u32 poolUnk4;
    u16 poolCount;
    u8 pad36[2];
    u8 unk38;
    u8 pad39[0x60 - 0x39];
} State;

extern State lbl_80525F60;

void fn_8022F0E0(s32 arg);
void fn_8023052C(void);
void fn_80230508(u8 arg);
void *fn_8022F77C(void *pool);
void fn_8022F63C(void *pool, void *node);
s32 fn_802292BC(s32 a0, u8 a1, u16 a2, void *a3, void (*a4)(s32, s32), void *a5);

void fn_80231148(s32 unused, s32 arg1) {
    u8 old;
    void *node;

    if (arg1 != 0) {
        fn_8022F0E0(arg1);
        fn_8023052C();
        old = lbl_80525F60.unk38;
        lbl_80525F60.unk38 = old - 1;
        fn_80230508(old);
    }
    if (lbl_80525F60.unk38 < 5 && lbl_80525F60.poolCount != 0) {
        node = fn_8022F77C(&lbl_80525F60.pool);
        if (fn_802292BC(lbl_80525F60.unk0, lbl_80525F60.unk10, *(u16 *)((u8 *)node + 2),
                        (u8 *)node + *(u16 *)((u8 *)node + 4) + 8, fn_80231148, node) < 0) {
            fn_8022F63C(&lbl_80525F60.pool, node);
        } else {
            fn_8023052C();
            old = lbl_80525F60.unk38;
            lbl_80525F60.unk38 = old + 1;
            fn_80230508(old);
        }
    }
}
