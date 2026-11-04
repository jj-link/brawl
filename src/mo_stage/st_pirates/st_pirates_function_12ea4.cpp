#pragma force_active on
struct Matrix {
    unsigned int v[12];
};

struct Object {
    char pad[0x160];
    Matrix* src;
    unsigned char* data;
    Matrix matrix;
    unsigned char state;
};

extern "C" const float lbl_52_rodata_328[];
extern "C" void fn_8003F074(Matrix*, float, float, float);

extern "C" void fn_52_12EA4(Object* self) {
    const float* constants = lbl_52_rodata_328;

    if (Matrix* src = self->src) {
        self->matrix = *src;

        switch (self->state) {
        case 0:
            if (self->data[0] == 0)
                fn_8003F074(&self->matrix, constants[8], constants[9], constants[7]);
            else if (self->data[0] == 1)
                fn_8003F074(&self->matrix, constants[10], constants[9], constants[7]);
            break;

        case 1:
            if (self->data[0] == 0)
                fn_8003F074(&self->matrix, constants[11], constants[12], constants[7]);
            else if (self->data[0] == 1)
                fn_8003F074(&self->matrix, constants[13], constants[9], constants[7]);
            break;
        }
    }
}
