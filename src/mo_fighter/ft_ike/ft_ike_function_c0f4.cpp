#pragma force_active on
namespace {
struct IkeTraversalIndex {
    short value;
};

struct IkeTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_119_C0A4(IkeTraversalEntry*, void*);
void fn_119_C52C(IkeTraversalIndex*, const IkeTraversalIndex*);
int fn_119_C184(void*, const IkeTraversalIndex*, void*);
}

extern "C" void fn_119_C0F4(
    void* object, const IkeTraversalIndex* index, void* argument
) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    IkeTraversalEntry* entry =
        reinterpret_cast<IkeTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false)
        fn_119_C0A4(entry, argument);

    IkeTraversalIndex operation;
    fn_119_C52C(&operation, index);
    fn_119_C184(composite + 4, &operation, argument);
}
