#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct ZakoParameterTables {
    u8 prefix[0x20];
    const s32* ints[2][1];
};

extern "C" s32 fn_126_7974();

extern "C" s32 fn_126_7980(ZakoParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_126_7974()][parameter - 24000][element];
}
