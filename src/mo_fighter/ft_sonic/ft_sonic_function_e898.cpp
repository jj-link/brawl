#pragma force_active on
extern "C" {
void fn_123_E52C(void*, void*);
void fn_123_ED34(short*, const void*);
void fn_123_E928(void*, const void*, void*);
}

struct TraversalIndex {
    short value;
};

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_123_E898(void* object, const TraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 8) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_123_E52C(element, argument);
        }
    }

    short next;
    fn_123_ED34(&next, operation);
    fn_123_E928(composite + 4, &next, argument);
}
