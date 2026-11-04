#include <so/so_module_accesser.h>
#include <em/em_area_module_impl.h>
#pragma force_active on

struct Vec3 { float x, y, z; };

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];
Vec3* fn_41_5AC4(Vec3*, float, float, float);
extern float lbl_41_rodata_D58;

void fn_41_25524(s32* out, soModuleAccesser* acc, s32 index, s32 flag) {
    if (index <= -1 || index >= 8) {
        fn_41_5AC4((Vec3*)out, lbl_41_rodata_D58, lbl_41_rodata_D58, lbl_41_rodata_D58);
        return;
    }
    char* area = (char*)__dynamic_cast(
        *(void**)(*(char**)((char*)acc + 0xd8) + 0x90),
        0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);
    s32 v1, v0;
    if (flag == 0) {
        char* p = area + index * 0xc;
        v0 = *(s32*)(p + 0x4a8);
        v1 = *(s32*)(p + 0x4ac);
        out[0] = v0;
        out[1] = v1;
        out[2] = *(s32*)(p + 0x4b0);
    } else {
        char* p = area + index * 0xc;
        v0 = *(s32*)(p + 0x508);
        v1 = *(s32*)(p + 0x50c);
        out[0] = v0;
        out[1] = v1;
        out[2] = *(s32*)(p + 0x510);
    }
}
}
