#include <types.h>
#pragma force_active on

class soModuleAccesser;

struct PokeParameterTables {
    u8 prefix[0xe8];
    const s32* ints[2][4];
};

extern "C" s32 fn_116_AC5C();

extern "C" s32 fn_116_AC68(PokeParameterTables* tables, soModuleAccesser*, s32 parameter, s32 element) {
    return tables->ints[fn_116_AC5C()][parameter - 24000][element];
}
