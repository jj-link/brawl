#pragma force_active on
struct TraversalIndex {
    short value;
};

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_109_BC08(void*, void*);
extern "C" void fn_109_BFA8(short*, const short*);
extern "C" void fn_109_BCE8(void*, void*, void*);

extern "C" void fn_109_BC58(void* object, const TraversalIndex* operation, void* argument) {
    unsigned char* element = static_cast<unsigned char*>(object) + 0xC;

    if (operation->value & 2) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_109_BC08(element, argument);
        }
    }

    short next;
    fn_109_BFA8(&next, &operation->value);
    fn_109_BCE8(static_cast<unsigned char*>(object) + 4, &next, argument);
}
