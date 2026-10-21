#pragma force_active on
namespace {
struct YoshiTraversalIndex {
    short value;
};
struct YoshiElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_95_EB98(void*, void*);
void fn_95_ED68(YoshiTraversalIndex*, const YoshiTraversalIndex*);
int fn_95_EC78(void*, const YoshiTraversalIndex*, void*);
}

extern "C" void fn_95_EBE8(void* object, const YoshiTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 8) {
        bool enabled = reinterpret_cast<YoshiElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_95_EB98(element, argument);
        }
    }
    YoshiTraversalIndex next;
    fn_95_ED68(&next, operation);
    fn_95_EC78(composite + 4, &next, argument);
}
