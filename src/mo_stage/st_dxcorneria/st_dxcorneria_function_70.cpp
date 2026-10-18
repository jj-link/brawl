#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* __ct__14snd3DGeneratorFv(void*);
extern char lbl_82_data_90[];
extern char lbl_82_data_360[];
extern int lbl_82_data_0;

void* fn_82_70() {
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x104c, 0xf);
    if (p) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_82_data_90, 0x30);
        *(void**)(p + 0x3c) = lbl_82_data_360;
        *(int*)(p + 0xfac) = lbl_82_data_0;
        *(int*)(p + 0xfb0) = 0;
        __ct__14snd3DGeneratorFv(p + 0x1008);
        __ct__14snd3DGeneratorFv(p + 0x1018);
        __ct__14snd3DGeneratorFv(p + 0x1028);
        __ct__14snd3DGeneratorFv(p + 0x1034);
        *(int*)(p + 0x1040) = 0;
        *(char*)(p + 0x1048) = 0;
        *(int*)(p + 0x1044) = 0;
    }
    return p;
}
}
