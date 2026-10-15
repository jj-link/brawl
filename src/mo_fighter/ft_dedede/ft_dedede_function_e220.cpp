// The interface pointer for this entry points 0x94 bytes past the complete
// object; this entry re-derives the complete object pointer and tail-calls
// the imported fn_27_135A70 from the sora_melee module, which returns a
// boolean indicating whether the adjustment was applied.
#include <types.h>

extern "C" bool fn_27_135A70(void* object);

extern "C" bool fn_117_E220(void* object) {
    return fn_27_135A70(static_cast<unsigned char*>(object) - 0x94);
}
