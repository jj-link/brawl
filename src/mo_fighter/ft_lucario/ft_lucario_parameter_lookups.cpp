#include <types.h>

// These category-specific views expose only the offsets and inline pointer tables
// used by the module's parameter callbacks; table storage remains externally owned.
struct LucarioFloatParameters {
    unsigned char prefix[0x10];
    s32 offset;
    u32 reserved;
    const float* entries[1];
};
struct LucarioIntParameters {
    unsigned char prefix[0x14];
    s32 offset;
    u32 reserved[2];
    const s32* entries[1];
};
struct LucarioIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[2];
    void* entries[1];
};

extern "C" float fn_118_13E40(const LucarioFloatParameters* object, void*, s32 selector, s32 index) {
    return object->entries[selector - object->offset][index];
}
extern "C" s32 fn_118_13E60(const LucarioIntParameters* object, void*, s32 selector, s32 index) {
    return object->entries[selector - object->offset][index];
}
extern "C" void* fn_118_13E80(const LucarioIndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
