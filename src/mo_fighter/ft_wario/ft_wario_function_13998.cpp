#include <types.h>
#pragma force_active on

namespace {
struct WarioTraversalIndex {
    short value;
};

struct WarioTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    unsigned char disabled;
};
}

extern "C" {
void fn_110_14BF8(void*, void*);
void fn_110_13A28(WarioTraversalIndex*, const WarioTraversalIndex*);
void fn_110_138C8(void*, const WarioTraversalIndex*, void*);
}

extern "C" void fn_110_13998(void* object, const WarioTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    WarioTraversalEntry* entry = reinterpret_cast<WarioTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        static_cast<unsigned int>(entry->enabled != 0) == 1 &&
        entry->disabled == 0)
        fn_110_14BF8(entry, argument);

    WarioTraversalIndex operation;
    fn_110_13A28(&operation, index);
    fn_110_138C8(composite + 4, &operation, argument);
}
