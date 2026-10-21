#include <types.h>
#pragma force_active on

struct Node {
    Node* next;
    Node* prev;
};

class Object {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual Object* find(s32, s32);

    Node link;
};

struct Entry {
    s32 key;
    Object* object;
};

struct Owner {
    u8 pad0[0x14];
    Node children;
    u8 pad1[0xC];
    Object* primary;
    u8 pad2[0xD0];
    Entry* entries;
    u8 count;
};

extern "C" s32 fn_8018C114(void*, s32);

extern "C" Object* fn_80185A18(Owner* self, s32 key, s32 recurse) {
    if (self->primary &&
        fn_8018C114((u8*)self->primary + 0x44, key)) {
        return self->primary;
    }

    s32 i = 0;
    s32 offset = 0;
    for (; i < self->count; offset += 8, ++i) {
        if (fn_8018C114(
                (u8*)((Entry*)((u8*)self->entries + offset))->object + 0x44,
                key)) {
            return self->entries[i].object;
        }
    }

    if (recurse) {
        Node* end = &self->children;
        for (Node* node = self->children.next; node != end; node = node->next) {
            Object* result = ((Object*)((u8*)node - 4))->find(key, 1);
            if (result) {
                return result;
            }
        }
    }

    return 0;
}
