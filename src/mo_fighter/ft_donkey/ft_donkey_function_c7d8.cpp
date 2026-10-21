#pragma force_active on
namespace {
struct DonkeyTraversalIndex {
    short value;
};

struct DonkeyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_92_C788(void*, void*);
void fn_92_C870(DonkeyTraversalIndex*, const DonkeyTraversalIndex*);
void fn_92_C868(void*, const DonkeyTraversalIndex*, void*);
}

extern "C" void fn_92_C7D8(void* object, const DonkeyTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<DonkeyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_92_C788(element, argument);
        }
    }
    DonkeyTraversalIndex next;
    fn_92_C870(&next, operation);
    fn_92_C868(composite + 4, &next, argument);
}
