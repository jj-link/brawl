#pragma force_active on
typedef unsigned int u32;

typedef struct Work {
    char pad[0x14];
    float *floats;
} Work;

extern "C" void fn_105_DD3C(Work *work, u32 index, float value)
{
    work->floats[index] -= value;
}
