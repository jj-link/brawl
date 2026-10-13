namespace {
struct DededeTraversalIndex {
    short value;
};
struct DededeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_117_21BA0(void*, void*);
void fn_117_21FE8(DededeTraversalIndex*, const DededeTraversalIndex*);
void fn_117_21C80(void*, const DededeTraversalIndex*, void*);
}

extern "C" void fn_117_21D88(void* object, const DededeTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 2) {
        bool enabled = reinterpret_cast<DededeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_117_21BA0(element, argument);
        }
    }
    DededeTraversalIndex next;
    fn_117_21FE8(&next, operation);
    fn_117_21C80(composite + 4, &next, argument);
}
