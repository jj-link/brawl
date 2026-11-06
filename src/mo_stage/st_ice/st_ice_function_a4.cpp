#pragma force_active on
extern "C" {
extern char lbl_62_data_0[];
extern char lbl_62_data_1F8[];
extern const float lbl_62_rodata_0;
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__9gfArchiveFv(void*);
void setIdentity__6MatrixFv(void*);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_62_A4(void* self) {
    char* p = (char*)self;
    unsigned int i;

    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_62_data_0, 0x17);
    *(void**)(p + 0x3c) = lbl_62_data_1F8;
    __ct__9gfArchiveFv(p + 0x4f8);
    __ct__9gfArchiveFv(p + 0x578);
    __ct__9gfArchiveFv(p + 0x5f8);
    __ct__9gfArchiveFv(p + 0x678);
    __ct__9gfArchiveFv(p + 0x6f8);
    __ct__9gfArchiveFv(p + 0x778);
    __ct__9gfArchiveFv(p + 0x7f8);
    __ct__9gfArchiveFv(p + 0x878);
    __ct__9gfArchiveFv(p + 0x8f8);
    __ct__9gfArchiveFv(p + 0x978);
    __ct__9gfArchiveFv(p + 0x9f8);

    p[0x1d8] = 0;
    *(float*)(p + 0x1dc) = lbl_62_rodata_0;
    i = 0;
    p[0x438] = 0xe;
    *(float*)(p + 0x43c) = lbl_62_rodata_0;
    *(float*)(p + 0x440) = lbl_62_rodata_0;
    *(float*)(p + 0x420) = lbl_62_rodata_0;
    *(float*)(p + 0x424) = lbl_62_rodata_0;
    *(float*)(p + 0x428) = lbl_62_rodata_0;
    *(float*)(p + 0x42c) = lbl_62_rodata_0;
    *(float*)(p + 0x430) = lbl_62_rodata_0;
    *(float*)(p + 0x434) = lbl_62_rodata_0;
    do {
        setIdentity__6MatrixFv(p + ((unsigned char)i * 0x30) + 0x1e0);
        i += 1;
    } while (i < 0xc);

    p[0x485] = 0;
    *(float*)(p + 0x488) = lbl_62_rodata_0;
    memset(p + 0x48c, 0, 0x18);
    memset(p + 0x4a4, 0, 0xc);
    *(int*)(p + 0x4b0) = -1;
    p[0x4b4] = 0xe;
    memset(p + 0x448, 0, 0x3c);
    p[0x484] = 0xe;
    p[0x4b5] = 0;
    *(float*)(p + 0x4b8) = lbl_62_rodata_0;
    p[0x4bc] = 0xe;
    p[0x4bd] = 0xe;
    p[0x4be] = 0;
    *(float*)(p + 0x4c0) = lbl_62_rodata_0;
    p[0x4c4] = 0xe;
    p[0x4c5] = 0xe;
    p[0x4c6] = 0;
    *(float*)(p + 0x4c8) = lbl_62_rodata_0;
    p[0x4cc] = 0xe;
    *(float*)(p + 0x4d0) = lbl_62_rodata_0;
    *(int*)(p + 0x4d4) = 0;
    *(int*)(p + 0x4d8) = 0;
    *(float*)(p + 0x4dc) = lbl_62_rodata_0;
    p[0x4e0] = 0;
    *(float*)(p + 0x4e4) = lbl_62_rodata_0;
    *(float*)(p + 0x4ec) = lbl_62_rodata_0;
    p[0x4f0] = 0xe;
    *(int*)(p + 0x4f4) = -1;

    return self;
}
