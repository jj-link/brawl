#pragma force_active on
struct FloatWorkHolder {
    char pad[0x14];
    float *floatWorks;
};

extern "C" void fn_107_C5D8(FloatWorkHolder *work, float value, unsigned int index)
{
    work->floatWorks[index] += value;
}
