#include <string.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
extern "C" char lbl_67_data_0[];
extern "C" char lbl_67_data_608[];

extern "C" void* fn_67_70() {
    char* self = (char*)__nw__FUlQ25Heaps8HeapType(0x24c, 0xf);
    if (self != 0) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_67_data_0, 0x1e);
        *(void**)(self + 0x3C) = lbl_67_data_608;
        *(int*)(self + 0x244) = 0;
        memset(self + 0x1D8, 0, 0x18);
        memset(self + 0x1F0, 0, 0x28);
        *(unsigned char*)(self + 0x248) = 0;
    }
    return self;
}
