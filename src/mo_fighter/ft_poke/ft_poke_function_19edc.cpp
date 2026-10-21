#pragma force_active on
namespace {
struct PokeTraversalIndex {
    short value;
};

struct PokeTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_116_19EA4(PokeTraversalEntry*, void*);
short* fn_116_1A34C(PokeTraversalIndex*, const PokeTraversalIndex*);
int fn_116_19F6C(void*, const PokeTraversalIndex*, void*);
}

extern "C" void fn_116_19EDC(
    void* object, const PokeTraversalIndex* index, void* argument)
{
    unsigned char* composite = static_cast<unsigned char*>(object);
    PokeTraversalEntry* entry =
        reinterpret_cast<PokeTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false)
        fn_116_19EA4(entry, argument);

    PokeTraversalIndex operation;
    fn_116_1A34C(&operation, index);
    fn_116_19F6C(composite + 4, &operation, argument);
}
