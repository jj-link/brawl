#pragma force_active on
struct State {
    unsigned char padding[0x164];
    unsigned char first : 1;
    unsigned char flag : 1;
    unsigned char rest : 6;
};

extern "C" void fn_27_1CA98(State* self, unsigned int value)
{
    self->flag = value;
}
