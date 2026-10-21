#pragma force_active on
namespace {
struct WarioElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_110_C5DC(void*, void*);
short* fn_110_C6C4(short*, const short*);
void fn_110_C6BC(void*, short*, void*);
}

extern "C" void fn_110_C62C(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation[0] & 4) {
        bool enabled = reinterpret_cast<WarioElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_110_C5DC(element, argument);
        }
    }
    short next;
    fn_110_C6C4(&next, operation);
    fn_110_C6BC(composite + 4, &next, argument);
}
