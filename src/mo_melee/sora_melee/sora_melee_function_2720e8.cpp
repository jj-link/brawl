#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern const float lbl_27_rodata_4488;
extern const float lbl_27_rodata_448C;

struct V2 {
    float x, y;
    V2() {}
    V2(float a, float b) : x(a), y(b) {}
    V2& operator=(const V2& o) { x = o.x; y = o.y; return *this; }
};

struct Elem {
    u32 a;
    V2 p;
    float d;
    s32 e;
    u8 f;
    s32 g;
    u8 h;
    Elem() {
        a = 0;
        p = V2(lbl_27_rodata_4488, lbl_27_rodata_4488);
        d = lbl_27_rodata_448C;
        e = -1;
        f = 0;
        g = -1;
        h = 1;
    }
};

struct Node {
    Node* next;
    Node* link;
    Elem* value;
};

struct List {
    u8 pad[4];
    Node* head;
    Node* tail;
    Node* cur;
    s32 count;
};

extern "C" void fn_27_2720E8(List* self, const Elem& src) {
    Elem* e = new (__nw__FUlQ25Heaps8HeapType(0x20, 0xF)) Elem;
    *e = src;
    if (self->head == 0) {
        Node* n = (Node*)__nw__FUlQ25Heaps8HeapType(0xC, 0xF);
        if (n != 0) {
            n->next = 0;
            n->link = 0;
        }
        self->cur = n;
        self->tail = n;
        self->head = n;
        n->value = e;
    } else {
        Node* n = (Node*)__nw__FUlQ25Heaps8HeapType(0xC, 0xF);
        if (n != 0) {
            n->next = 0;
            n->link = 0;
        }
        self->tail->link = n;
        self->tail->link->value = e;
        self->tail->link->next = self->tail;
        self->tail = self->tail->link;
    }
    self->count = self->count + 1;
}
