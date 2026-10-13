namespace {
struct DededeTraversalIndex {
    short value;
};
}

extern "C" {
void fn_117_21B44(DededeTraversalIndex*, const short*);
void fn_117_21FE8(DededeTraversalIndex*, const DededeTraversalIndex*);
void fn_117_21F50(void*, const DededeTraversalIndex*, void*);
void fn_117_21E68(void*, const DededeTraversalIndex*, void*);
void fn_117_21D88(void*, const DededeTraversalIndex*, void*);
void fn_117_21CD8(void*, const DededeTraversalIndex*, void*);
void fn_117_21BF0(void*, const DededeTraversalIndex*, void*);
}

extern "C" void fn_117_2196C(void* object, void* argument, const short* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    DededeTraversalIndex operation;
    short value = *index;
    DededeTraversalIndex second;
    DededeTraversalIndex fourth;
    DededeTraversalIndex fifth;
    DededeTraversalIndex third;
    DededeTraversalIndex first;

    // Each array traversal receives a distinct copy of the index operation.
    fn_117_21B44(&operation, &value);
    fn_117_21FE8(&first, &operation);
    fn_117_21F50(composite + 0xE4, &first, argument);
    fn_117_21FE8(&second, &operation);
    fn_117_21E68(composite + 0xA8, &second, argument);
    fn_117_21FE8(&third, &operation);
    fn_117_21D88(composite + 0x68, &third, argument);
    fn_117_21FE8(&fourth, &operation);
    fn_117_21CD8(composite + 0x48, &fourth, argument);
    fn_117_21FE8(&fifth, &operation);
    fn_117_21BF0(composite + 8, &fifth, argument);
}
