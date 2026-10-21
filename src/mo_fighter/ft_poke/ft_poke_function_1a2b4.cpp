#pragma force_active on
typedef short s16;

struct PokeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_116_1A27C(unsigned char* element, void* arg);
s16* fn_116_1A34C(s16* destination, const s16* source);
void fn_116_1A344(unsigned char* target, const s16* value, void* arg);
}

extern "C" void fn_116_1A2B4(unsigned char* object, const s16* source, void* arg) {
    unsigned char* element = object + 0xC;
    if (*source & 4) {
        bool enabled = reinterpret_cast<PokeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_116_1A27C(element, arg);
        }
    }
    s16 tmp;
    fn_116_1A34C(&tmp, source);
    fn_116_1A344(object + 4, &tmp, arg);
}
