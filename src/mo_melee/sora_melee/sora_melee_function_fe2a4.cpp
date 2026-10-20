#pragma force_active on
struct S {
    char pad[8];
    int f8;
};

extern "C" char* fn_27_FE2A4(S* self, int idx) {
    int i = (self->f8 >> 26) + idx;
    if (i >= 19) {
        i -= 19;
    }
    return (char*)self + 0xc + i * 8;
}
