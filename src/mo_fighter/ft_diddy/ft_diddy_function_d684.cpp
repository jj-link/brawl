#pragma force_active on
typedef signed short s16;

extern "C" {
void fn_115_D634(void*, void*);
void fn_115_D71C(s16*, const s16*);
void fn_115_D714(void*, const s16*, void*);
}

struct DiddyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_115_D684(void* object, const s16* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (source[0] & 4) {
        bool enabled = reinterpret_cast<DiddyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_115_D634(element, argument);
        }
    }
    s16 local[4];
    fn_115_D71C(local, source);
    fn_115_D714(composite + 4, local, argument);
}
