#pragma force_active on
typedef unsigned int u32;

typedef struct FtKirbyWork {
    unsigned char pad_00[0x14];
    float *m_floats;
} FtKirbyWork;

extern "C" void fn_96_F4D0(FtKirbyWork *work, u32 index, float value)
{
    work->m_floats[index] -= value;
}
