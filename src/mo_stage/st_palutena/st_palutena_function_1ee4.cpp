#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* memset(void*, int, unsigned long);
extern char lbl_67_data_0[];
extern char lbl_67_data_608[];
}

extern "C" void* fn_67_1EE4() {
    char* self = (char*)__nw__FUlQ25Heaps8HeapType(0x24C, 0xF);
    if (self) {
        __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_67_data_0, 0x1E);
        *(void**)(self + 0x3C) = lbl_67_data_608;
        *(int*)(self + 0x244) = 0;
        memset(self + 0x1D8, 0, 0x18);
        memset(self + 0x1F0, 0, 0x28);
        self[0x248] = 0;
    }
    return self;
}
