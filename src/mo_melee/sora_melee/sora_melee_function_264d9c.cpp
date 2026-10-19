#include <types.h>
#pragma force_active on

struct Node {
    u8 pad0[0x1c];
    Node* m1c;
    Node* m20;
    Node* m24;
    u8 pad1[0x14c - 0x28];
    Node* m14c;
};

extern "C" void fn_27_264D9C(Node* a, Node* b) {
    a->m14c = b;
    b->m1c = a;
    Node* p = a->m20;
    if (p == nullptr) {
        a->m20 = b;
        return;
    }
    Node* q = p;
    while (q->m24 != nullptr) {
        q = q->m24;
    }
    q->m24 = b;
}
