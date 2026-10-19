#pragma force_active on
struct Unk49_6C10
{
    unsigned char pad[8];
    int field;
};

extern "C" int fn_49_6C10(const Unk49_6C10 *arg)
{
    return arg->field >> 30;
}
