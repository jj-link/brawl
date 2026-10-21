#include <types.h>
#pragma force_active on

struct Node {
    u8 pad0[0x50];
    Node* next;
};

struct Owner {
    u8 pad0[0x88];
    Node* head;
};

extern "C" {
void fn_27_261C7C(Node* node);

void fn_27_224C28(Owner* self) {
    u32 count = 0;
    u32 i = 0;
    Node* p = self->head;
    while (p != nullptr) {
        p = p->next;
        count++;
    }

    while (i != count) {
        Node* n = self->head;
        u32 k = i;
        while (k != 0 && n != nullptr) {
            n = n->next;
            k--;
        }
        if (n != nullptr) {
            fn_27_261C7C(n);
        }
        i++;
    }
}
}
