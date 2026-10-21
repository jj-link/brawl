#pragma force_active on
namespace {
struct LinkTraversalIndex {
    short value;
};

struct LinkTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_93_E2F4(LinkTraversalEntry*, void*);
void fn_93_E94C(LinkTraversalIndex*, const LinkTraversalIndex*);
int fn_93_E3D4(void*, const LinkTraversalIndex*, void*);
}

extern "C" void fn_93_E344(void* object, const LinkTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    LinkTraversalEntry* entry = reinterpret_cast<LinkTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_93_E2F4(entry, argument);

    LinkTraversalIndex operation;
    fn_93_E94C(&operation, index);
    fn_93_E3D4(composite + 4, &operation, argument);
}
