#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct LinkParameterTables {
    u8 prefix[0xB8];
    const s32* ints[2][6];
};

extern "C" s32 fn_93_B68C();

extern "C" s32 fn_93_B698(LinkParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_93_B68C()][parameter - 24000][element];
}
