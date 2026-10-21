#pragma force_active on
namespace {
struct SonicTraversalIndex {
    short value;
};

struct SonicTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_123_18484(SonicTraversalEntry*, void*);
void fn_123_17AEC(SonicTraversalIndex*, const SonicTraversalIndex*);
void fn_123_17AE4(void*, const SonicTraversalIndex*, void*);
}

extern "C" void fn_123_17A54(void* object, const SonicTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    SonicTraversalEntry* entry = reinterpret_cast<SonicTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_123_18484(entry, argument);

    SonicTraversalIndex operation;
    fn_123_17AEC(&operation, index);
    fn_123_17AE4(composite + 4, &operation, argument);
}
