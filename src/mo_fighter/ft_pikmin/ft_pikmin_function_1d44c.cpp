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
void fn_113_1D3FC(void*, void*);
void fn_113_1D4E4(PikminTraversalIndex*, const PikminTraversalIndex*);
void fn_113_1D4DC(void*, const PikminTraversalIndex*, void*);
}

extern "C" void fn_113_1D44C(
    void* object,
    const PikminTraversalIndex* operation,
    void* argument
) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 2) {
        bool enabled = reinterpret_cast<PikminElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_113_1D3FC(element, argument);
        }
    }

    PikminTraversalIndex next;
    fn_113_1D4E4(&next, operation);
    fn_113_1D4DC(composite + 4, &next, argument);
}
