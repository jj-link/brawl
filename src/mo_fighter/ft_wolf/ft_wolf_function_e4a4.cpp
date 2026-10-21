#pragma force_active on
extern "C" {
void fn_125_E454(void* element, void* argument);
void fn_125_E53C(short* dest, const short* src);
void fn_125_E534(void* object, const void* operation, void* argument);
}

struct WolfElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_125_E4A4(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 4) {
        bool enabled = reinterpret_cast<WolfElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_125_E454(element, argument);
        }
    }
    short next;
    fn_125_E53C(&next, operation);
    fn_125_E534(composite + 4, &next, argument);
}
