#pragma force_active on
namespace {
struct KirbyTraversalIndex {
    short value;
};

struct KirbyTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_96_211CC(KirbyTraversalEntry*, void*);
KirbyTraversalIndex* fn_96_13310(KirbyTraversalIndex*, const KirbyTraversalIndex*);
int fn_96_12EB8(void*, const KirbyTraversalIndex*, void*);
}

extern "C" void fn_96_12E28(void* object, const KirbyTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    KirbyTraversalEntry* entry = reinterpret_cast<KirbyTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false)
        fn_96_211CC(entry, argument);

    KirbyTraversalIndex operation;
    fn_96_13310(&operation, index);
    fn_96_12EB8(composite + 4, &operation, argument);
}
