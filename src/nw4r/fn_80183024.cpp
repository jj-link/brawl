#include <types.h>
#pragma force_active on

class ListNode {
public:
    ListNode* next;
};

class Elem {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5(s32 flags);
    ListNode link;
};

class Base {
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    u8 pad[0x14 - 4];
    ListNode sentinel;
    u8 pad2[0xB7 - 0x14 - 4];
    u8 flagB7;
};

extern "C" {
void fn_80183024(Base* self, s32 flags) {
    self->b6();
    if ((self->flagB7 & 1) || !(flags & 1)) {
        ListNode* node;
        ListNode* head = &self->sentinel;
        node = head->next;
        while (node != head) {
            Elem* e = (Elem*)((u8*)node - 4);
            e->e5(flags);
            node = node->next;
        }
    }
}
}
