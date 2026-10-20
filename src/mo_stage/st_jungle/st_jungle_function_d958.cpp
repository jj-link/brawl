#pragma force_active on
union Src {
    unsigned raw;
    struct {
        unsigned : 29;
        unsigned v : 3;
    } bits;
};
struct Dst {
    unsigned v : 3;
    unsigned : 29;
};

extern "C" void fn_51_D958(void* base, unsigned s) {
    Src src;
    src.raw = s;
    Dst* p = (Dst*)((unsigned*)base + 2);
    p->v = src.bits.v;
}
