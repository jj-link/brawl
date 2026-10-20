#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct GanonParameterTables {
    u8 prefix[0x10];
    const float* floats[2][27];
    const s32* ints[2][2];
};

extern "C" s32 fn_109_964C();

extern "C" s32 fn_109_9658(GanonParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_109_964C()][parameter - 24000][element];
}
