namespace {
struct DededeTraversalIndex {
    short value;
};
struct DededeTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_117_21F00(DededeTraversalEntry*, void*);
void fn_117_21FE8(DededeTraversalIndex*, const DededeTraversalIndex*);
int fn_117_21FE0(void*, const DededeTraversalIndex*, void*);
}

extern "C" void fn_117_21F50(void* object, const DededeTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    DededeTraversalEntry* entry = reinterpret_cast<DededeTraversalEntry*>(composite + 0xC);
    if ((index->value & 4) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_117_21F00(entry, argument);

    DededeTraversalIndex operation;
    fn_117_21FE8(&operation, index);
    fn_117_21FE0(composite + 4, &operation, argument);
}
