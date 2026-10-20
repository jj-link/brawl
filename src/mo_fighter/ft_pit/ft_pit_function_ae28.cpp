#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct PitParameterTables {
    u8 prefix[0x108];
    const s32* ints[2][8];
};

extern "C" s32 fn_112_AE1C();

extern "C" s32 fn_112_AE28(PitParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_112_AE1C()][parameter - 24000][element];
}
