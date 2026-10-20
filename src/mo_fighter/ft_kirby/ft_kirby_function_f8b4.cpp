#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct KirbyParameterTables {
    u8 prefix[0x10];
    const float* floats[2][292];
    const s32* ints[2][79];
};

extern "C" s32 fn_96_F8A8();

extern "C" s32 fn_96_F8B4(KirbyParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_96_F8A8()][parameter - 24000][element];
}
