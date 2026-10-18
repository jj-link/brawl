#include <types.h>
#pragma force_active on

struct FtPokeState {
    u8 pad[0x31];
    u8 flag31;
};

extern "C" void fn_116_CBE8(FtPokeState* object) {
    object->flag31 = 0;
}
