#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(u32 size, s32 align);
};

extern Object_vptr_0* lbl_805A0EB8;

struct Node {
    u8 pad0[4];
    s16 size;
    u8 pad6[0x20 - 6];
    s16 index;
    u8 pad22[4];
    u8 pad26a : 6;
    u8 b : 2;
    u8 a : 2;
    u8 pad27a : 6;
};

struct Owner {
    u8 pad0[0x20];
    Node* node;
    u8 pad24[4];
    Node** data1;
    s32 size1;
    u32 cap1;
    Node** data2;
    s32 size2;
    u32 cap2;
    u8 pad40[0xb4 - 0x40];
    signed char flag;
};

struct Flag {
    signed char v;
};

struct Target {
    u8 pad0[8];
    Owner* owner;
    u8 padc[0xa8 - 0xc];
    u8 kind;
    Flag isKind7() {
        Flag f;
        f.v = kind == 7;
        return f;
    }
};

extern "C" void fn_8027CE3C(void*, int);
extern "C" Node* fn_802E9BFC(Node*, Owner*);
extern "C" void fn_802E9DFC(Node*, Target*);

extern "C" void fn_802F83E8(Owner* owner, Target* target, int mode) {
    target->owner = owner;
    if (target->isKind7().v) {
        fn_802E9DFC(owner->node, target);
        return;
    }
    if (owner->flag) {
        Node* n = (Node*)lbl_805A0EB8->slot4(0x70, 0x30);
        n->size = 0x70;
        if (n) {
            n = fn_802E9BFC(n, owner);
        }
        if (mode == 1) {
            n->a = 1;
            n->b = 1;
            n->index = owner->size1;
            if (owner->size1 == (s32)(owner->cap1 & 0x3FFFFFFF)) {
                fn_8027CE3C(&owner->data1, 4);
            }
            owner->data1[owner->size1++] = n;
        } else {
            n->a = 0;
            n->b = 0;
            n->index = owner->size2;
            if (owner->size2 == (s32)(owner->cap2 & 0x3FFFFFFF)) {
                fn_8027CE3C(&owner->data2, 4);
            }
            owner->data2[owner->size2++] = n;
        }
        fn_802E9DFC(n, target);
        return;
    }
    if (mode == 1) {
        fn_802E9DFC(owner->data1[0], target);
    }
}
