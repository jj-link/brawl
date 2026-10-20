#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct FalcoParameterTables {
    u8 prefix[0x10];
    const float* floats[2][28];
    const s32* ints[2][12];
};

extern "C" s32 fn_108_B5E8();

extern "C" s32 fn_108_B5F4(FalcoParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_108_B5E8()][parameter - 24000][element];
}
