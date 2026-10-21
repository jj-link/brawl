#pragma force_active on
namespace {
struct ToonTraversalIndex {
    short value;
};
struct ToonElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_121_E860(void*, void*);
void fn_121_E940(void*, const ToonTraversalIndex*, void*);
void fn_121_E948(ToonTraversalIndex*, const ToonTraversalIndex*);
}

extern "C" void fn_121_E8B0(void* object, const ToonTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<ToonElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_121_E860(element, argument);
        }
    }
    ToonTraversalIndex next;
    fn_121_E948(&next, operation);
    fn_121_E940(composite + 4, &next, argument);
}
