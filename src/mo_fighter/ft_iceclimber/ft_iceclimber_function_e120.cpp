#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct IceClimberParameterTables {
    u8 prefix[0x10];
    const float* floats[2][61];
    const s32* ints[2][2];
};

extern "C" s32 fn_105_E114();

extern "C" s32 fn_105_E120(IceClimberParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_105_E114()][parameter - 24000][element];
}
