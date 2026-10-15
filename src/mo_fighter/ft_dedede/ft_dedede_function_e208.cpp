// The interface pointer for this entry points 0x7C bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_135468 from the sora_melee module, which
// receives a flag word and returns a boolean.
#include <types.h>

extern "C" bool fn_27_135468(void* object, u32 flags);

extern "C" bool fn_117_E208(void* object, u32 flags) {
    return fn_27_135468(static_cast<unsigned char*>(object) - 0x7C, flags);
}
