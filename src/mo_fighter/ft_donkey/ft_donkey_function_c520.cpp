#pragma force_active on
struct TraversalIndex {
    short value;
};

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_92_C4D0(void* element, void* argument);
void fn_92_C870(TraversalIndex* destination, const TraversalIndex* source);
void fn_92_C5B0(void* composite, const TraversalIndex* operation, void* argument);
}

extern "C" void fn_92_C520(void* object, const TraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 2) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_92_C4D0(element, argument);
        }
    }

    TraversalIndex next;
    fn_92_C870(&next, operation);
    fn_92_C5B0(composite + 4, &next, argument);
}
