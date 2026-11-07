#pragma force_active on
extern "C" {
extern char lbl_47_data_0[];
extern char lbl_47_data_2C8[];
extern const float lbl_47_rodata_0;
extern const float lbl_47_rodata_4;
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_47_A4(void* p) {
    char* self = (char*)p;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_47_data_0, 4);
    *(void**)(self + 0x3c) = lbl_47_data_2C8;
    memset(self + 0x1d8, 0, 0x18);
    memset(self + 0x1f0, 0, 0x18);
    self[0x208] = 0;
    *(float*)(self + 0x20c) = lbl_47_rodata_0;
    *(float*)(self + 0x210) = lbl_47_rodata_0;
    *(float*)(self + 0x214) = lbl_47_rodata_4;
    self[0x218] = 5;
    memset(self + 0x21c, 0, 0x30);
    memset(self + 0x24c, 0, 4);
    memset(self + 0x250, 0, 0x18);
    memset(self + 0x268, 0, 2);
    self[0x26a] = 0;
    return p;
}
