#include <types.h>

// The parameter table begins at 0x2C; its extent belongs to the caller.
struct LuigiIndefiniteParamTable {
    u8 storage[0x18];
    u32 firstParameter;
};

extern "C" void* fn_99_10B58(const LuigiIndefiniteParamTable* object, void*,
                            u32 parameter, u32) {
    const u8* slot = reinterpret_cast<const u8*>(object) + 0x2C
                   + (parameter - object->firstParameter) * sizeof(void*);
    return *reinterpret_cast<void* const*>(slot);
}
