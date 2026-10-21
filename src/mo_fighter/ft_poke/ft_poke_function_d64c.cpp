#include <types.h>
#pragma force_active on

extern "C" void fn_116_D5FC(void* element, void* argument);
extern "C" void fn_116_D99C(s16* destination, const s16* source);
extern "C" void fn_116_D6DC(void* composite, const s16* operation, void* argument);

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char reserved : 7;
};

extern "C" void fn_116_D64C(void* object, const s16* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation[0] & 2) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_116_D5FC(element, argument);
        }
    }
    s16 next;
    fn_116_D99C(&next, operation);
    fn_116_D6DC(composite + 4, &next, argument);
}
