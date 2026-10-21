#pragma force_active on
namespace {
struct SamusTraversalIndex {
    short value;
};

struct SamusElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_94_E810(void*, void*);
short* fn_94_EAC8(short*, const short*);
void fn_94_E8F0(void*, const SamusTraversalIndex*, void*);
}

extern "C" void fn_94_E860(void* object, const SamusTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<SamusElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_94_E810(element, argument);
        }
    }
    SamusTraversalIndex next;
    fn_94_EAC8(&next.value, &operation->value);
    fn_94_E8F0(composite + 4, &next, argument);
}
