#include <types.h>
#pragma force_active on

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* self, u32 index);
extern "C" void SetTranslate__Q34nw4r3g3d7ResNodeFfff(void* node, f32 x, f32 y, f32 z);

struct ObjA {
    u8 pad[0x10];
    u8* unk10;
    u8 pad2[0x34 - 0x14];
    u32 unk34;
};

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" void fn_800B6784(ObjA* arg0, Vec3f* arg1) {
    void* spC;
    void* sp8;

    spC = *(void**)(arg0->unk10 + 0xE8);
    sp8 = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&spC, arg0->unk34);
    SetTranslate__Q34nw4r3g3d7ResNodeFfff(&sp8, arg1->x, arg1->y, arg1->z);
}
