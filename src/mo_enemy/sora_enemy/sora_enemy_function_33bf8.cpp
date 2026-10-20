#pragma force_active on
struct fn_41_33BF8_Obj {
    char pad[0xa4];
    unsigned char b0 : 1;
    unsigned char flag : 1;
    unsigned char rest : 6;
};

extern "C" bool fn_41_33BF8(fn_41_33BF8_Obj* self)
{
    return self->flag;
}
