#pragma force_active on
typedef unsigned int u32;

struct WorkStub {
    char pad[0x14];
    float *m_floatWorks;
};

extern "C" void fn_92_9A90(WorkStub *work, u32 index, float value)
{
    work->m_floatWorks[index] += value;
}
