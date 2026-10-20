#pragma force_active on
struct Fn27Obj {
    int pad[2];
    int flags;
};

extern "C" void* fn_27_1AFE2C(Fn27Obj* p, int idx) {
    int sum = (p->flags >> 22) + idx;
    if (sum >= 0x11f) {
        sum -= 0x11f;
    }
    return (char*)p + sum * 4 + 0xc;
}
