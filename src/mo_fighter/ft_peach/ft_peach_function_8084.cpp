#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_711E4(void* animCommand, s16 animEvent, void* animData);
void* fn_27_1AB96C(void* obj, u8 flag);

void* fn_103_8084(void* self, s16 eventId) {
    u8* base = static_cast<u8*>(self);
    fn_27_711E4(self, eventId, base + 0x24);
    fn_27_1AB96C(base + 0x24, 0);
    return self;
}
}
