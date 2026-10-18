#include <so/work/so_general_work_abstract.h>
#include <so/work/so_general_work_simple.h>
#include <types.h>
#pragma force_active on

// Local view of the caller's float-work block: the pointer handed in in r3
// keeps its float array behind a pointer at +0x14 (same layout as the
// soGeneralWorkSimple base block), and the value at 'index' is returned.
struct GanonWork {
    u32 m_unk0[5];
    float* m_floatWorks;
};

extern "C" float fn_109_92B4(const GanonWork* work, u32 index) {
    return work->m_floatWorks[index];
}
