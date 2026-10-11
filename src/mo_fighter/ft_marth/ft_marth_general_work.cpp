#include <so/work/so_general_work_simple.h>

extern "C" const float lbl_106_rodata_8;

// These entries share the general-work storage layout used by Marth's builder.
extern "C" u32 fn_106_8218(const soGeneralWorkSimple* work, u32 mask, u32 index) {
    if (work->m_flagWorks[index] & mask) {
        return 1;
    }
    return 0;
}

extern "C" void fn_106_8234(soGeneralWorkSimple* work, u32 mask, u32 index) {
    work->soGeneralWorkSimple::offFlag(mask, index);
}

extern "C" void fn_106_824C(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::clearFlag(index);
}

extern "C" void fn_106_8260(soGeneralWorkSimple* work, u32 mask, u32 index) {
    work->soGeneralWorkSimple::onFlag(mask, index);
}

extern "C" u32 fn_106_8278(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getFloatWorkSize();
}

extern "C" void fn_106_8280(soGeneralWorkSimple* work, float value, u32 index) {
    if (lbl_106_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}

extern "C" void fn_106_82A8(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::mulFloatWork(value, index);
}

extern "C" void fn_106_82C0(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::subFloatWork(value, index);
}

extern "C" void fn_106_82D8(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::addFloatWork(value, index);
}

extern "C" void fn_106_82F0(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::setFloatWork(value, index);
}

extern "C" float fn_106_8300(const soGeneralWorkSimple* work, u32 index) {
    return work->soGeneralWorkSimple::getFloatWork(index);
}

extern "C" u32 fn_106_8310(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getIntWorkSize();
}

extern "C" void fn_106_8318(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::decIntWork(index);
}

extern "C" void fn_106_8330(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::incIntWork(index);
}

extern "C" void fn_106_8348(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::divIntWork(value, index);
}

extern "C" void fn_106_8368(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::mulIntWork(value, index);
}

extern "C" void fn_106_8380(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::subIntWork(value, index);
}

extern "C" void fn_106_8398(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::addIntWork(value, index);
}

extern "C" void fn_106_83B0(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::setIntWork(value, index);
}

extern "C" s32 fn_106_83C0(const soGeneralWorkSimple* work, u32 index) {
    return work->soGeneralWorkSimple::getIntWork(index);
}

extern "C" bool fn_106_83D0(const soGeneralWorkSimple*) {
    return false;
}
