#pragma force_active on
namespace {
struct WolfTraversalIndex {
    short value;
};
struct WolfElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_125_E19C(void*, void*);
void fn_125_E53C(WolfTraversalIndex*, const WolfTraversalIndex*);
void fn_125_E27C(void*, const WolfTraversalIndex*, void*);
}

extern "C" void fn_125_E1EC(void* object, const WolfTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 2) {
        bool enabled = reinterpret_cast<WolfElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_125_E19C(element, argument);
        }
    }
    WolfTraversalIndex next;
    fn_125_E53C(&next, operation);
    fn_125_E27C(composite + 4, &next, argument);
}
