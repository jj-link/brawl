#pragma force_active on
struct Obj {
    int a;
    int b;
    unsigned int v;
};

extern "C" {
int fn_40_30904(Obj* p) {
    unsigned int r = (p->v << 5) | (p->v >> 27);
    return (int)(r & 0xFC000000) >> 27;
}
}
