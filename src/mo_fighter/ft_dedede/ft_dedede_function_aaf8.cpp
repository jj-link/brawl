#include <types.h>

// ABI view of ftExtendParamAccesserEx<3999, 41, 23999, 14>.
struct DededeParameterTables {
    u8 prefix[0x10];
    const float* floats[2][42];
    const s32* ints[2][15];
};

extern "C" s32 fn_117_AB50();

extern "C" float fn_117_AAF8(DededeParameterTables* tables, void*, s32 parameter, s32 element) {
    return tables->floats[fn_117_AB50()][parameter - 4000][element];
}
