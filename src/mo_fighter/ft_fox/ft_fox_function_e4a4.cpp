#pragma force_active on
namespace {
struct FoxTraversalIndex {
    short value;
};

struct FoxElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_97_E454(void*, void*);
void fn_97_E624(FoxTraversalIndex*, const FoxTraversalIndex*);
void fn_97_E534(void*, const FoxTraversalIndex*, void*);
}

extern "C" void fn_97_E4A4(void* object, const FoxTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 8) {
        bool enabled = reinterpret_cast<FoxElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_97_E454(element, argument);
        }
    }

    FoxTraversalIndex next;
    fn_97_E624(&next, operation);
    fn_97_E534(composite + 4, &next, argument);
}
