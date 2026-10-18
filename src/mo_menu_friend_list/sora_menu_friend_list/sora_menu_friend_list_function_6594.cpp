#include <types.h>
#pragma force_active on

struct FriendListSub {
    u8 pad[0x24f4];
    u32 field;
};

extern "C" void fn_14_6594(FriendListSub* self) {
    self->field = 0;
}
