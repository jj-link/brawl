#pragma force_active on
namespace {
struct KoopaTraversalIndex {
    short value;
};
struct KoopaElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_102_BAE8(void*, void*);
void fn_102_BE88(KoopaTraversalIndex*, const KoopaTraversalIndex*);
void fn_102_BBC8(void*, const KoopaTraversalIndex*, void*);
}

extern "C" void fn_102_BB38(void* object, const KoopaTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 2) {
        bool enabled = reinterpret_cast<KoopaElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_102_BAE8(element, argument);
        }
    }

    KoopaTraversalIndex next;
    fn_102_BE88(&next, operation);
    fn_102_BBC8(composite + 4, &next, argument);
}
