#pragma force_active on
extern "C" {
void fn_119_C274(void* object, void* argument);
short* fn_119_C52C(short* destination, const short* source);
void fn_119_C354(void* object, const short* source, void* argument);
}

struct FlagBits {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
};

extern "C" void fn_119_C2C4(void* object, const short* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    short local[4];
    if (source[0] & 4) {
        bool enabled = reinterpret_cast<FlagBits*>(element)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_119_C274(element, argument);
        }
    }
    fn_119_C52C(local, source);
    fn_119_C354(composite + 4, local, argument);
}
