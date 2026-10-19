#pragma force_active on
struct Struct52_6F40
{
    int unk0[2];
    int value;
};

extern "C" int fn_52_6F40(Struct52_6F40 *arg)
{
    return arg->value >> 30;
}
