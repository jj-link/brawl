#pragma force_active on
typedef unsigned int u32;

struct FloatArrayHolder {
    char pad[0x14];
    float *values;
};

extern "C" void fn_109_928C(FloatArrayHolder *self, u32 index, float value)
{
    self->values[index] += value;
}
