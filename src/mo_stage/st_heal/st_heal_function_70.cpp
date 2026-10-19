#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
extern char lbl_87_data_4[];
extern char lbl_87_data_110[];
extern unsigned int lbl_87_data_0;

void* fn_87_70(void) {
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x2b4, 0xf);
    if (p) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_87_data_4, 0x36);
        *(void**)(p + 0x3c) = lbl_87_data_110;
        *(unsigned char*)(p + 0x2a8) = 0;
        *(unsigned int*)(p + 0x2ac) = lbl_87_data_0;
        *(unsigned int*)(p + 0x2b0) = 0;
    }
    return p;
}
}
