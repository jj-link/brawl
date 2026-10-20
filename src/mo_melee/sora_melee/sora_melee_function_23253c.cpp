#include <types.h>
#pragma force_active on

struct Node {
    Node* next;
    u32 unk4;
    u32 val8;
    u8 pad[0x10];
    void* p1c;
};

struct Owner {
    u8 pad[0x40];
    Node* head;
};

extern "C" void* fn_27_263AD0(void* p, int x);

extern "C" {
void fn_27_23253C(Owner* self, void* key, u32 value) {
    Node* n = self->head;
    while (n != nullptr) {
        if (n->p1c != nullptr) {
            if (key == fn_27_263AD0(n->p1c, 0)) {
                n->val8 = value;
                break;
            }
        }
        n = n->next;
    }
}
}
