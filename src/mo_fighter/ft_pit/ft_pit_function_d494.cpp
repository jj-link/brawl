#pragma force_active on
#include <types.h>

extern "C" {
void fn_112_D444(void* entry, void* argument);
void fn_112_DA64(void* destination, const void* source);
s32 fn_112_D524(void* arg, void* src, void* argument);
}

struct PitTraversalIndex {
    short value;
};

struct PitTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
};

extern "C" void fn_112_D494(void* object, const PitTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    PitTraversalEntry* entry = reinterpret_cast<PitTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        ((entry->enabled ? 1U : 0U) == 1U) &&
        entry->disabled == false)
        fn_112_D444(entry, argument);

    PitTraversalIndex operation;
    fn_112_DA64(&operation, index);
    fn_112_D524(composite + 4, &operation, argument);
}
