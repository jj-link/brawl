#pragma force_active on
namespace {
struct DonkeyTraversalIndex {
    short value;
};

struct DonkeyTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_92_C3E8(DonkeyTraversalEntry*, void*);
void fn_92_C870(DonkeyTraversalIndex*, const DonkeyTraversalIndex*);
int fn_92_C4C8(void*, const DonkeyTraversalIndex*, void*);
}

extern "C" void fn_92_C438(
    void* object, const DonkeyTraversalIndex* index, void* argument)
{
    unsigned char* composite = static_cast<unsigned char*>(object);
    DonkeyTraversalEntry* entry =
        reinterpret_cast<DonkeyTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false)
    {
        fn_92_C3E8(entry, argument);
    }

    DonkeyTraversalIndex operation;
    fn_92_C870(&operation, index);
    fn_92_C4C8(composite + 4, &operation, argument);
}
