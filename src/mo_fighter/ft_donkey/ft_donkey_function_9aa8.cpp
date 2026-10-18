#pragma force_active on
typedef unsigned int u32;

struct WorkBlock {
    char pad[0x14];
    float *floatWorks;
};

extern "C" void fn_92_9AA8(WorkBlock *work, float value, u32 index)
{
    work->floatWorks[index] = value;
}
