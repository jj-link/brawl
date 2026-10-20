#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct SonicParameterTables {
    u8 prefix[0x10];
    const float* floats[2][70];
    const s32* ints[2][12];
};

extern "C" s32 fn_123_A858();

extern "C" s32 fn_123_A864(SonicParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_123_A858()][parameter - 24000][element];
}
