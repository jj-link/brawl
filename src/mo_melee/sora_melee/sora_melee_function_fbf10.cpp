#pragma force_active on
struct fn27Obj {
    char pad[0x18];
    int flags;
};

extern "C" void* fn_27_FBF10(fn27Obj* p, int idx) {
    int n = (p->flags >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)p + 0x1c + n * 12;
}
