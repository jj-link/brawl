#pragma force_active on
struct Fn67Obj {
    char pad[8];
    int field8;
};

extern "C" void* fn_67_5140(Fn67Obj* p, int index) {
    int t = p->field8 >> 30;
    int n = t + index;
    if (n >= 1) {
        n = n - 1;
    }
    return (char*)p + n * 0x78 + 0xc;
}
