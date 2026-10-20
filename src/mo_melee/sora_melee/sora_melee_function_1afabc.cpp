#pragma force_active on
struct Fn27Obj {
    char pad[8];
    int unk8;
};

extern "C" void* fn_27_1AFABC(Fn27Obj* self, int idx) {
    int n = (self->unk8 >> 27) + idx;
    if (n >= 15) {
        n -= 15;
    }
    return (char*)self + 12 + n * 4;
}
