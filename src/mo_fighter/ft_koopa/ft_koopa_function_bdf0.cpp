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
void fn_102_BDA0(void*, void*);
KoopaTraversalIndex* fn_102_BE88(KoopaTraversalIndex*, const KoopaTraversalIndex*);
void fn_102_BE80(void*, const KoopaTraversalIndex*, void*);
}

extern "C" void fn_102_BDF0(void* object, const KoopaTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 4) {
        bool enabled = reinterpret_cast<KoopaElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_102_BDA0(element, argument);
        }
    }

    KoopaTraversalIndex next;
    fn_102_BE88(&next, operation);
    fn_102_BE80(composite + 4, &next, argument);
}
