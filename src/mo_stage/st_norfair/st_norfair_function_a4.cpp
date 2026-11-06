#pragma force_active on
extern "C" {
extern char lbl_54_data_0[];
extern char lbl_54_data_1CC[];
extern const float lbl_54_rodata_0;
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__13grTenganEventFv(void*);
void __dt__13grTenganEventFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_54_A4(void* p) {
    char* self = (char*)p;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_54_data_0, 0xb);
    *(void**)(self + 0x3c) = lbl_54_data_1CC;
    __construct_array(self + 0x214, (void (*)(void*))__ct__13grTenganEventFv, (void (*)(void*))__dt__13grTenganEventFv, 0xac, 5);
    __ct__13grTenganEventFv(self + 0x570);
    __ct__13grTenganEventFv(self + 0x61c);
    __ct__13grTenganEventFv(self + 0x6c8);
    *(float*)(self + 0x774) = lbl_54_rodata_0;
    *(float*)(self + 0x778) = lbl_54_rodata_0;
    *(float*)(self + 0x77c) = lbl_54_rodata_0;
    *(float*)(self + 0x780) = lbl_54_rodata_0;
    *(float*)(self + 0x784) = lbl_54_rodata_0;
    *(float*)(self + 0x788) = lbl_54_rodata_0;
    self[0x78c] = 0;
    self[0x78d] = 0;
    *(float*)(self + 0x790) = lbl_54_rodata_0;
    *(float*)(self + 0x794) = lbl_54_rodata_0;
    self[0x798] = 0;
    self[0x799] = 0;
    self[0x79a] = 1;
    *(float*)(self + 0x79c) = lbl_54_rodata_0;
    *(float*)(self + 0x7a0) = lbl_54_rodata_0;
    *(float*)(self + 0x7a4) = lbl_54_rodata_0;
    *(float*)(self + 0x7a8) = lbl_54_rodata_0;
    self[0x7ac] = 1;
    memset(self + 0x7b0, 0, 0x3c);
    self[0x7ec] = 0;
    self[0x7ed] = 8;
    memset(self + 0x7ee, 0, 4);
    memset(self + 0x7f4, 0, 0x30);
    *(int*)(self + 0x828) = 0;
    *(int*)(self + 0x82c) = 0;
    self[0x824] = 0;
    self[0x830] = 0;
    self[0x831] = 0;
    *(int*)(self + 0x834) = -1;
    *(int*)(self + 0x838) = -1;
    *(int*)(self + 0x83c) = -1;
    *(int*)(self + 0x840) = -1;
    *(int*)(self + 0x844) = -1;
    return p;
}
