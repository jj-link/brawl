#include <types.h>
#pragma force_active on

extern "C" unsigned char lbl_8059E742;

typedef struct Entry {
    u8 f0;
    u8 f1;
    u8 pad2[2];
    u32 f4;
    u8 f8;
    u8 f9;
    u16 fA;
    u32 fC;
    u32 f10;
    u8 pad14[4];
} Entry;

struct Node;

typedef struct Node {
    s32 unk0;
    struct Node *unk4;
    struct Node *unk8;
    u8 unkC;
    u8 unkD;
    u16 unkE;
    u8 pad10[4];
    Entry entries[4];
} Node;

typedef struct MgrFlag {
    s8 f0;
    u8 pad[0x1F];
} MgrFlag;

typedef struct Mgr {
    u8 pad0[0x14];
    u8 unk14;
    u8 pad15[0x9B];
    MgrFlag field[4];
    u8 pad130[0x18];
    u16 unk148;
    u8 pad14A[0x306];
    Node *unk450;
    Node *unk454;
    Node *unk458;
} Mgr;

extern "C" s32 fn_80141474(Mgr *mgr, Node *node) {
    u8 g;
    u8 i;
    u32 n = 4;
    Entry *base;

    if (node->unk0 != 4)
        return 0;
    if (node->unkC == 0)
        return 0;
    g = lbl_8059E742;
    base = node->entries;
    for (i = 0; i < n; i++) {
        if (i != g && mgr->field[i].f0 != 0 && base[i].f1 == 0)
            return 0;
    }
    if ((s16)(node->unkE - mgr->unk148) > 0)
        mgr->unk148 = node->unkE;
    node->unkC = 0;
    node->unkD = 0;
    node->unk0 = 0;
    for (i = 0; i < n; i++) {
        node->entries[i].f0 = 0;
        node->entries[i].f1 = 0;
        node->entries[i].f8 = 0;
        node->entries[i].f9 = 0;
        node->entries[i].f4 = 0;
        node->entries[i].fA = 0;
        node->entries[i].fC = 0;
        node->entries[i].f10 = 0;
    }
    if (node->unk8)
        node->unk8->unk4 = node->unk4;
    if (node->unk4)
        node->unk4->unk8 = node->unk8;
    if (mgr->unk454 == node)
        mgr->unk454 = node->unk8;
    if (mgr->unk450 == node)
        mgr->unk450 = node->unk4;
    node->unk0 = 0;
    node->unk4 = mgr->unk458;
    node->unk8 = 0;
    u8 c = mgr->unk14;
    mgr->unk458 = node;
    if (c)
        mgr->unk14 = c - 1;
    return 1;
}