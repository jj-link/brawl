#include <types.h>

extern "C" void* fn_111_9884(void* array, int index);
extern "C" int fn_27_8D3E4(void* controller);

extern "C" void fn_111_9798(void* object) {
    u8* state = static_cast<u8*>(object);
    for (int index = 0; index < 1; ++index) {
        u8* element = static_cast<u8*>(fn_111_9884(state + 0xC, index));
        if (fn_27_8D3E4(element + 0x88) == 0) {
            break;
        }
    }
}
