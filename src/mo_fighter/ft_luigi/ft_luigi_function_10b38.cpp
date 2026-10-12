#include <types.h>

// Integer parameter arrays follow the header at 0x20; the caller owns their extent.
struct LuigiIntegerParamTable {
    u8 storage[0x14];
    u32 firstParameter;
};

extern "C" u32 fn_99_10B38(const LuigiIntegerParamTable* object, void*,
                          u32 parameter, u32 element) {
    const u8* slot = reinterpret_cast<const u8*>(object) + 0x20
                   + (parameter - object->firstParameter) * sizeof(u32*);
    const u32* values = *reinterpret_cast<const u32* const*>(slot);
    return values[element];
}
