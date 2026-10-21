#pragma force_active on
struct SamusTraversalIndex {
    short value;
};

struct SamusElementFlags {
    unsigned char enabled : 1;
};

extern "C" void fn_94_E8F8(void*, void*);
extern "C" SamusTraversalIndex* fn_94_EAC8(SamusTraversalIndex*, const SamusTraversalIndex*);
extern "C" int fn_94_E9D8(void*, const SamusTraversalIndex*, void*);

extern "C" void fn_94_E948(void* object, const SamusTraversalIndex* operation, void* argument) {
    unsigned char* element = static_cast<unsigned char*>(object) + 0xC;
    if (operation->value & 8) {
        bool enabled = reinterpret_cast<SamusElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_94_E8F8(element, argument);
        }
    }
    SamusTraversalIndex next;
    fn_94_EAC8(&next, operation);
    fn_94_E9D8(static_cast<unsigned char*>(object) + 4, &next, argument);
}
