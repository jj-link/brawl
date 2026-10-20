#pragma force_active on
extern "C" {
void fn_108_E0F0(void* element, void* argument);
void fn_108_E490(short* destination, const short* source);
void fn_108_E1D0(void* destination, const void* operation, void* argument);
}

struct FalcoTraversalIndex {
    short value;
};

struct FalcoElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_108_E140(void* object, const FalcoTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 2) {
        bool enabled = reinterpret_cast<FalcoElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_108_E0F0(element, argument);
        }
    }
    FalcoTraversalIndex next;
    fn_108_E490(&next.value, &operation->value);
    fn_108_E1D0(composite + 4, &next, argument);
}
