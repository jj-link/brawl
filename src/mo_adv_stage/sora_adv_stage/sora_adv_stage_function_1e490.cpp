#pragma force_active on
struct Obj {
    char pad[8];
    int flags;
};

extern "C" {
void* fn_40_1E490(Obj* p, int idx) {
    int n = (p->flags >> 26) + idx;
    if (n >= 0x18) {
        n -= 0x18;
    }
    return (char*)p + n * 0x38 + 0xc;
}
}
