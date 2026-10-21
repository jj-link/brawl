#pragma force_active on
namespace {
struct DiddyTraversalIndex {
    short value;
};

struct DiddyTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_115_D1AC(DiddyTraversalEntry*, void*);
void fn_115_D71C(DiddyTraversalIndex*, const DiddyTraversalIndex*);
int fn_115_D28C(void*, const DiddyTraversalIndex*, void*);
}

extern "C" void fn_115_D1FC(
    void* object,
    const DiddyTraversalIndex* index,
    void* argument
) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    DiddyTraversalEntry* entry =
        reinterpret_cast<DiddyTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false) {
        fn_115_D1AC(entry, argument);
    }

    DiddyTraversalIndex operation;
    fn_115_D71C(&operation, index);
    fn_115_D28C(composite + 4, &operation, argument);
}
