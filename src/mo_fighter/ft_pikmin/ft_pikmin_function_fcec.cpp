#pragma force_active on
namespace {
struct PikminTraversalIndex {
    short value;
};
struct PikminElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_113_FC9C(void*, void*);
void fn_113_FD84(short*, const PikminTraversalIndex*);
void fn_113_FD7C(void*, const short*, void*);
}

extern "C" void fn_113_FCEC(void* object, const PikminTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<PikminElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_113_FC9C(element, argument);
        }
    }
    short next;
    fn_113_FD84(&next, operation);
    fn_113_FD7C(composite + 4, &next, argument);
}
