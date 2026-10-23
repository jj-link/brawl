#include <types.h>
#include <nw4r/ut/ut_LinkList.h>

struct Node {
    Node* next;
    u32 pad4;
    u32 flags;
    u8 padC[2];
    u16 s14;
};

struct Head {
    u32 count;
    Node head;
};

extern Head lbl_8049DEDC;

struct Object {
    u8 pad0[0xB];
    u8 bit7 : 1;
    u8 bit6 : 1;
    u8 rest : 6;
    u16 id;
    u8 padE[0xD6];
    Node* node;
};

inline Node* findNode(Head* head) {
    nw4r::ut::LinkList<Node, 0>* list =
        (nw4r::ut::LinkList<Node, 0>*)head;
    Node* found = 0;

    if (head->count != 0) {
        nw4r::ut::LinkList<Node, 0>::Iterator it = list->GetBeginIter();
        for (; it != list->GetEndIter(); it++) {
            u32 f = it->flags;
            if (((f >> 16) & 1) && ((f >> 23) & 7) == 5) {
                found = &*it;
                break;
            }
        }
    }
    return found;
}

#pragma force_active on
extern "C" void fn_800A4154(Object* p) {
    Node* found = findNode(&lbl_8049DEDC);
    p->node = found;
    p->id = 0;
    p->bit6 = p->bit7;
    p->bit7 = 0;

    if (found) {
        p->id = found->s14;
        p->bit7 = (found->flags >> 15) & 1;
    }
}
