#pragma force_active on
struct SonicElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_123_DD24(void* object, void* argument);
void fn_123_ED34(short* destination, const short* source);
int fn_123_E120(void* object, const short* operation, void* argument);
}

extern "C" void fn_123_E090(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 2) {
        bool enabled = reinterpret_cast<SonicElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_123_DD24(element, argument);
        }
    }
    short next;
    fn_123_ED34(&next, operation);
    fn_123_E120(composite + 4, &next, argument);
}
