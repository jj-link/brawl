#include <types.h>
#pragma force_active on

struct TableEntry {
    u32 unk0;
    s32 unk4;
    u16 unk8;
};

extern TableEntry lbl_27_data_4B8E0[];

struct InnerObj {
    u32 pad;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(u32*);
};

struct Outer {
    u32 pad[10];
    s32 unk28;
};

struct Node {
    Node* next;
    u32 unk4;
    u32 unk8;
    u32 pad[3];
    InnerObj* inner;
    Outer* unk1C;
};

struct Arg0 {
    u32 pad[10];
    s32 unk28;
    u32 pad2[5];
    Node* nodes;
};

struct Arg2 {
    u8 unk0;
    u8 pad[1];
    u16 unk2;
    s32 unk4;
    u32 unk8;
    s32 unkC;
    u16 unk10;
};

extern "C" void* fn_27_263AD0(void*, int);
extern "C" s32 fn_27_263AE8(Outer*);

extern "C" void fn_27_2323EC(Arg0* arg0, u32 arg1, Arg2* arg2) {
    Node* node = arg0->nodes;
    while (node != 0) {
        u32 sp8 = 0;
        InnerObj* inner = node->inner;
        int ok;
        if (inner != 0 && inner->v3(&sp8) != 0) {
            ok = 1;
        } else {
            ok = 0;
        }
        if (ok != 0 && sp8 == arg1) {
            u32 zero = 0;
            arg2->unk2 = (u16)node->unk8;
            arg2->unk4 = arg0->unk28;
            arg2->unk8 = zero;
            TableEntry* entry = &lbl_27_data_4B8E0[arg2->unk2];
            arg2->unkC = entry->unk4;
            arg2->unk10 = entry->unk8;
            arg2->unk0 = (u8)lbl_27_data_4B8E0[arg2->unk2].unk0;
            return;
        }
        if (node->unk1C != 0 &&
            arg1 == (u32)fn_27_263AD0(node->unk1C, 0)) {
            arg2->unk2 = (u16)node->unk8;
            arg2->unk4 = node->unk1C->unk28;
            arg2->unk8 = fn_27_263AE8(node->unk1C);
            TableEntry* entry = &lbl_27_data_4B8E0[arg2->unk2];
            arg2->unkC = entry->unk4;
            arg2->unk10 = entry->unk8;
            arg2->unk0 = (u8)lbl_27_data_4B8E0[arg2->unk2].unk0;
            return;
        }
        node = node->next;
    }
}
