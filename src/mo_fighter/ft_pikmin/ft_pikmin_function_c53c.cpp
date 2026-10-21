#pragma force_active on

struct PikminParam1 {
    float f0, f4;
};

struct PikminParam2 {
    int i0;
    float f4, f8;
};

struct PikminParam3 {
    float f0, f4;
};

struct PikminAccesser {
    unsigned char pad[0x10];
    float* floats[2][15];
    int* ints[2][2];
};

extern "C" void fn_113_C53C(PikminAccesser* self, const unsigned char* data)
{
    for (int i = 0; i < 2; ++i) {
        self->floats[i][0] = &(*(PikminParam1**)(data + 0x84))->f0;
        self->floats[i][1] = &(*(PikminParam1* const*)(data + 0x84))->f4;
        self->floats[i][2] = &(*(PikminParam2* const*)(data + 0x88))->f4;
        self->floats[i][3] = &(*(PikminParam2* const*)(data + 0x88))->f8;
        self->floats[i][4] = &(*(PikminParam3**)(data + 0x8C))->f0;
        self->floats[i][5] = &(*(PikminParam3* const*)(data + 0x8C))->f4;
        self->floats[i][6] = &(*(PikminParam3**)(data + 0x90))->f0;
        self->floats[i][7] = &(*(PikminParam3* const*)(data + 0x90))->f4;
        self->floats[i][8] = &(*(PikminParam3**)(data + 0x94))->f0;
        self->floats[i][9] = &(*(PikminParam3* const*)(data + 0x94))->f4;
        self->floats[i][10] = &(*(PikminParam3**)(data + 0x98))->f0;
        self->floats[i][11] = &(*(PikminParam3* const*)(data + 0x98))->f4;
        self->floats[i][12] = &(*(PikminParam3**)(data + 0x9C))->f0;
        self->floats[i][13] = &(*(PikminParam3**)(data + 0xA0))->f0;
        self->ints[i][0] = &(*(PikminParam2* const*)(data + 0x88))->i0;
    }
}
