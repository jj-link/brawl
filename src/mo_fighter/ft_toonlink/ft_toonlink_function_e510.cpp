#pragma force_active on
namespace {
struct ToonLinkTraversalIndex {
    short value;
};

struct ToonLinkTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_121_E4C0(ToonLinkTraversalEntry*, void*);
void fn_121_E948(ToonLinkTraversalIndex*, const ToonLinkTraversalIndex*);
int fn_121_E5A0(void*, const ToonLinkTraversalIndex*, void*);
}

extern "C" void fn_121_E510(void* object, const ToonLinkTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    ToonLinkTraversalEntry* entry =
        reinterpret_cast<ToonLinkTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false) {
        fn_121_E4C0(entry, argument);
    }

    ToonLinkTraversalIndex operation;
    fn_121_E948(&operation, index);
    fn_121_E5A0(composite + 4, &operation, argument);
}
