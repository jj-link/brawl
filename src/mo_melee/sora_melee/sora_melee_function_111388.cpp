#include <types.h>
#pragma force_active on

struct fn_27_Flags {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern "C" {
void fn_27_111388(u8** self, u32 val) {
    u8* obj = *self;
    fn_27_Flags* f = (fn_27_Flags*)(obj + 0x48e);
    f->b2 = val;
}
}
