#include <types.h>
#pragma force_active on

struct MuMenu_297F8 {
    unsigned char pad[0x66c];
    u32 field_66C;
    u32 field_670;
    u32 field_674;
    void* field_678;
};

extern "C" s32 fn_2_25BC0(s32 index);
extern "C" void printIndex__5MuMsgFUlUlPv(void* msg, u32 a, u32 b, void* c);

extern "C" void fn_2_297F8(MuMenu_297F8* self, s32 index) {
    s32 value = fn_2_25BC0(index);
    printIndex__5MuMsgFUlUlPv(self->field_678, self->field_66C + 0x19, value, 0);
}
