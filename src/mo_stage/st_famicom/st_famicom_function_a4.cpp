#pragma force_active on
extern "C" {
extern char lbl_68_data_0[];
extern char lbl_68_data_208[];
extern const float lbl_68_rodata_0;
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__9gfArchiveFv(void*);
void initialize__15stCollisionWorkFv(void*);
void* memset(void*, int, unsigned long);
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

extern "C" void* fn_68_A4(void* self) {
    char* p = (char*)self;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_68_data_0, 0x1f);
    *(void**)(p + 0x3c) = lbl_68_data_208;
    __ct__9gfArchiveFv(p + 0x42c);
    __ct__9gfArchiveFv(p + 0x4ac);
    __ct__9gfArchiveFv(p + 0x52c);
    __ct__9gfArchiveFv(p + 0x5ac);

    initialize__15stCollisionWorkFv(p + 0x218);
    *(short*)(p + 0x224) = 0x18;
    p[0x226] = 1;
    initialize__15stCollisionWorkFv(p + 0x228);
    *(short*)(p + 0x234) = 0x1e;
    p[0x236] = 1;
    initialize__15stCollisionWorkFv(p + 0x238);
    *(short*)(p + 0x244) = 0x1e;
    p[0x246] = 1;
    initialize__15stCollisionWorkFv(p + 0x248);
    *(short*)(p + 0x254) = 0x12;
    p[0x256] = 1;
    initialize__15stCollisionWorkFv(p + 0x258);
    *(short*)(p + 0x264) = 0x12;
    p[0x266] = 1;
    initialize__15stCollisionWorkFv(p + 0x268);
    *(short*)(p + 0x274) = 0x1d;
    p[0x276] = 1;
    initialize__15stCollisionWorkFv(p + 0x278);
    *(short*)(p + 0x284) = 0x1d;
    p[0x286] = 1;

    memset(p + 0x298, 0, 0x54);
    *(float*)(p + 0x2ec) = lbl_68_rodata_0;
    *(float*)(p + 0x2f0) = lbl_68_rodata_0;
    *(float*)(p + 0x2f4) = lbl_68_rodata_0;
    *(int*)(p + 0x2f8) = 0;
    p[0x2fc] = 0xd;
    *(float*)(p + 0x300) = lbl_68_rodata_0;
    *(float*)(p + 0x304) = lbl_68_rodata_0;
    *(float*)(p + 0x308) = lbl_68_rodata_0;
    *(int*)(p + 0x30c) = 0;
    p[0x310] = 0xd;
    *(float*)(p + 0x314) = lbl_68_rodata_0;
    *(float*)(p + 0x318) = lbl_68_rodata_0;
    *(float*)(p + 0x31c) = lbl_68_rodata_0;
    *(int*)(p + 0x320) = 0;
    p[0x324] = 0xd;
    *(float*)(p + 0x328) = lbl_68_rodata_0;
    *(float*)(p + 0x32c) = lbl_68_rodata_0;
    *(float*)(p + 0x330) = lbl_68_rodata_0;
    *(int*)(p + 0x334) = 0;
    p[0x338] = 0xd;
    *(float*)(p + 0x33c) = lbl_68_rodata_0;
    *(float*)(p + 0x340) = lbl_68_rodata_0;
    *(float*)(p + 0x344) = lbl_68_rodata_0;
    *(int*)(p + 0x348) = 0;
    p[0x34c] = 0xd;
    *(float*)(p + 0x350) = lbl_68_rodata_0;
    *(float*)(p + 0x354) = lbl_68_rodata_0;
    *(float*)(p + 0x358) = lbl_68_rodata_0;
    *(int*)(p + 0x35c) = 0;
    p[0x360] = 0xd;
    *(float*)(p + 0x364) = lbl_68_rodata_0;
    *(float*)(p + 0x368) = lbl_68_rodata_0;
    *(float*)(p + 0x36c) = lbl_68_rodata_0;
    *(int*)(p + 0x370) = 0;
    p[0x374] = 0xd;
    *(int*)(p + 0x378) = 0;
    *(int*)(p + 0x37c) = 0;
    *(int*)(p + 0x380) = 0;
    *(int*)(p + 0x384) = 0;
    *(int*)(p + 0x388) = 0;
    *(int*)(p + 0x38c) = 0;
    *(int*)(p + 0x390) = 0;
    *(int*)(p + 0x394) = 0;

    initialize__15stCollisionWorkFv(p + 0x288);
    *(short*)(p + 0x294) = 0x4;
    p[0x296] = 1;
    memset(p + 0x398, 0, 0xc);

    p[0x3a4] = 0xd;
    p[0x3b0] = 0;
    *(float*)(p + 0x3b4) = lbl_68_rodata_0;
    *(float*)(p + 0x3b8) = lbl_68_rodata_0;
    memset(p + 0x3bc, 0, 0x30);

    p[0x3ec] = 0xd;
    p[0x3ed] = 0xd;
    p[0x3ee] = 1;
    p[0x3ef] = 0;
    p[0x3f0] = 0;
    *(float*)(p + 0x3f4) = lbl_68_rodata_0;
    *(int*)(p + 0x428) = 0;
    memset(p + 0x3f8, 0, 0x30);

    *(int*)(p + 0x3a8) = 0;
    *(int*)(p + 0x3ac) = 0;
    *(float*)(p + 0x1d8) = lbl_68_rodata_0;
    *(float*)(p + 0x1dc) = lbl_68_rodata_0;
    *(float*)(p + 0x1e0) = lbl_68_rodata_0;
    *(float*)(p + 0x1e4) = lbl_68_rodata_0;
    *(float*)(p + 0x1e8) = lbl_68_rodata_0;
    *(float*)(p + 0x1ec) = lbl_68_rodata_0;
    memset(p + 0x1f4, 0, 0x10);
    memset(p + 0x204, 0, 0x10);
    memset(p + 0x214, 0, 0x4);
    p[0x1f0] = 0xd;

    if (g_cmAIController != 0) {
        g_cmAIController->flags.bits.top = 1;
    }
    return self;
}