#include <types.h>

// ABI views of the weapon parameter tables. Each lookup uses its own base
// index and array of parameter rows; the caller supplies the row element.
struct PikachuFloatParameters {
    u8 prefix[0x10];
    s32 first;
    s32 reserved;
    const float* rows[9];
};
struct PikachuIntParameters {
    u8 prefix[0x14];
    s32 first;
    u8 reserved[0x24];
    const s32* rows[2];
};
struct PikachuIndefiniteParameters {
    u8 prefix[0x18];
    s32 first;
    u8 reserved[0x28];
    void* rows[1];
};

extern "C" float fn_98_1BA7C(const PikachuFloatParameters* parameters, void*, s32 index, s32 element) {
    return parameters->rows[index - parameters->first][element];
}
extern "C" s32 fn_98_1BA9C(const PikachuIntParameters* parameters, void*, s32 index, s32 element) {
    return parameters->rows[index - parameters->first][element];
}
extern "C" void* fn_98_1BABC(const PikachuIndefiniteParameters* parameters, void*, s32 index, s32) {
    return parameters->rows[index - parameters->first];
}
