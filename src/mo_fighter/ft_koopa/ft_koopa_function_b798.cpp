#include <st/module.h>
#pragma force_active on

namespace {
struct KoopaTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_102_B748(void* entry, void* argument);
void fn_102_BE88(s16* destination, const s16* source);
void fn_102_B828(void* a, void* b, void* c);
}

extern "C" void fn_102_B798(void* object, const s16* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    KoopaTraversalEntry* entry = reinterpret_cast<KoopaTraversalEntry*>(composite + 0xC);
    if ((*index & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_102_B748(entry, argument);

    s16 operation;
    fn_102_BE88(&operation, index);
    fn_102_B828(composite + 4, &operation, argument);
}
