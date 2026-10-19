#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
extern const char lbl_42_data_0[];
extern char lbl_42_data_68[];

void* fn_42_70() {
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x1d8, 0xf);
    if (p) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_42_data_0, 1);
        *(void**)(p + 0x3c) = lbl_42_data_68;
    }
    return p;
}
}
