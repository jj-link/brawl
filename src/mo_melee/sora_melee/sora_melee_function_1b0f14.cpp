#pragma force_active on
struct Fn27Base {
    char pad[8];
    int unk8;
};

extern "C" {
char* fn_27_1B0F14(Fn27Base* self, int idx) {
    int n = (self->unk8 >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return (char*)self + n * 20 + 0xc;
}
}
