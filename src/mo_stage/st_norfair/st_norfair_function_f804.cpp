#include <types.h>
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

extern "C" void fn_54_F804(void* self) {
    char* p = (char*)self;
    char* base = p + 0xd0;
    if (base == 0) return;
    void** models = (void**)(*(void**)(p + 0x44));
    void* model = models[0];
    if (model == 0) return;
    char* mp = (char*)model;
    if (*(int*)(mp + 0x11c) == 0) {
        *(unsigned int*)(base + 0xc) = 0;
        *(unsigned int*)(mp + 0x11c) = (unsigned int)base;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
        *(unsigned short*)(mp + 0x122) = *(unsigned int*)(*(unsigned int**)(base + 4));
    }
    *(float*)((char*)*(void**)(base + 4) + 0x30) = *(float*)(p + 0x174);
}
