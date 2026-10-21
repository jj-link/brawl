#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" const float lbl_93_rodata_C;

inline s32 minimumSize(const s32& size, const u32& limit) {
    return size >= limit ? limit : size;
}

extern "C" void fn_93_48C8(soGeneralWorkSimple* work) {
    s32 intIndex;
    s32 intWorkSize = work->m_intWorkSize;
    intWorkSize = minimumSize(intWorkSize, work->m_intWorkSize);
    for (intIndex = 0; intIndex < intWorkSize; intIndex++) {
        work->m_intWorks[intIndex] = 0;
    }

    s32 floatIndex;
    s32 floatWorkSize = work->m_floatWorkSize;
    floatWorkSize = minimumSize(floatWorkSize, work->m_floatWorkSize);
    for (floatIndex = 0; floatIndex < floatWorkSize; floatIndex++) {
        work->m_floatWorks[floatIndex] = lbl_93_rodata_C;
    }

    s32 flagIndex;
    s32 flagWorkSize = work->m_flagWorkSize;
    flagWorkSize = minimumSize(flagWorkSize, work->m_flagWorkSize);
    for (flagIndex = 0; flagIndex < flagWorkSize; flagIndex++) {
        work->m_flagWorks[flagIndex] = 0;
    }
}
