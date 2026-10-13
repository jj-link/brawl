#include <so/work/so_general_work_simple.h>

// Interface accessor: return the float work entry count (m_floatWorkSize) stored at +0x18.
extern "C" u32 fn_117_A730(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getFloatWorkSize();
}
