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
void fn_123_CD38(SonicTraversalEntry*, void*);
void fn_123_ED34(SonicTraversalIndex*, const SonicTraversalIndex*);
int fn_123_D134(void*, const SonicTraversalIndex*, void*);
}

extern "C" void fn_123_D0A4(void* object, const SonicTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    SonicTraversalEntry* entry = reinterpret_cast<SonicTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_123_CD38(entry, argument);

    SonicTraversalIndex operation;
    fn_123_ED34(&operation, index);
    fn_123_D134(composite + 4, &operation, argument);
}
