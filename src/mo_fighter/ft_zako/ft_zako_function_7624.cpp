#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct FtWorkSimple {
    char pad[12];
    s32 *m_intWorks;
};

extern "C" void fn_126_7624(FtWorkSimple *work, s32 value, u32 index) {
    if (0 != value) {
        work->m_intWorks[index] /= value;
    }
}
