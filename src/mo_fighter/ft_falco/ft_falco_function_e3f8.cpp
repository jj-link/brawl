#pragma force_active on
namespace {
struct FalcoTraversalIndex {
    short value;
};
struct FalcoElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_108_E3A8(void*, void*);
void fn_108_E490(FalcoTraversalIndex*, const FalcoTraversalIndex*);
void fn_108_E488(void*, const FalcoTraversalIndex*, void*);
}

extern "C" void fn_108_E3F8(void* object, const FalcoTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<FalcoElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_108_E3A8(element, argument);
        }
    }
    FalcoTraversalIndex next;
    fn_108_E490(&next, operation);
    fn_108_E488(composite + 4, &next, argument);
}
