#include <types.h>
#pragma force_active on

extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void* o, u8 c);

struct FtSubObj {
    u8 pad[0x24];
    u8 sub[4];
};

extern "C" void* fn_111_6C7C(void* object, s16 animEvent) {
    FtSubObj* self = (FtSubObj*)object;
    fn_27_711E4(object, animEvent, self->sub);
    fn_27_1AB96C(self->sub, 0);
    return object;
}
