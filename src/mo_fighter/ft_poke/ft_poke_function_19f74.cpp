#include <types.h>
#pragma force_active on

struct PokeEntry {
    unsigned char padding[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char disabled;
};

extern "C" void fn_116_1ACAC(PokeEntry*, void*);
extern "C" s16* fn_116_1A34C(s16*, const s16*);
extern "C" s32 fn_116_1A004(void*, const s16*, void*);

extern "C" void fn_116_19F74(void* object, const s16* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    PokeEntry* entry = reinterpret_cast<PokeEntry*>(composite + 0xC);

    if (((*index) & 1) != 0 &&
        (entry->enabled ? 1u : 0u) == 1u &&
        entry->disabled == 0)
        fn_116_1ACAC(entry, argument);

    s16 operation;
    fn_116_1A34C(&operation, index);
    fn_116_1A004(composite + 4, &operation, argument);
}
