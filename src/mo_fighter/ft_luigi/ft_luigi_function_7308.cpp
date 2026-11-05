#include <so/work/so_general_work_simple.h>

extern "C" const float lbl_99_rodata_8;

// decomp-orchestrator: begin fn_99_7308
// decomp-orchestrator: it replaces the file's own definition:
//| extern "C" void fn_99_7308(soGeneralWorkSimple* work) {
//|     s32 intWorkSize = work->m_intWorkSize;
//|     intWorkSize = (intWorkSize != work->m_intWorkSize) ? work->m_intWorkSize : intWorkSize;
//|     for (s32 i = 0; i < intWorkSize; i++) {
//|         work->m_intWorks[i] = 0;
//|     }
//|
//|     s32 floatWorkSize = work->m_floatWorkSize;
//|     floatWorkSize = (floatWorkSize != work->m_floatWorkSize) ? work->m_floatWorkSize : floatWorkSize;
//|     for (s32 i = 0; i < floatWorkSize; i++) {
//|         work->m_floatWorks[i] = lbl_99_rodata_8;
//|     }
//|
//|     s32 flagWorkSize = work->m_flagWorkSize;
//|     flagWorkSize = (flagWorkSize != work->m_flagWorkSize) ? work->m_flagWorkSize : flagWorkSize;
//|     for (s32 i = 0; i < flagWorkSize; i++) {
//|         work->m_flagWorks[i] = 0;
//|     }
//| }
#include <so/work/so_general_work_simple.h>
#pragma force_active on
namespace decomp_orch_fn_99_7308 {
extern "C" const float lbl_99_rodata_8;

static inline void clearInts(soGeneralWorkSimple* work, const s32& count) {
    s32 size = count;
    if ((u32)size >= work->m_intWorkSize)
        size = work->m_intWorkSize;
    for (s32 i = 0; i < size; ++i)
        work->m_intWorks[i] = 0;
}

static inline void clearFloats(soGeneralWorkSimple* work, const s32& count) {
    s32 size = count;
    if ((u32)size >= work->m_floatWorkSize)
        size = work->m_floatWorkSize;
    for (s32 i = 0; i < size; ++i)
        work->m_floatWorks[i] = lbl_99_rodata_8;
}

static inline void clearFlags(soGeneralWorkSimple* work, const s32& count) {
    s32 size = count;
    if ((u32)size >= work->m_flagWorkSize)
        size = work->m_flagWorkSize;
    for (s32 i = 0; i < size; ++i)
        work->m_flagWorks[i] = 0;
}

extern "C" void fn_99_7308(soGeneralWorkSimple* work) {
    clearInts(work, reinterpret_cast<const s32&>(work->m_intWorkSize));
    clearFloats(work, reinterpret_cast<const s32&>(work->m_floatWorkSize));
    clearFlags(work, reinterpret_cast<const s32&>(work->m_flagWorkSize));
}
}  // namespace decomp_orch_fn_99_7308
using decomp_orch_fn_99_7308::fn_99_7308;
// decomp-orchestrator: end fn_99_7308
