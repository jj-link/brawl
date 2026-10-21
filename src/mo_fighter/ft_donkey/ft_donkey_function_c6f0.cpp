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
void fn_92_C6A0(void*, void*);
void fn_92_C870(DonkeyTraversalIndex*, const DonkeyTraversalIndex*);
void fn_92_C780(void*, const DonkeyTraversalIndex*, void*);
}

extern "C" void fn_92_C6F0(void* object, const DonkeyTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 8) {
        bool enabled = reinterpret_cast<DonkeyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_92_C6A0(element, argument);
        }
    }

    DonkeyTraversalIndex next;
    fn_92_C870(&next, operation);
    fn_92_C780(composite + 4, &next, argument);
}
