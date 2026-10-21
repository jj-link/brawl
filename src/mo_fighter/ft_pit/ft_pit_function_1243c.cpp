#pragma force_active on
extern "C" {
struct PitTraversalIndex {
    short value;
};

struct PitTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
};

void fn_112_123EC(PitTraversalEntry*, void*);
PitTraversalIndex* fn_112_125BC(PitTraversalIndex*, const PitTraversalIndex*);
int fn_112_124CC(void*, const PitTraversalIndex*, void*);

void fn_112_1243C(void* object, const PitTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    PitTraversalEntry* entry = reinterpret_cast<PitTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        ((entry->enabled ? 1U : 0U) == 1U) &&
        entry->disabled == false)
        fn_112_123EC(entry, argument);

    PitTraversalIndex operation;
    fn_112_125BC(&operation, index);
    fn_112_124CC(composite + 4, &operation, argument);
}
}
