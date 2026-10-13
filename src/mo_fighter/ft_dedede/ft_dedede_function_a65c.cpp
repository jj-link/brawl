#include <so/work/so_general_work_abstract.h>

// Query through the work interface before clearing an already-set flag.
extern "C" u32 fn_117_A65C(soGeneralWorkAbstract* work, u32 flag, u32 index) {
    u32 result = work->isFlag(flag, index);
    if (result == 1) {
        work->offFlag(flag, index);
    }
    return result;
}
