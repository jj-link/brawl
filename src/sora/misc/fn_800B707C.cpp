#include <types.h>
#pragma force_active on

namespace nw4r { namespace g3d { class ResMdl; } }

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

struct ObjA {
    u8 pad[0x10];
    u8* unk10;
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);
extern "C" void fn_80192FF8(void* node, f32 x, f32 y, f32 z);

extern "C" void fn_800B707C(ObjA* arg0, const char* arg1, Vec3f* arg2) {
    void* spC;
    void* sp8;

    spC = *(void**)(arg0->unk10 + 0xE8);
    sp8 = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&spC, arg1);
    fn_80192FF8(&sp8, arg2->x, arg2->y, arg2->z);
}
