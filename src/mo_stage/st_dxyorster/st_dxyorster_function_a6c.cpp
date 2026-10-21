#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* memset(void*, int, unsigned long);
extern char lbl_76_data_0[];
extern char lbl_76_data_D4[];

void* fn_76_A6C() {
    char* self = (char*)__nw__FUlQ25Heaps8HeapType(0x250, 0xF);
    if (self) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_76_data_0, 0x2a);
        *(char**)(self + 0x3c) = lbl_76_data_D4;
        memset(self + 0x1d8, 0, 0x6c);
        self[0x244] = 1;
        self[0x245] = 1;
        self[0x246] = 0;
        memset(self + 0x247, 0, 9);
    }
    return self;
}
}
