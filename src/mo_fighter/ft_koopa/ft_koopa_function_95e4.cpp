#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct KoopaParameterTables {
    u8 prefix[0x10];
    const float* floats[2][47];
    const s32* ints[2][8];
};

extern "C" s32 fn_102_95D8();

extern "C" s32 fn_102_95E4(KoopaParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_102_95D8()][parameter - 24000][element];
}
