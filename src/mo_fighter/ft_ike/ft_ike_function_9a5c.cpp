#pragma force_active on
typedef unsigned int u32;

struct Fn119Work {
    char pad[12];
    u32 *values;
};

extern "C" void fn_119_9A5C(Fn119Work *work, u32 value, u32 index)
{
    work->values[index] += value;
}
