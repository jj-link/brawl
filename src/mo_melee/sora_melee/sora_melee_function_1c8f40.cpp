#pragma force_active on
struct Obj {
    char pad[0x18];
    int f18;
};

extern "C" void* fn_27_1C8F40(Obj* self, int idx) {
    int t = self->f18 >> 30;
    int n = t + idx;
    if (n >= 1) {
        n -= 1;
    }
    return (char*)self + n * 12 + 0x1c;
}
