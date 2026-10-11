#include <so/work/so_general_work_simple.h>

extern "C" const float lbl_111_rodata_8;

// These entries share the general-work storage layout used by Meta Knight's builder.
extern "C" u32 fn_111_8848(const soGeneralWorkSimple* work, u32 mask, u32 index) {
    if (work->m_flagWorks[index] & mask) {
        return 1;
    }
    return 0;
}

extern "C" void fn_111_8864(soGeneralWorkSimple* work, u32 mask, u32 index) {
    work->soGeneralWorkSimple::offFlag(mask, index);
}

extern "C" void fn_111_887C(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::clearFlag(index);
}

extern "C" void fn_111_8890(soGeneralWorkSimple* work, u32 mask, u32 index) {
    work->soGeneralWorkSimple::onFlag(mask, index);
}

extern "C" u32 fn_111_88A8(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getFloatWorkSize();
}

extern "C" void fn_111_88B0(soGeneralWorkSimple* work, float value, u32 index) {
    if (lbl_111_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}

extern "C" void fn_111_88D8(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::mulFloatWork(value, index);
}

extern "C" void fn_111_88F0(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::subFloatWork(value, index);
}

extern "C" void fn_111_8908(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::addFloatWork(value, index);
}

extern "C" void fn_111_8920(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::setFloatWork(value, index);
}

extern "C" float fn_111_8930(const soGeneralWorkSimple* work, u32 index) {
    return work->soGeneralWorkSimple::getFloatWork(index);
}

extern "C" u32 fn_111_8940(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getIntWorkSize();
}

extern "C" void fn_111_8948(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::decIntWork(index);
}

extern "C" void fn_111_8960(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::incIntWork(index);
}

extern "C" void fn_111_8978(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::divIntWork(value, index);
}

extern "C" void fn_111_8998(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::mulIntWork(value, index);
}

extern "C" void fn_111_89B0(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::subIntWork(value, index);
}

extern "C" void fn_111_89C8(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::addIntWork(value, index);
}

extern "C" void fn_111_89E0(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::setIntWork(value, index);
}

extern "C" s32 fn_111_89F0(const soGeneralWorkSimple* work, u32 index) {
    return work->soGeneralWorkSimple::getIntWork(index);
}

extern "C" bool fn_111_8A00(const soGeneralWorkSimple*) {
    return false;
}
