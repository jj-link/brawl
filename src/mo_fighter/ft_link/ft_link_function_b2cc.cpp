#pragma force_active on
struct FnWork {
    char pad[0x14];
    float *values;
};

extern "C" void fn_93_B2CC(FnWork *work, unsigned int index, float value)
{
    work->values[index] += value;
}
