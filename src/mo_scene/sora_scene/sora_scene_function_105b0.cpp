#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct Node {
    Node* next;
    Node* link;
    s32 value;
};

struct List {
    u8 pad[4];
    Node* head;
    Node* tail;
    Node* cur;
    s32 count;
};

extern "C" void fn_1_105B0(List* self, s32 value) {
    Node* n;
    if (self->head == 0) {
        n = (Node*)__nw__FUlQ25Heaps8HeapType(0xC, 0x2A);
        if (n != 0) {
            n->next = 0;
            n->link = 0;
        }
        self->cur = n;
        self->tail = n;
        self->head = n;
        n->value = value;
    } else {
        n = (Node*)__nw__FUlQ25Heaps8HeapType(0xC, 0x2A);
        if (n != 0) {
            n->next = 0;
            n->link = 0;
        }
        self->tail->link = n;
        self->tail->link->value = value;
        n = self->tail;
        n->link->next = n;
        self->tail = self->tail->link;
    }
    self->count = self->count + 1;
}
