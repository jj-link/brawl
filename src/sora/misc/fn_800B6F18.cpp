#include <types.h>
#pragma force_active on

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);
extern "C" void fn_80192ECC(void* node, float a, float b, float c);

extern "C" void fn_800B6F18(void* arg0, const char* arg1, void* arg2) {
    void* local = *(void**)(*(char**)((char*)arg0 + 0x10) + 0xE8);
    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&local, arg1);
    fn_80192ECC(&node, *(float*)arg2, *(float*)((char*)arg2 + 4), *(float*)((char*)arg2 + 8));
}
