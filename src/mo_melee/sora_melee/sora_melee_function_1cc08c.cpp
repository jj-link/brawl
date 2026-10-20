#pragma force_active on
struct Obj {
    char pad[0x18];
    int val;
};

extern "C" {
void* fn_27_1CC08C(Obj* self, int idx) {
    int n = (self->val >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)self + 0x1c + n * 12;
}
}
