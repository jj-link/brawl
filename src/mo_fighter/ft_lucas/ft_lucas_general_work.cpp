#include <so/work/so_general_work_simple.h>

extern "C" const float lbl_114_rodata_8;

// These entries share the general-work storage layout used by Lucas's builder.
extern "C" u32 fn_114_CDA0(const soGeneralWorkSimple* work, u32 mask, u32 index) {
    if (work->m_flagWorks[index] & mask) {
        return 1;
    }
    return 0;
}

extern "C" void fn_114_CDBC(soGeneralWorkSimple* work, u32 mask, u32 index) {
    work->soGeneralWorkSimple::offFlag(mask, index);
}

extern "C" void fn_114_CDD4(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::clearFlag(index);
}

extern "C" void fn_114_CDE8(soGeneralWorkSimple* work, u32 mask, u32 index) {
    work->soGeneralWorkSimple::onFlag(mask, index);
}

extern "C" u32 fn_114_CE00(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getFloatWorkSize();
}

extern "C" void fn_114_CE08(soGeneralWorkSimple* work, float value, u32 index) {
    if (lbl_114_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}

extern "C" void fn_114_CE30(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::mulFloatWork(value, index);
}

extern "C" void fn_114_CE48(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::subFloatWork(value, index);
}

extern "C" void fn_114_CE60(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::addFloatWork(value, index);
}

extern "C" void fn_114_CE78(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::setFloatWork(value, index);
}

extern "C" float fn_114_CE88(const soGeneralWorkSimple* work, u32 index) {
    return work->soGeneralWorkSimple::getFloatWork(index);
}

extern "C" u32 fn_114_CE98(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getIntWorkSize();
}

extern "C" void fn_114_CEA0(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::decIntWork(index);
}

extern "C" void fn_114_CEB8(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::incIntWork(index);
}

extern "C" void fn_114_CED0(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::divIntWork(value, index);
}

extern "C" void fn_114_CEF0(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::mulIntWork(value, index);
}

extern "C" void fn_114_CF08(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::subIntWork(value, index);
}

extern "C" void fn_114_CF20(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::addIntWork(value, index);
}

extern "C" void fn_114_CF38(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::setIntWork(value, index);
}

extern "C" s32 fn_114_CF48(const soGeneralWorkSimple* work, u32 index) {
    return work->soGeneralWorkSimple::getIntWork(index);
}

extern "C" bool fn_114_CF58(const soGeneralWorkSimple*) {
    return false;
}
