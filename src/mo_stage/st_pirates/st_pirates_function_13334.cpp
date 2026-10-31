#pragma force_active on
struct Matrix { float m[3][4]; };
struct Object {
    char pad[0x160];
    Matrix* source;
    unsigned int field164;
    Matrix matrix;
};
extern "C" const float lbl_52_rodata_328[];
extern "C" void fn_8003F074(Matrix*, float, float, float);
extern "C" void fn_52_13334(Object* self) {
    const float* constants = lbl_52_rodata_328;
    Matrix* source = self->source;
    if (!source) return;
    self->matrix = *source;
    return fn_8003F074(&self->matrix, constants[19], constants[15], constants[7]);
}
