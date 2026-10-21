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
void fn_116_D42C(PokeTraversalEntry*, void*);
void fn_116_D99C(PokeTraversalIndex*, const PokeTraversalIndex*);
int fn_116_D50C(void*, const PokeTraversalIndex*, void*);
}

extern "C" void fn_116_D47C(void* object, const PokeTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    PokeTraversalEntry* entry = reinterpret_cast<PokeTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_116_D42C(entry, argument);

    PokeTraversalIndex operation;
    fn_116_D99C(&operation, index);
    fn_116_D50C(composite + 4, &operation, argument);
}
