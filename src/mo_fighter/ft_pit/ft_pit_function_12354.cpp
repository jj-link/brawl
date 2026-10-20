#pragma force_active on
namespace {
struct PitTraversalIndex {
    short value;
};

struct PitTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_112_12304(PitTraversalEntry*, void*);
void fn_112_125BC(PitTraversalIndex*, const PitTraversalIndex*);
int fn_112_123E4(void*, const PitTraversalIndex*, void*);
}

extern "C" void fn_112_12354(void* object, const PitTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    PitTraversalEntry* entry = reinterpret_cast<PitTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_112_12304(entry, argument);

    PitTraversalIndex operation;
    fn_112_125BC(&operation, index);
    fn_112_123E4(composite + 4, &operation, argument);
}
