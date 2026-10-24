#include <types.h>
#pragma force_active on
extern "C" {

s32 fn_803EBE4C();
s32 fn_803EC0F8(s8);
void OSReport(const char*, ...);
extern char lbl_80421450[];

struct Foo {
    u8 pad[0x14];
    u32 var : 8;
    u32 low : 24;
};

s32 fn_8001EB00(Foo* self) {
    u32 var;
    s32 result = fn_803EC0F8(0x41);
    if (result) {
        fn_803EBE4C();
        var = 0xD;
        s32 second = fn_803EBE4C();
        if (second == 5)
            var = 0xE;
        OSReport(lbl_80421450, result, second);
    } else {
        var = 0;
    }
    self->var = var;
    return var;
}

}
