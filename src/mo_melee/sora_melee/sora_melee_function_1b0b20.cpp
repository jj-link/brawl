#pragma force_active on
struct Obj {
    char pad[8];
    int unk8;
};

extern "C" void* fn_27_1B0B20(Obj* self, int n) {
    int r = (self->unk8 >> 28) + n;
    if (r >= 5) {
        r -= 5;
    }
    return (char*)self + (r * 16) + 12;
}
