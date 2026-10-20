#include <types.h>
#pragma force_active on

extern "C" u32 getModuleAccesser__23soExternalValueAccesserFP11StageObject(void* self);

extern "C" u32 fn_27_14D490(void* self) {
    char* obj = (char*)getModuleAccesser__23soExternalValueAccesserFP11StageObject(self);
    char* p = *(char**)(obj + 0xd8);
    return *(u32*)(p + 0x20);
}
