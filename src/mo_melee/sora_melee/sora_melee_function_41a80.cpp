#pragma force_active on
struct Fn27Obj {
    char pad[8];
    int field8;
};

extern "C" void* fn_27_41A80(Fn27Obj* self, int idx) {
    int n = (self->field8 >> 28) + idx;
    if (n >= 6) {
        n -= 6;
    }
    return (char*)self + 12 + (n << 3);
}
