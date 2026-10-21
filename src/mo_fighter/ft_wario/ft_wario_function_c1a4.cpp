#pragma force_active on
namespace {
struct WarioTraversalIndex {
    short value;
};

struct WarioTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_110_C154(WarioTraversalEntry*, void*);
short* fn_110_C6C4(WarioTraversalIndex*, const WarioTraversalIndex*);
int fn_110_C234(void*, const WarioTraversalIndex*, void*);
}

extern "C" void fn_110_C1A4(
    void* object,
    const WarioTraversalIndex* index,
    void* argument
) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    WarioTraversalEntry* entry =
        reinterpret_cast<WarioTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false) {
        fn_110_C154(entry, argument);
    }

    WarioTraversalIndex operation;
    fn_110_C6C4(&operation, index);
    fn_110_C234(composite + 4, &operation, argument);
}
