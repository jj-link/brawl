#include <types.h>
#pragma force_active on

typedef struct State {
    s32 unk0;
    u8 pad4[0x38];
    void *pool;
    u32 poolUnk4;
    u16 poolCount;
    u8 pad46[2];
    u8 unk48;
    u8 pad49[0x60 - 0x49];
} State;

typedef struct Node {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 data[1];
} Node;

extern State lbl_80525F60;

void fn_8022F0E0(s32 arg);
void fn_8023052C(void);
void fn_80230508(u8 arg);
void *fn_8022F77C(void *pool);
void fn_8022F63C(void *pool, void *node);
s32 fn_802298D4(s32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5,
                 void *a6, void (*a7)(void *, s32), void *a8);

void fn_8023105C(void *a0, s32 arg1) {
    u8 old;

    if (arg1 != 0) {
        fn_8022F0E0(arg1);
        fn_8023052C();
        old = lbl_80525F60.unk48;
        lbl_80525F60.unk48 = old - 1;
        fn_80230508(old);
    }
    if (lbl_80525F60.unk48 < 5 && lbl_80525F60.poolCount != 0) {
        Node *node = fn_8022F77C(&lbl_80525F60.pool);
        if (fn_802298D4(lbl_80525F60.unk0, 0x20, 0, 0, 0,
                        node->unk2,
                        &node->data[node->unk4],
                        fn_8023105C, node) < 0) {
            fn_8022F63C(&lbl_80525F60.pool, node);
        } else {
            fn_8023052C();
            old = lbl_80525F60.unk48;
            lbl_80525F60.unk48 = old + 1;
            fn_80230508(old);
        }
    }
}
