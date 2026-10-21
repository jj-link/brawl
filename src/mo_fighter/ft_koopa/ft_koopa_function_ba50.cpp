#pragma force_active on
namespace {
struct KoopaTraversalIndex {
    short value;
};

struct KoopaTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_102_BA00(KoopaTraversalEntry*, void*);
void fn_102_BE88(KoopaTraversalIndex*, const KoopaTraversalIndex*);
int fn_102_BAE0(void*, const KoopaTraversalIndex*, void*);
}

extern "C" void fn_102_BA50(
    void* object,
    const KoopaTraversalIndex* index,
    void* argument
) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    KoopaTraversalEntry* entry =
        reinterpret_cast<KoopaTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false) {
        fn_102_BA00(entry, argument);
    }

    KoopaTraversalIndex operation;
    fn_102_BE88(&operation, index);
    fn_102_BAE0(composite + 4, &operation, argument);
}
