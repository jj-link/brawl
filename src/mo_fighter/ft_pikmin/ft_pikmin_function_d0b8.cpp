#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct PikminParameterTables {
    u8 prefix[0x88];
    const s32* ints[2][2];
};

extern "C" s32 fn_113_D0AC();

extern "C" s32 fn_113_D0B8(PikminParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_113_D0AC()][parameter - 24000][element];
}
