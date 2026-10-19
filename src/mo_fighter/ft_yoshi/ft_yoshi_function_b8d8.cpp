#pragma force_active on
struct YoshiFloatWork
{
    unsigned char padding[0x14];
    float* values;
};

extern "C" void fn_95_B8D8(YoshiFloatWork* work, unsigned int index, float value)
{
    work->values[index] = value;
}
