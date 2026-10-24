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
    virtual void e3(s32 flags);
    ListNode link;
};

class Base {
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    u8 pad[0x14 - 4];
    ListNode sentinel;
    u8 pad2[0xB7 - 0x14 - 4];
    u8 flagB7;
};

extern "C" {
void fn_80182F9C(Base* self, s32 flags) {
    if (self->flagB7 & 1) {
        self->b4();
        ListNode* node = self->sentinel.next;
        ListNode* end = &self->sentinel;
        while (node != end) {
            Elem* e = (Elem*)((u8*)node - 4);
            e->e3(flags);
            node = node->next;
        }
    }
}
}
