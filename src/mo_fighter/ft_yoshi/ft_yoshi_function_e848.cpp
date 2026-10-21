#pragma force_active on
namespace {
struct YoshiTraversalIndex {
    short value;
};

struct YoshiTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_95_E7F8(YoshiTraversalEntry*, void*);
short* fn_95_ED68(YoshiTraversalIndex*, const YoshiTraversalIndex*);
int fn_95_E8D8(void*, const YoshiTraversalIndex*, void*);
}

extern "C" void fn_95_E848(
    void* object,
    const YoshiTraversalIndex* index,
    void* argument
) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    YoshiTraversalEntry* entry =
        reinterpret_cast<YoshiTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false)
        fn_95_E7F8(entry, argument);

    YoshiTraversalIndex operation;
    fn_95_ED68(&operation, index);
    fn_95_E8D8(composite + 4, &operation, argument);
}
