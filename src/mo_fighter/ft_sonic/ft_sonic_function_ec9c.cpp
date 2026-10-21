#pragma force_active on
namespace {
struct SonicElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_123_E930(void*, void*);
void fn_123_ED34(short*, const short*);
int fn_123_ED2C(void*, const short*, void*);
}

extern "C" void fn_123_EC9C(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation[0] & 4) {
        bool enabled = reinterpret_cast<SonicElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_123_E930(element, argument);
        }
    }
    short next[4];
    fn_123_ED34(next, operation);
    fn_123_ED2C(composite + 4, next, argument);
}
