#pragma force_active on
extern "C" {
extern char lbl_49_data_0[];
extern char lbl_49_data_E4[];
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_49_A4(void* p) {
    char* self = (char*)p;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_49_data_0, 6);
    *(void**)(self + 0x3c) = lbl_49_data_E4;
    *(int*)(self + 0x1d8) = 0;
    memset(self + 0x1dc, 0, 0x18);
    self[0x1f4] = 10;
    self[0x1f5] = 10;
    memset(self + 0x1f8, 0, 0x1a0);
    self[0x398] = 0;
    return p;
}
