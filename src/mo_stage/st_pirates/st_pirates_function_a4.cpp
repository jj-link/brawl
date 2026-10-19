#pragma force_active on
extern "C" void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" void setIdentity__6MatrixFv(void*);
extern "C" void* memset(void*, int, unsigned long);
extern "C" const char lbl_52_data_0[];
extern "C" const char lbl_52_data_484[];
extern "C" const float lbl_52_rodata_0;
extern "C" const float lbl_52_rodata_4;

extern "C" void* fn_52_A4(void* self) {
    unsigned char* p = (unsigned char*)self;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_52_data_0, 9);
    *(const char**)(p + 0x3C) = lbl_52_data_484;
    __ct__14snd3DGeneratorFv(p + 0x5F4);
    *(unsigned char*)(p + 0x1D8) = 0;
    *(float*)(p + 0x1DC) = lbl_52_rodata_0;
    *(unsigned char*)(p + 0x1E0) = 0;
    *(unsigned char*)(p + 0x1E1) = 0;
    for (unsigned int i = 0; i < 0x12; i++) {
        setIdentity__6MatrixFv(p + (unsigned char)i * 0x30 + 0x1E4);
    }
    *(float*)(p + 0x544) = lbl_52_rodata_0;
    *(float*)(p + 0x548) = lbl_52_rodata_0;
    *(float*)(p + 0x54C) = lbl_52_rodata_0;
    *(float*)(p + 0x550) = lbl_52_rodata_0;
    *(float*)(p + 0x554) = lbl_52_rodata_0;
    *(float*)(p + 0x558) = lbl_52_rodata_0;
    *(unsigned char*)(p + 0x55C) = 9;
    *(unsigned char*)(p + 0x55D) = 0;
    *(float*)(p + 0x560) = lbl_52_rodata_0;
    *(float*)(p + 0x564) = lbl_52_rodata_0;
    *(unsigned char*)(p + 0x568) = 0;
    *(unsigned char*)(p + 0x569) = 0;
    *(unsigned char*)(p + 0x56A) = 1;
    *(unsigned char*)(p + 0x56B) = 0;
    *(unsigned char*)(p + 0x56C) = 0;
    *(unsigned char*)(p + 0x56D) = 0;
    *(unsigned char*)(p + 0x56E) = 7;
    *(unsigned char*)(p + 0x56F) = 0;
    *(unsigned char*)(p + 0x570) = 0;
    memset(p + 0x574, 0, 0x60);
    *(float*)(p + 0x5D4) = lbl_52_rodata_0;
    *(float*)(p + 0x5D8) = lbl_52_rodata_0;
    *(float*)(p + 0x5DC) = lbl_52_rodata_0;
    *(float*)(p + 0x5E0) = lbl_52_rodata_0;
    *(unsigned char*)(p + 0x5E4) = 0;
    *(float*)(p + 0x5E8) = lbl_52_rodata_0;
    *(unsigned char*)(p + 0x5EC) = 0;
    *(unsigned char*)(p + 0x5ED) = 7;
    *(unsigned char*)(p + 0x5EE) = 7;
    *(unsigned char*)(p + 0x5EF) = 7;
    *(unsigned char*)(p + 0x5F0) = 7;
    *(unsigned char*)(p + 0x5F1) = 7;
    *(int*)(p + 0x600) = 0;
    *(int*)(p + 0x5FC) = 0;
    *(float*)(p + 0x604) = lbl_52_rodata_4;
    *(unsigned char*)(p + 0x608) = 0;
    *(unsigned char*)(p + 0x609) = 7;
    *(unsigned char*)(p + 0x60A) = 7;
    *(unsigned char*)(p + 0x60B) = 7;
    return self;
}
