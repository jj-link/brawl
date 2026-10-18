#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

struct GeneralWork {
    int padding[3];
    s32 *m_intWorks;
};

extern "C" void fn_113_CD5C(GeneralWork *work, s32 value, u32 index) {
    if (value != 0) {
        work->m_intWorks[index] /= value;
    }
}
