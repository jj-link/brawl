#pragma force_active on
extern "C" {
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* __ct__14snd3DGeneratorFv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void __construct_array(void*, void* (*)(void*), void (*)(void*), unsigned long, int);
void* memset(void*, int, unsigned long);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
void fn_27_22A9D4(void*, int);
extern const char lbl_85_data_0[];
extern char lbl_85_data_438[];
extern void* lbl_27_bss_5780;

void* fn_85_A4(char* self) {
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_85_data_0, 0x35);
    *(void**)(self + 0x3c) = (void*)lbl_85_data_438;
    __construct_array(self + 0x22c, __ct__14snd3DGeneratorFv, (void (*)(void*))__dt__14snd3DGeneratorFv, 8, 8);
    *(int*)(self + 0x1d8) = 0;
    *(int*)(self + 0x1dc) = 0;
    *(int*)(self + 0x1e0) = 0x2c;
    *(unsigned char*)(self + 0x1e4) = 0;
    *(unsigned char*)(self + 0x1e5) = 0;
    *(unsigned char*)(self + 0x1e6) = 0;
    *(int*)(self + 0x1f8) = 0;
    *(int*)(self + 0x1fc) = 0;
    *(int*)(self + 0x200) = 0;
    *(int*)(self + 0x204) = 0;
    *(unsigned char*)(self + 0x1e7) = 0;
    *(int*)(self + 0x1e8) = 0;
    *(int*)(self + 0x1ec) = 0;
    *(int*)(self + 0x1f0) = 0;
    *(int*)(self + 0x1f4) = 0;
    *(int*)(self + 0x208) = 0;
    memset(self + 0x26c, 0, 0x1a28);
    if (!lbl_27_bss_5780) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (p) {
            p = fn_27_22A914(p);
        }
        lbl_27_bss_5780 = p;
    }
    fn_27_22A9D4(lbl_27_bss_5780, 0x20);
    return self;
}
}
