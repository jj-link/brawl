#pragma force_active on
extern "C" {
void fn_95_EAB0(void* element, void* argument);
short* fn_95_ED68(short* destination, const short* source);
void fn_95_EB90(void* object, short* local, void* argument);
}

namespace {
struct YoshiElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" void fn_95_EB00(unsigned char* object, const short* source, void* argument) {
    short local;
    unsigned char* element = object + 0xC;
    if (source[0] & 4) {
        bool enabled = reinterpret_cast<YoshiElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_95_EAB0(element, argument);
        }
    }
    fn_95_ED68(&local, source);
    fn_95_EB90(object + 4, &local, argument);
}
