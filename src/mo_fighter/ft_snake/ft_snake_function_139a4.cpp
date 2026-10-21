#pragma force_active on
typedef signed short s16;

struct SnakeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_122_13954(void*, void*);
s16* fn_122_13B24(s16* destination, const s16* source);
void fn_122_13A34(void*, s16*, void*);
}

extern "C" void fn_122_139A4(void* object, const s16* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation[0] & 8) {
        bool enabled = reinterpret_cast<SnakeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_122_13954(element, argument);
        }
    }
    s16 next;
    fn_122_13B24(&next, operation);
    fn_122_13A34(composite + 4, &next, argument);
}
