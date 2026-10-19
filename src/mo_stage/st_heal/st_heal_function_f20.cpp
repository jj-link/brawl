#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
extern char lbl_87_data_0[];

void* fn_87_F20(void) {
    char* base = lbl_87_data_0;
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x2b4, 0xf);
    if (p) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(p, base + 4, 0x36);
        *(void**)(p + 0x3c) = base + 0x110;
        *(unsigned char*)(p + 0x2a8) = 0;
        *(unsigned int*)(p + 0x2ac) = *(unsigned int*)base;
        *(unsigned int*)(p + 0x2b0) = 0;
    }
    return p;
}
}
