#pragma force_active on
struct fn_27_C97A8_type
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};

extern "C" int fn_27_C97A8(fn_27_C97A8_type* arg)
{
    unsigned int value = arg->unk8;
    value = (value << 4) & 0xE0000000;
    return ((int)value) >> 30;
}
