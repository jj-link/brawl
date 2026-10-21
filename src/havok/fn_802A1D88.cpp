#pragma force_active on

struct Entry {
    short a;
    short b;
    Entry() { b = 0; }
};

struct State {
    Entry entries[8];
    unsigned char f20, f21, f22;
};

extern "C" void fn_802A1D88(State *p) {
    p->entries[0].b = 0;
    for (Entry *q = p->entries + 1; q < p->entries + 8; ++q)
        q->b = 0;
    p->f21 = 0;
    p->f20 = 0;
    p->f22 = 0;
}
