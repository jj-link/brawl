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
void fn_110_15314(WarioTraversalEntry*, void*);
void fn_110_13A28(WarioTraversalIndex*, const WarioTraversalIndex*);
int fn_110_13978(void*, const WarioTraversalIndex*, void*);
}

extern "C" void fn_110_138E8(
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
        fn_110_15314(entry, argument);
    }

    WarioTraversalIndex operation;
    fn_110_13A28(&operation, index);
    fn_110_13978(composite + 4, &operation, argument);
}
