#pragma force_active on
#pragma opt_propagation off

extern "C" {
extern const char lbl_57_data_0[];
extern const char lbl_57_data_234[];
extern const float lbl_57_rodata_0;
extern const float lbl_57_rodata_4[];

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void fn_8009ED40(void*, int, int);
void fn_8009F1FC(void*);
void setIdentity__6MatrixFv(void*);

struct FlagWord {
    unsigned int mode : 3;
    unsigned int rest : 29;
};

void* fn_57_A4(void* this_ptr) {
    char* p = (char*)this_ptr;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(this_ptr, lbl_57_data_0, 0xE);
    *(const char**)(p + 0x3C) = lbl_57_data_234;
    fn_8009ED40(p + 0x3F4, 0, 1);
    *(unsigned char*)(p + 0x1D8) = 0;
    *(float*)(p + 0x1DC) = lbl_57_rodata_0;
    *(float*)(p + 0x1E0) = lbl_57_rodata_0;
    *(unsigned char*)(p + 0x1E4) = 0x15;
    for (unsigned char i = 0; i < 0xA; ++i) {
        setIdentity__6MatrixFv(p + i * 0x30 + 0x1E8);
    }
    *(unsigned char*)(p + 0x3C8) = 0;
    *(float*)(p + 0x3CC) = lbl_57_rodata_0;
    *(unsigned char*)(p + 0x3D0) = 0x15;
    *(unsigned char*)(p + 0x3D1) = 0x15;
    *(unsigned char*)(p + 0x3D2) = 0x15;
    *(unsigned char*)(p + 0x3D3) = 0x15;
    *(unsigned char*)(p + 0x3D4) = 0;
    *(float*)(p + 0x3D8) = lbl_57_rodata_0;
    *(float*)(p + 0x3DC) = lbl_57_rodata_0;
    *(float*)(p + 0x3E0) = lbl_57_rodata_0;
    *(unsigned int*)(p + 0x3E4) = 0xFFFFFFFF;
    *(float*)(p + 0x3E8) = lbl_57_rodata_0;
    *(float*)(p + 0x3EC) = lbl_57_rodata_0;
    *(float*)(p + 0x3F0) = lbl_57_rodata_0;
    fn_8009F1FC(p + 0x3F4);
    ((FlagWord*)(p + 0x3FC))->mode = 1;
    for (unsigned char i = 0; i < 0xD; ++i) {
        setIdentity__6MatrixFv(p + i * 0x30 + 0x4D8);
    }
    for (unsigned char i = 0; i < 0xC; ++i) {
        setIdentity__6MatrixFv(p + i * 0x30 + 0x748);
    }
    unsigned char i = 0;
    setIdentity__6MatrixFv(p + i * 0x30 + 0x988);
    *(unsigned char*)(p + 0x478) = i;
    *(float*)(p + 0x47C) = lbl_57_rodata_0;
    *(float*)(p + 0x480) = lbl_57_rodata_0;
    *(float*)(p + 0x484) = lbl_57_rodata_0;
    *(float*)(p + 0x488) = lbl_57_rodata_0;
    *(float*)(p + 0x48C) = lbl_57_rodata_0;
    *(float*)(p + 0x490) = lbl_57_rodata_0;
    *(float*)(p + 0x494) = lbl_57_rodata_0;
    *(float*)(p + 0x498) = lbl_57_rodata_0;
    *(float*)(p + 0x49C) = lbl_57_rodata_0;
    *(float*)(p + 0x4A0) = lbl_57_rodata_0;
    *(float*)(p + 0x4A4) = lbl_57_rodata_0;
    *(float*)(p + 0x4A8) = lbl_57_rodata_0;
    *(unsigned int*)(p + 0x4AC) = 0xFFFFFFFF;
    *(float*)(p + 0x4B0) = lbl_57_rodata_0;
    *(float*)(p + 0x4B4) = lbl_57_rodata_0;
    *(float*)(p + 0x4B8) = lbl_57_rodata_0;
    *(float*)(p + 0x4BC) = lbl_57_rodata_0;
    *(float*)(p + 0x4C0) = lbl_57_rodata_0;
    *(float*)(p + 0x4C4) = lbl_57_rodata_0;
    *(float*)(p + 0x4C8) = lbl_57_rodata_0;
    *(float*)(p + 0x4CC) = lbl_57_rodata_0;
    *(float*)(p + 0x4D0) = lbl_57_rodata_0;
    *(float*)(p + 0x4D4) = lbl_57_rodata_4[0];
    *(unsigned char*)(p + 0x9B8) = 0x15;
    *(unsigned char*)(p + 0x9B9) = i;
    *(float*)(p + 0x9BC) = lbl_57_rodata_0;
    *(float*)(p + 0x9C0) = lbl_57_rodata_0;
    *(float*)(p + 0x9C4) = lbl_57_rodata_0;
    *(unsigned char*)(p + 0x9C8) = 0x15;
    return this_ptr;
}
}
