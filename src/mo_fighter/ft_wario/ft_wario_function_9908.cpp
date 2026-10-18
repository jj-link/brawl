#pragma force_active on
struct FloatArrayOwner {
    char pad[0x14];
    float *values;
};

extern "C" void fn_110_9908(FloatArrayOwner *owner, int index, float value)
{
    owner->values[index] += value;
}
