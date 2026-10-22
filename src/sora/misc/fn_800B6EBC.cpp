#include <types.h>
#pragma force_active on

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* self, u32 index);
extern "C" void fn_80192ECC(void* node, float a, float b, float c);

extern "C" void fn_800B6EBC(void* arg0, float* arg1) {
    void* local = *(void**)(*(char**)((char*)arg0 + 0x10) + 0xE8);
    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&local, *(u32*)((char*)arg0 + 0x34));
    fn_80192ECC(&node, arg1[0], arg1[1], arg1[2]);
}
