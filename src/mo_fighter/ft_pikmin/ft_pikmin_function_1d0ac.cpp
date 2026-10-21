#pragma force_active on
namespace {
struct PikminTraversalIndex {
    short value;
};

struct PikminTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_113_221CC(PikminTraversalEntry*, void*);
void fn_113_1D4E4(PikminTraversalIndex*, const PikminTraversalIndex*);
int fn_113_1D13C(void*, const PikminTraversalIndex*, void*);
}

extern "C" void fn_113_1D0AC(
    void* object,
    const PikminTraversalIndex* index,
    void* argument
) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    PikminTraversalEntry* entry =
        reinterpret_cast<PikminTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false) {
        fn_113_221CC(entry, argument);
    }

    PikminTraversalIndex operation;
    fn_113_1D4E4(&operation, index);
    fn_113_1D13C(composite + 4, &operation, argument);
}
