#pragma force_active on
#include <types.h>

struct Vec3f {
    float x, y, z;
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* self, u32 index);

extern "C" void fn_800B66D0(char* self, Vec3f* out) {
    void* mdl = *(void**)(*(char**)(self + 0x10) + 0xe8);
    char* node = (char*)GetResNode__Q34nw4r3g3d6ResMdlCFUl(&mdl, *(u32*)(self + 0x34));
    out->x = *(float*)(node + 0x38);
    out->y = *(float*)(node + 0x3c);
    out->z = *(float*)(node + 0x40);
}
