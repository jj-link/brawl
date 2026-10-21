#pragma force_active on
namespace {
struct ZeldaTraversalIndex {
    short value;
};

struct ZeldaTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_104_D508(ZeldaTraversalEntry*, void*);
void fn_104_DC48(ZeldaTraversalIndex*, const ZeldaTraversalIndex*);
int fn_104_D5E8(void*, const ZeldaTraversalIndex*, void*);
}

extern "C" void fn_104_D558(void* object, const ZeldaTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    ZeldaTraversalEntry* entry = reinterpret_cast<ZeldaTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false)
        fn_104_D508(entry, argument);

    ZeldaTraversalIndex operation;
    fn_104_DC48(&operation, index);
    fn_104_D5E8(composite + 4, &operation, argument);
}
