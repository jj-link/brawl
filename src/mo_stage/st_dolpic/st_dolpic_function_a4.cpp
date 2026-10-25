#pragma force_active on
#pragma opt_propagation off

extern "C" {
extern char lbl_46_data_0[];
extern char lbl_46_data_8EC[];
extern const float lbl_46_rodata_0;
extern const float lbl_46_rodata_4;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__14snd3DGeneratorFv(void*);
void memset(void*, int, unsigned int);
void setIdentity__6MatrixFv(void*);

inline void* matrixAt(char* p, unsigned char index) {
    return p + index * 0x30 + 0x41C;
}

void* fn_46_A4(void* this_ptr) {
    char* p = (char*)this_ptr;

    __ct__7stMeleeFPCcQ26Stages11srStageKind(this_ptr, lbl_46_data_0, 3);
    *(char**)(p + 0x3C) = lbl_46_data_8EC;

    __ct__14snd3DGeneratorFv(p + 0x1FC);
    __ct__14snd3DGeneratorFv(p + 0x204);
    __ct__14snd3DGeneratorFv(p + 0x20C);
    __ct__14snd3DGeneratorFv(p + 0x214);
    __ct__14snd3DGeneratorFv(p + 0x21C);
    __ct__14snd3DGeneratorFv(p + 0x224);

    *(unsigned char*)(p + 0x1D8) = 0;
    *(unsigned char*)(p + 0x1D9) = 0x10;
    *(float*)(p + 0x1DC) = lbl_46_rodata_0;
    memset(p + 0x1E0, 0, 4);
    *(float*)(p + 0x1E4) = lbl_46_rodata_4;
    *(float*)(p + 0x1E8) = lbl_46_rodata_4;
    *(int*)(p + 0x1EC) = 100;
    *(int*)(p + 0x1F0) = 0;
    *(unsigned char*)(p + 0x1F4) = 5;
    *(unsigned char*)(p + 0x1F5) = 3;
    *(unsigned char*)(p + 0x1F6) = 3;
    *(unsigned char*)(p + 0x1F7) = 3;
    *(unsigned char*)(p + 0x1F8) = 3;
    *(unsigned char*)(p + 0x1F9) = 3;

    *(int*)(p + 0x22C) = -1;
    *(int*)(p + 0x230) = -1;
    *(int*)(p + 0x234) = -1;
    *(int*)(p + 0x238) = -1;
    *(int*)(p + 0x23C) = -1;
    *(int*)(p + 0x240) = -1;
    *(int*)(p + 0x244) = -1;
    *(float*)(p + 0x248) = lbl_46_rodata_0;
    *(float*)(p + 0x24C) = lbl_46_rodata_0;
    memset(p + 0x250, 0, 0x1B0);

    *(int*)(p + 0x418) = 0x24;
    *(float*)(p + 0x400) = lbl_46_rodata_0;
    *(float*)(p + 0x404) = lbl_46_rodata_0;
    *(float*)(p + 0x408) = lbl_46_rodata_0;
    *(float*)(p + 0x40C) = lbl_46_rodata_0;
    *(float*)(p + 0x410) = lbl_46_rodata_0;
    *(float*)(p + 0x414) = lbl_46_rodata_0;

    unsigned int i = 0;
    do {
        setIdentity__6MatrixFv(matrixAt(p, i));
        ++i;
    } while (i < 0xF);

    *(int*)(p + 0x6EC) = 0;
    *(int*)(p + 0x6F0) = 0;
    *(int*)(p + 0x6F4) = 0;
    *(int*)(p + 0x6F8) = 0;
    *(int*)(p + 0x6FC) = 0;
    *(int*)(p + 0x700) = 0;
    *(int*)(p + 0x704) = 0;
    *(int*)(p + 0x708) = 0;
    *(int*)(p + 0x70C) = 0;
    *(int*)(p + 0x710) = 0;

    setIdentity__6MatrixFv(p + 0x714);
    *(unsigned char*)(p + 0x744) = 0;
    *(unsigned char*)(p + 0x745) = 0;
    *(float*)(p + 0x748) = lbl_46_rodata_0;
    *(float*)(p + 0x74C) = lbl_46_rodata_4;
    *(float*)(p + 0x750) = lbl_46_rodata_4;
    *(float*)(p + 0x754) = lbl_46_rodata_4;
    *(int*)(p + 0x758) = 0;
    *(int*)(p + 0x760) = 0;
    *(int*)(p + 0x75C) = 0;

    return this_ptr;
}
}
