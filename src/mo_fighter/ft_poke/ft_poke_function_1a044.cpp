#pragma force_active on
namespace {
struct PokeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_116_1A00C(void* element, void* argument);
void fn_116_1A34C(short* destination, const short* source);
void fn_116_1A0D4(void* object, short* value, void* argument);
}

extern "C" void fn_116_1A044(unsigned char* object, const short* source, void* argument) {
    unsigned char* element = object + 0xC;
    if (source[0] & 2) {
        bool enabled = reinterpret_cast<PokeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_116_1A00C(element, argument);
        }
    }
    short value;
    fn_116_1A34C(&value, source);
    fn_116_1A0D4(object + 4, &value, argument);
}
