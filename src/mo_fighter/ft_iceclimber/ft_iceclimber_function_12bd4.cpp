#pragma force_active on
namespace {
struct TraversalIndex {
    short value;
};

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_105_12890(void*, void*);
void fn_105_12C6C(TraversalIndex*, const TraversalIndex*);
void fn_105_12C64(void*, const TraversalIndex*, void*);
}

extern "C" void fn_105_12BD4(void* object, const TraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 4) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_105_12890(element, argument);
        }
    }

    TraversalIndex next;
    fn_105_12C6C(&next, operation);
    fn_105_12C64(composite + 4, &next, argument);
}
