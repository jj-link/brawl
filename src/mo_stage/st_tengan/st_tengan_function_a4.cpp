#pragma force_active on
extern "C" {
extern char lbl_60_data_0[];
extern char lbl_60_data_4D8[];
extern const float lbl_60_rodata_0;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__14snd3DGeneratorFv(void*);
void __ct__13grTenganEventFv(void*);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_60_A4(void* self) {
    char* p = (char*)self;

    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_60_data_0, 0x15);
    *(void**)(p + 0x3c) = lbl_60_data_4D8;
    __ct__14snd3DGeneratorFv(p + 0x208);
    __ct__13grTenganEventFv(p + 0x21c);
    __ct__13grTenganEventFv(p + 0x2c8);
    __ct__13grTenganEventFv(p + 0x374);
    __ct__13grTenganEventFv(p + 0x420);
    __ct__13grTenganEventFv(p + 0x4cc);
    __ct__13grTenganEventFv(p + 0x578);
    __ct__13grTenganEventFv(p + 0x624);
    __ct__13grTenganEventFv(p + 0x6d0);
    __ct__13grTenganEventFv(p + 0x77c);
    __ct__13grTenganEventFv(p + 0x828);
    __ct__13grTenganEventFv(p + 0x8d4);
    __ct__13grTenganEventFv(p + 0x980);
    __ct__13grTenganEventFv(p + 0xa2c);
    __ct__13grTenganEventFv(p + 0xad8);
    __ct__13grTenganEventFv(p + 0xb84);
    __ct__13grTenganEventFv(p + 0xc30);
    __ct__13grTenganEventFv(p + 0xcdc);
    __ct__13grTenganEventFv(p + 0xd88);

    *(unsigned char*)(p + 0xef1) = 255;
    *(float*)(p + 0x1d8) = lbl_60_rodata_0;
    *(float*)(p + 0x1dc) = lbl_60_rodata_0;
    *(float*)(p + 0x1e0) = lbl_60_rodata_0;
    *(float*)(p + 0x1e4) = lbl_60_rodata_0;
    *(float*)(p + 0x1e8) = lbl_60_rodata_0;
    *(float*)(p + 0x1ec) = lbl_60_rodata_0;
    *(float*)(p + 0x1f0) = lbl_60_rodata_0;
    *(float*)(p + 0x1f4) = lbl_60_rodata_0;
    *(float*)(p + 0x1f8) = lbl_60_rodata_0;
    *(float*)(p + 0x1fc) = lbl_60_rodata_0;
    *(float*)(p + 0x200) = lbl_60_rodata_0;
    *(int*)(p + 0x204) = 0;
    *(int*)(p + 0x210) = -1;
    *(int*)(p + 0x214) = 0;
    *(int*)(p + 0x218) = -1;
    *(float*)(p + 0xe34) = lbl_60_rodata_0;
    *(float*)(p + 0xe38) = lbl_60_rodata_0;
    *(float*)(p + 0xe3c) = lbl_60_rodata_0;
    *(float*)(p + 0xe40) = lbl_60_rodata_0;
    *(float*)(p + 0xe44) = lbl_60_rodata_0;
    *(float*)(p + 0xe48) = lbl_60_rodata_0;
    *(int*)(p + 0xe4c) = 0;
    *(int*)(p + 0xe50) = 0;
    *(unsigned char*)(p + 0xe54) = 0;
    *(unsigned char*)(p + 0xe55) = 0;
    *(float*)(p + 0xe58) = lbl_60_rodata_0;
    *(float*)(p + 0xe5c) = lbl_60_rodata_0;
    *(unsigned char*)(p + 0xe60) = 0;
    *(float*)(p + 0xe64) = lbl_60_rodata_0;
    *(unsigned char*)(p + 0xe68) = 0;
    *(unsigned char*)(p + 0xe69) = 0;
    *(unsigned char*)(p + 0xe6a) = 0;
    *(unsigned char*)(p + 0xe6b) = 0;

    memset(p + 0xe6c, 0, 0x30);

    *(int*)(p + 0xe9c) = -1;
    *(int*)(p + 0xea0) = -1;
    *(float*)(p + 0xea4) = lbl_60_rodata_0;
    *(unsigned char*)(p + 0xea8) = 0;
    *(int*)(p + 0xeac) = 0;
    *(int*)(p + 0xeb0) = -1;
    *(int*)(p + 0xeb4) = 0;
    *(unsigned char*)(p + 0xeb8) = 0;
    *(unsigned char*)(p + 0xeb9) = 0;
    *(unsigned char*)(p + 0xeba) = 0;
    *(float*)(p + 0xebc) = lbl_60_rodata_0;
    *(float*)(p + 0xec0) = lbl_60_rodata_0;
    *(float*)(p + 0xec4) = lbl_60_rodata_0;
    *(unsigned char*)(p + 0xec8) = 0;
    *(float*)(p + 0xecc) = lbl_60_rodata_0;
    *(float*)(p + 0xed0) = lbl_60_rodata_0;
    *(float*)(p + 0xed4) = lbl_60_rodata_0;
    *(float*)(p + 0xed8) = lbl_60_rodata_0;
    *(int*)(p + 0xedc) = 0;
    *(int*)(p + 0xee0) = -1;
    *(int*)(p + 0xee4) = -1;
    *(int*)(p + 0xee8) = -1;
    *(float*)(p + 0xeec) = lbl_60_rodata_0;
    *(unsigned char*)(p + 0xef0) = 0;
    *(unsigned char*)(p + 0xef1) = 255;

    return p;
}
