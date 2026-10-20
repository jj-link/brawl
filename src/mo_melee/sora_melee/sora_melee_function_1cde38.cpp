#pragma force_active on
struct FnObj {
    char pad[0x18];
    int f18;
};

extern "C" void* fn_27_1CDE38(FnObj* p, int idx) {
    int t = (p->f18 >> 28) + idx;
    if (t >= 4) {
        t -= 4;
    }
    return (char*)p + t * 12 + 0x1c;
}
