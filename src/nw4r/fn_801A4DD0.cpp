#pragma force_active on
typedef unsigned int u32;

struct Obj {
    int unk0;
    float* unk4;
    u32* unk8;
};

extern float lbl_805A3348;

extern "C" void fn_801A4DD0(Obj* self, float f1, float f2, float f3) {
    self->unk4[0] = f1;
    self->unk4[1] = f2;
    self->unk4[2] = f3;
    if (f1 == f2 && f1 == f3) {
        if (lbl_805A3348 == f1) {
            *self->unk8 |= 0x40000000;
            return;
        }
        *self->unk8 |= 0x10000000;
        *self->unk8 &= 0x3FFFFFFF;
        return;
    }
    *self->unk8 &= 0x0FFFFFFF;
}
