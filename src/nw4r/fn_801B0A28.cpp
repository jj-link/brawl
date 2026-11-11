#pragma force_active on
#include <types.h>
struct ParamData { s32 w[16]; };
extern "C" void fn_801AFB78(void*, void*, s32*, s32, s32, s32, s32, s32, s32, s32);
extern "C" char lbl_804663C8[];
struct Object {
    void* vtable;
    char pad4[0x134];
    s32 field138, field13C, field140;
    ParamData parameters;
    s32 field184;
    Object(void* a1, s32* a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, ParamData* a10, s32 a11, s32 a12) {
        s32 copy = *a2;
        fn_801AFB78(this, a1, &copy, a3, a4, a5, a6, a7, a8, a9);
        field138 = 0;
        vtable = lbl_804663C8;
        field13C = 0;
        field140 = a11;
        parameters = *a10;
        field184 = a12;
    }
};
extern "C" Object* fn_801B0A28(Object* self, void* a1, s32* a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, ParamData* a10, s32 a11, s32 a12) {
    return new(self) Object(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}