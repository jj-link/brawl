#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
void* fn_27_1CF740(Obj* self, int idx) {
    int r = (self->unk8 >> 27) + idx;
    if (r >= 8) {
        r -= 8;
    }
    return (char*)self + r * 12 + 12;
}
}
