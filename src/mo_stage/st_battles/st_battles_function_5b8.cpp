#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
extern "C" const char lbl_42_data_0[];
extern "C" const char lbl_42_data_68[];

extern "C" void* fn_42_5B8() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1D8, 0x0F);
    if (p != 0) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_42_data_0, 1);
        *(void**)((char*)p + 0x3C) = (void*)lbl_42_data_68;
    }
    return p;
}
