#include <types.h>
#pragma force_active on

namespace {
struct ZeldaTraversalIndex {
    s16 value;
};
struct ZeldaTraversalEntry {
    unsigned char data[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    unsigned char disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_104_D5F0(ZeldaTraversalEntry*, void*);
void fn_104_DC48(ZeldaTraversalIndex*, const ZeldaTraversalIndex*);
s32 fn_104_D6D0(void*, const ZeldaTraversalIndex*, void*);
}

extern "C" s32 fn_104_D640(void* object, const ZeldaTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    ZeldaTraversalEntry* entry = reinterpret_cast<ZeldaTraversalEntry*>(composite + 0xC);
    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_104_D5F0(entry, argument);

    ZeldaTraversalIndex operation;
    fn_104_DC48(&operation, index);
    return fn_104_D6D0(composite + 4, &operation, argument);
}
