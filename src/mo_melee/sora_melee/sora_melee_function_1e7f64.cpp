#pragma force_active on
struct fn27Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
void* fn_27_1E7F64(fn27Obj* self, int idx) {
    int n = (self->unk8 >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)self + n * 12 + 12;
}
}
