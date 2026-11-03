#pragma force_active on
extern "C" {
extern char lbl_51_data_0[];
extern char lbl_51_data_640[];
extern const float lbl_51_rodata_0;
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* memset(void*, int, unsigned long);
void setIdentity__6MatrixFv(void*);
}

typedef unsigned int u32;

union Flags {
    u32 raw;
    struct {
        u32 top : 8;
        u32 rest : 24;
    } bits;
};

struct cmAIController {
    int pad[2];
    Flags flags;
};

extern cmAIController* g_cmAIController;

extern "C" void* fn_51_A4(void* p) {
    char* self = (char*)p;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_51_data_0, 8);
    *(void**)(self + 0x3c) = lbl_51_data_640;
    memset(self + 0x1d8, 0, 0x18);
    memset(self + 0x1f0, 0, 0x9c);
    memset(self + 0x28c, 0, 0xc);
    memset(self + 0x298, 0, 0x24);
    memset(self + 0x2bc, 0, 0xc);
    memset(self + 0x2c8, 0, 0x18);
    memset(self + 0x2e0, 0, 0x18);
    memset(self + 0x2f8, 0, 0x30);
    memset(self + 0x328, 0, 0x30);
    memset(self + 0x358, 0, 0x30);
    memset(self + 0x388, 0, 0x24);
    memset(self + 0x3ac, 0, 0x24);
    setIdentity__6MatrixFv(self + 0x3d0);
    setIdentity__6MatrixFv(self + 0x400);
    *(int*)(self + 0x430) = 0;
    memset(self + 0x434, 0, 0xd);
    self[0x441] = 0;
    self[0x442] = 0;
    self[0x443] = 0;
    self[0x444] = 0;
    self[0x445] = 0;
    *(float*)(self + 0x448) = lbl_51_rodata_0;
    self[0x44c] = 0;
    self[0x44d] = 0;
    self[0x44e] = 0;
    self[0x44f] = 0;
    self[0x450] = 0;
    self[0x451] = 0;
    self[0x452] = 0;
    self[0x453] = 0;
    *(float*)(self + 0x454) = lbl_51_rodata_0;
    *(float*)(self + 0x458) = lbl_51_rodata_0;
    self[0x45c] = 1;
    *(float*)(self + 0x460) = lbl_51_rodata_0;
    self[0x464] = 0;
    *(float*)(self + 0x468) = lbl_51_rodata_0;
    *(int*)(self + 0x46c) = -1;
    self[0xe8] = 1;
    if (g_cmAIController != 0) {
        g_cmAIController->flags.bits.top = 1;
    }
    return p;
}
