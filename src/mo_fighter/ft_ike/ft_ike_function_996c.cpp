#pragma force_active on
typedef unsigned int u32;

struct FtIkeWork {
    char pad[0x14];
    float* m_values;
};

extern "C" void fn_119_996C(FtIkeWork* work, u32 index, float value)
{
    work->m_values[index] *= value;
}
