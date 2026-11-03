#pragma force_active on
struct Base {
    char pad[0x2c];
    unsigned count;
    int off;
    char pad2[8];
    unsigned flags1;
    char pad3[0x100];
    unsigned flags2;
};

struct Ent {
    int pad0, pad4;
    int a;
    int b;
    int idx;
    char pad[0x34 - 0x14];
};

struct Holder {
    Base* p;
};

static inline void clear_bit(unsigned* p, int idx) {
    if (p && idx >= 0 && idx <= 7) {
        *p &= ~(1u << idx);
    }
}

extern "C" void fn_80192080(Holder* h) {
    unsigned n = h->p->count;
    Base* b;
    char* d;
    unsigned* p1;
    unsigned* p2;
    Ent* e;
    unsigned offset = 0;
    for (unsigned i = 0; i < n; i++) {
        b = h->p;
        d = b->off ? (char*)b + b->off : 0;
        p1 = (unsigned*)((char*)b + 0x3c);
        p2 = (unsigned*)((char*)b + 0x140);
        e = (Ent*)(d + offset);
        e->a = 0;
        e->b = 0;
        clear_bit(p1, e->idx);
        clear_bit(p2, e->idx);
        offset += 0x34;
    }
}
