#pragma force_active on
struct fn27Obj {
    char pad[8];
    int f8;
};

extern "C" {
char* fn_27_1B0174(fn27Obj* self, int idx) {
    int i = (self->f8 >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return (char*)self + i * 0xb8 + 0xc;
}
}
