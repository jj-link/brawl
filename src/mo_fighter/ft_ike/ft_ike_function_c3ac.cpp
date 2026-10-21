#pragma force_active on
namespace {
struct IkeTraversalIndex {
    short value;
};

struct IkeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_119_C35C(void*, void*);
void fn_119_C52C(IkeTraversalIndex*, const IkeTraversalIndex*);
void fn_119_C43C(void*, const IkeTraversalIndex*, void*);
}

extern "C" void fn_119_C3AC(void* object, const IkeTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 8) {
        bool enabled = reinterpret_cast<IkeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_119_C35C(element, argument);
        }
    }
    IkeTraversalIndex next;
    fn_119_C52C(&next, operation);
    fn_119_C43C(composite + 4, &next, argument);
}
