#pragma force_active on
extern "C" {
void fn_119_C18C(void*, void*);
short* fn_119_C52C(short*, const short*);
int fn_119_C26C(void*, const short*, void*);
}

struct TraversalIndex {
    short value;
};

struct ElementFlags {
    unsigned char enabled : 1;
};

extern "C" void fn_119_C1DC(void* object, const TraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 2) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_119_C18C(element, argument);
        }
    }

    short next;
    fn_119_C52C(&next, &operation->value);
    fn_119_C26C(composite + 4, &next, argument);
}
