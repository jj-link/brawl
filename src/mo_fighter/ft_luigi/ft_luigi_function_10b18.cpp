#include <types.h>

// The parameter table begins at 0x18; its extent belongs to the caller.
struct LuigiFloatParamTable {
    u8 storage[0x10];
    u32 firstParameter;
};

extern "C" float fn_99_10B18(const LuigiFloatParamTable* object, void*,
                            u32 parameter, u32 element) {
    const u8* slot = reinterpret_cast<const u8*>(object) + 0x18
                   + (parameter - object->firstParameter) * sizeof(float*);
    const float* values = *reinterpret_cast<const float* const*>(slot);
    return values[element];
}
