#include <types.h>
#pragma force_active on

struct PeachVec2 {
    f32 x;
    f32 y;
};

struct PeachVec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct PeachLocals {
    u8 flag;
    PeachVec2 b;
    PeachVec2 a;
    PeachVec3 c;
    PeachVec3 d;
};

struct PeachFloatOwner {
    u8 unknown[0x7C];
    f32 scaleA;
    f32 scaleB;
};

extern "C" {
extern const f32 lbl_103_rodata_14;
PeachVec3* fn_103_9594(PeachVec3* destination, f32 x, f32 y, f32 z);
void fn_27_89D08(s32 id, void* accesser, s32 index, PeachVec2* vec2, PeachVec3* vec3);
f32 getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);

void fn_103_D870(void* unused, PeachFloatOwner* owner, const PeachVec2* source, void* accesser) {
    PeachLocals locals;
    locals.a.x = source->x;
    locals.a.y = lbl_103_rodata_14;
    fn_27_89D08(2, accesser, 0, &locals.a, fn_103_9594(&locals.d, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
    locals.b.x = source->y;
    locals.b.y = lbl_103_rodata_14;
    fn_27_89D08(1, accesser, 0, &locals.b, fn_103_9594(&locals.c, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
    locals.flag = 0;
    f32 scaleA = owner->scaleA;
    owner->scaleA = scaleA * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFBA, 0);
    f32 scaleB = owner->scaleB;
    owner->scaleB = scaleB * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFBA, 0);
}
}
