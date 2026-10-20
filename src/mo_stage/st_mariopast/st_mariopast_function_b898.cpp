#pragma force_active on
extern "C" int fn_48_B898(const unsigned int *arg)
{
    unsigned int value = arg[2];
    value = (value << 7) & 0xFF000000u;
    return (int)value >> 25;
}
