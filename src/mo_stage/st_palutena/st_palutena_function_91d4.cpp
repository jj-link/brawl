#pragma force_active on
#pragma opt_propagation off
#pragma peephole off

extern "C" const float lbl_67_rodata_80[12];

struct State {
    unsigned char pad0[0x190];
    float value190;
    unsigned char pad194[0x3e];
    unsigned char flag1d2;
    unsigned char pad1d3;
    float value1d4;
};

extern "C" void fn_67_91D4(State* self, unsigned int, unsigned int,
                           unsigned int force)
{
    const float* constants = lbl_67_rodata_80;
    unsigned int flag = 0;

    if (constants[0] == self->value1d4)
        flag = 1;

    if (force == 1)
        flag = 1;

    self->value1d4 = constants[10];

    if (constants[2] == self->value190 && flag == 1)
        self->flag1d2 = 1;
}
