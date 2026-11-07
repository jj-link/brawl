#pragma force_active on

struct FlagWord {
    unsigned int mode : 8;
    unsigned int rest : 24;
};

extern "C" {

extern const char lbl_63_data_0[];
extern const char lbl_63_data_580[];
extern const float lbl_63_rodata_0;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void initialize__15stCollisionWorkFv(void*);
void* memset(void*, int, unsigned long);

struct cmAIControllerFlags {
    int pad[2];
    FlagWord flags;
};
extern cmAIControllerFlags* g_cmAIController;

void* fn_63_A4(void* self) {
    unsigned char* p = (unsigned char*)self;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_63_data_0, 0x18);
    *(float*)(p + 0x1E8) = lbl_63_rodata_0;
    *(const char**)(p + 0x3C) = lbl_63_data_580;
    *(float*)(p + 0x1EC) = lbl_63_rodata_0;
    *(float*)(p + 0x1F0) = lbl_63_rodata_0;
    *(float*)(p + 0x1F4) = lbl_63_rodata_0;
    *(float*)(p + 0x1F8) = lbl_63_rodata_0;
    *(float*)(p + 0x1FC) = lbl_63_rodata_0;
    *(float*)(p + 0x200) = lbl_63_rodata_0;
    p[0x1E4] = 1;
    p[0x1D8] = 0;
    *(float*)(p + 0x1DC) = lbl_63_rodata_0;
    p[0x1E0] = 0;
    p[0x1E1] = 4;
    p[0x1E2] = 4;
    p[0x1E3] = 4;
    initialize__15stCollisionWorkFv(p + 0x204);
    p[0x212] = 0;
    *(short*)(p + 0x210) = 2;
    memset(p + 0x214, 0, 0xF0);
    p[0x304] = 0;
    p[0x305] = 0xFF;
    p[0x306] = 0x10;
    p[0x30C] = 0xB;
    p[0x30D] = 0xB;
    p[0x30E] = 0xB;
    p[0x30F] = 0;
    p[0x310] = 0;
    p[0x311] = 0;
    *(float*)(p + 0x314) = lbl_63_rodata_0;
    *(float*)(p + 0x318) = lbl_63_rodata_0;
    *(float*)(p + 0x31C) = lbl_63_rodata_0;
    p[0x320] = 0xFF;
    memset(p + 0x324, 0, 0x24);
    p[0x348] = 0x10;
    memset(p + 0x34C, 0, 0x24);
    memset(p + 0x370, 0, 0x24);
    memset(p + 0x394, 0, 0x60);
    p[0x3F5] = 0;
    p[0x3F4] = 0xD;
    memset(p + 0x3F8, 0, 0x60);
    p[0x458] = 0xD;
    p[0x459] = 0;
    *(int*)(p + 0x45C) = 0;
    *(int*)(p + 0x464) = 0;
    if (g_cmAIController != 0) {
        g_cmAIController->flags.mode = 1;
    }
    return self;
}

}