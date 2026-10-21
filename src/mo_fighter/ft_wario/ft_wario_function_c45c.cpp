#pragma force_active on
extern "C" {
void fn_110_C40C(void* object, void* argument);
short* fn_110_C6C4(short* destination, const short* source);
int fn_110_C4EC(void* object, short* source, void* argument);
}

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char rest : 7;
};

extern "C" void fn_110_C45C(void* object, const short* flags, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (flags[0] & 4) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_110_C40C(element, argument);
        }
    }
    short local;
    fn_110_C6C4(&local, flags);
    fn_110_C4EC(composite + 4, &local, argument);
}
