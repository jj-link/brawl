#pragma force_active on
typedef short s16;

namespace {
struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_107_FB94(void* object, void* argument);
void fn_107_FD64(s16* destination, const s16* source);
void fn_107_FC74(void* object, s16* values, void* argument);
}

extern "C" void fn_107_FBE4(void* object, const s16* input, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*input & 8) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_107_FB94(element, argument);
        }
    }
    s16 converted[4];
    fn_107_FD64(converted, input);
    fn_107_FC74(composite + 4, converted, argument);
}
