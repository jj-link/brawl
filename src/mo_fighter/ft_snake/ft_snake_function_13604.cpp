#pragma force_active on
namespace {
struct SnakeTraversalIndex {
    short value;
};

struct SnakeTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_122_135B4(SnakeTraversalEntry*, void*);
void fn_122_13B24(SnakeTraversalIndex*, const SnakeTraversalIndex*);
int fn_122_13694(void*, const SnakeTraversalIndex*, void*);
}

extern "C" void fn_122_13604(void* object, const SnakeTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    SnakeTraversalEntry* entry = reinterpret_cast<SnakeTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_122_135B4(entry, argument);

    SnakeTraversalIndex operation;
    fn_122_13B24(&operation, index);
    fn_122_13694(composite + 4, &operation, argument);
}
