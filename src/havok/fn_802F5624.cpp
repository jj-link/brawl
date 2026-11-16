#include <types.h>
#pragma force_active on

extern "C" void fn_80281D60(void*, const void*, unsigned int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* lbl_805A0EC8;

struct Rec;
struct Obj;
struct P;
struct Node {
    u16 type, size;
    u8 pad[4];
    Node* next;
};
struct A {
    u8 pad0[0xC];
    s32 f0C, f10, f14, f18, f1C;
    u8 pad20[6];
    u8 flags : 2;
    u8 rest : 6;
};
struct Rec {
    Obj* f00;
    P* f04[2];
    Node* f0C;
    u16 f10;
    u8 f12;
    u16 f14, f16, f18;
    u8 f1A, f1B;
    u16 f1C, f1E;
    char* f20;
};
struct P {
    u8 pad0[0x6C];
    Rec* f6C;
    s32 f70;
    u8 pad74[4];
    Obj** f78;
    s32 f7C;
    u8 pad80[4];
    char* f84;
    s32 f88;
};
class Obj {
public:
    virtual void slot0(int);
    u16 f04;
    s16 f06;
    A* f08;
    u8 pad0C[0x1C];
    Rec* f28;
};

inline void subtract(Rec* p, u16 x, u16 y, u16 z) {
    if (p) {
        int a = p->f18 - z;
        int b = p->f16 - y;
        int c = p->f14 - x;
        p->f18 = a;
        p->f14 = c;
        p->f16 = b;
    }
}

extern "C" void fn_802F5624(Obj* self) {
    P* p;
    s32 negE;
    u16 x, y, z;
    Rec* m;
    A* a;
    A* b;
    a = self->f08;
    Rec* n = self->f28;
    a->flags = 1;
    x = n->f14;
    y = n->f16;
    z = n->f18;
    b = self->f08;
    b->f0C -= x;
    b->f10 -= y;
    b->f14 -= z;
    m = self->f28;
    subtract(m, x, y, z);
    a->f1C--;
    self->f08 = 0;

    P* q;
    Obj** arr;
    u16 idx = n->f1C;
    q = n->f04[1 - n->f1A];
    arr = q->f78;
    u32 last = q->f7C - 1;
    Obj* item = arr[last];
    arr[idx] = item;
    q->f7C--;
    item->f28->f1C = idx;

    p = n->f04[n->f1A];
    negE = 0;
    if (n->f20) {
        u16 size = n->f1E;
        char* end = n->f20 + size;
        negE = -size;
        fn_80281D60(n->f20, end, (p->f84 + p->f88) - end);
        p->f88 -= n->f1E;
        n->f20 = 0;
    }
    Node* it = n->f0C;
    while (1) {
        if ((int)it->type < 0x17) break;
        Node* cur = it;
        it = it->next;
        fn_8027EABC(lbl_805A0EC8, cur, cur->size, 0x2a);
    }
    *(s32*)((u8*)n->f00 + 0x10) = 0;
    n->f0C = 0;
    self->f28 = 0;

    Rec* end = p->f6C + (p->f70 - 1);
    for (; n < end; ++n) {
        *n = *(n + 1);
        n->f00->f28 = n;
        n->f20 = n->f20 ? n->f20 + negE : 0;
    }
    p->f70--;
    if (self->f04) {
        if (--self->f06 == 0 && self != 0) {
            self->slot0(1);
        }
    }
}
