#include <types.h>
#pragma force_active on

struct Ctx {
    char pad[0x78];
    s32 field_78;
    s32 field_7c;
    char pad_80[4];
    s8 field_84;
    char pad_85[0x100 - 0x85];
    s32 field_100;
};
struct Inner {
    char pad[0x26];
    u8 hi : 2;
    u8 lo : 6;
};
struct Arg1 {
    char pad[8];
    Inner* field_8;
};
extern "C" void fn_802F4160(Ctx*, Arg1*);
extern "C" void fn_802F5624(void*);
extern "C" void fn_802EFE70(void*);

extern "C" void fn_802F8F98(Ctx* self, Arg1* a, s32 flag) {
    Inner* inner = a->field_8;
    inner->hi = 1;
    if (((const s32*)self)[0x7C / 4] != 0) {
        if (flag != 0 && self->field_100 != 0) {
            fn_802F4160(self, a);
        }
        fn_802F5624(a);
        return;
    }
    self->field_7c = self->field_7c + 1;
    if (flag != 0 && self->field_100 != 0) {
        fn_802F4160(self, a);
    }
    fn_802F5624(a);
    self->field_7c = self->field_7c - 1;
    if (self->field_7c == 0 && self->field_78 != 0 && self->field_84 == 0) {
        fn_802EFE70(self);
    }
}