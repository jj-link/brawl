#include <string.h>
#pragma force_active on

extern "C" void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" const char lbl_77_data_0[];
extern "C" char lbl_77_data_1B8[];

extern "C" {
void* fn_77_D94() {
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x1fc, 0xf);
    if (p) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_77_data_0, 0x2b);
        *(char**)(p + 0x3c) = lbl_77_data_1B8;
        *(int*)(p + 0x1f8) = 0;
        *(int*)(p + 0x1f4) = 0;
        memset(p + 0x1dc, 0, 0x18);
    }
    return p;
}
}
