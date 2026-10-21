#pragma force_active on
namespace {
struct ZakoTraversalIndex {
    short value;
};

struct ZakoTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_126_9204(ZakoTraversalEntry*, void*);
void fn_126_968C(ZakoTraversalIndex*, const ZakoTraversalIndex*);
int fn_126_92E4(void*, const ZakoTraversalIndex*, void*);
}

extern "C" void fn_126_9254(
    void* object, const ZakoTraversalIndex* index, void* argument)
{
    unsigned char* composite = static_cast<unsigned char*>(object);
    ZakoTraversalEntry* entry =
        reinterpret_cast<ZakoTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false)
    {
        fn_126_9204(entry, argument);
    }

    ZakoTraversalIndex operation;
    fn_126_968C(&operation, index);
    fn_126_92E4(composite + 4, &operation, argument);
}
