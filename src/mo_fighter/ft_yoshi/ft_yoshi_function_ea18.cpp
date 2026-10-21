#pragma force_active on
extern "C" {
void fn_95_E9C8(void* element, void* argument);
short* fn_95_ED68(short* destination, const short* source);
int fn_95_EAA8(void* object, short* local, void* argument);
}

namespace {
struct YoshiElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" void fn_95_EA18(unsigned char* object, const short* source, void* argument) {
    short local;
    unsigned char* element = object + 0xC;
    if (source[0] & 2) {
        bool enabled = reinterpret_cast<YoshiElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_95_E9C8(element, argument);
        }
    }
    fn_95_ED68(&local, source);
    fn_95_EAA8(object + 4, &local, argument);
}
