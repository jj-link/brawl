#pragma force_active on
struct fn27Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" void* fn_27_390294(fn27Obj* self, int p) {
    int r = self->unk8 >> 29;
    int idx = r + p;
    if (idx >= 2) {
        idx -= 2;
    }
    return (char*)self + (idx << 6) + 0xc;
}
