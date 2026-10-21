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
void fn_113_FBB4(void*, void*);
void fn_113_FD84(PikminTraversalIndex*, const PikminTraversalIndex*);
void fn_113_FC94(void*, const PikminTraversalIndex*, void*);
}

extern "C" void fn_113_FC04(
    void* object,
    const PikminTraversalIndex* operation,
    void* argument
) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 8) {
        bool enabled =
            reinterpret_cast<PikminElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_113_FBB4(element, argument);
        }
    }

    PikminTraversalIndex next;
    fn_113_FD84(&next, operation);
    fn_113_FC94(composite + 4, &next, argument);
}
