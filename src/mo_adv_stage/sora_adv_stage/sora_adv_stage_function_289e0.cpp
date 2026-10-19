#pragma force_active on
struct Obj {
    char pad[8];
    int f8;
};

extern "C" {
void* fn_40_289E0(Obj* p, int idx) {
    int i = (p->f8 >> 28) + idx;
    if (i >= 7) {
        i -= 7;
    }
    return (char*)p + (i << 3) + 0xc;
}
}
