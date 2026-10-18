#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" float fn_112_AA84(const soGeneralWorkSimple* work, u32 index) {
    return work->soGeneralWorkSimple::getFloatWork(index);
}
