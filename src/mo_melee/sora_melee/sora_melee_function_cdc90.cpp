#include <types.h>
#pragma force_active on

struct SoraFlagStruct {
    u32 pad0;
    u32 pad4;
    u32 flags8;
};

extern "C" {

unsigned int fn_27_CDC90(SoraFlagStruct* s) {
    return (s->flags8 >> 16) & 1;
}

}
