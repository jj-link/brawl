#pragma force_active on
typedef unsigned int u32;

typedef struct FtWork {
    char pad[0x14];
    float *m_values;
} FtWork;

extern "C" void fn_93_B2B4(FtWork *work, u32 index, float value) {
    work->m_values[index] -= value;
}
