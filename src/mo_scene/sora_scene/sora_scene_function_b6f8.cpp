#include <types.h>
#pragma force_active on

struct Sub {
    char pad0[0x48];
    u32 unk48;
};

struct Args {
    u32 a0;
    void* a4;
    void* a8;
    void* aC;
    void* a10;
    void* a14;
    void* a18;
    u32 a1C;
    void* a20;
    void* a24;
    u32 a28;
    void* a2C;
    void* a30;
};

struct Self {
    char pad0[0x35C];
    Sub* unk35C;
    void* unk360;
    void* unk364;
    void* unk368;
    void* unk36C;
    void* unk370;
    void* unk374;
    void* unk378;
    void* unk37C;
    u32 pad380;
    u32 h384;
    u32 h388;
    u32 h38C;
    u32 h390;
    u32 h394;
    u32 h398;
    u32 h39C;
    u32 h3A0;
    u32 h3A4;
};

extern "C" {
    s32 getReturnStatus__14gfFileIOHandleCFv(const void* h);
    void* getBuffer__14gfFileIOHandleCFv(const void* h);
    u32 getSize__14gfFileIOHandleCFv(const void* h);
    void release__14gfFileIOHandleFv(void* h);
    void fn_800B00B0(void* a, void* h);
    void Init__Q34nw4r3g3d7ResFileFPv(void* res);
    void* fn_80052DB0();
    void* fn_14_0(void* args);
    void* getInstance__14gfSceneManagerFv();
    extern const u8 lbl_1_rodata_6D0[];
}

extern "C" void fn_1_B6F8(Self* self) {
    Args args = {};
    fn_800B00B0(self->unk35C, &self->h3A4);
    release__14gfFileIOHandleFv(&self->h3A4);

    void* r14 = nullptr;
    void* b;
    if (getReturnStatus__14gfFileIOHandleCFv(&self->h384) == 0x15) {
        b = nullptr;
    } else {
        b = getBuffer__14gfFileIOHandleCFv(&self->h384);
        release__14gfFileIOHandleFv(&self->h384);
    }
    if (b != nullptr) {
        r14 = b;
        Init__Q34nw4r3g3d7ResFileFPv(&r14);
    }
    self->unk360 = r14;

    void* r10 = nullptr;
    if (getReturnStatus__14gfFileIOHandleCFv(&self->h388) == 0x15) {
        b = nullptr;
    } else {
        b = getBuffer__14gfFileIOHandleCFv(&self->h388);
        release__14gfFileIOHandleFv(&self->h388);
    }
    if (b != nullptr) {
        r10 = b;
        Init__Q34nw4r3g3d7ResFileFPv(&r10);
    }
    self->unk364 = r10;

    void* r0C = nullptr;
    if (getReturnStatus__14gfFileIOHandleCFv(&self->h38C) == 0x15) {
        b = nullptr;
    } else {
        b = getBuffer__14gfFileIOHandleCFv(&self->h38C);
        release__14gfFileIOHandleFv(&self->h38C);
    }
    if (b != nullptr) {
        r0C = b;
        Init__Q34nw4r3g3d7ResFileFPv(&r0C);
    }
    self->unk368 = r0C;

    void* r08 = nullptr;
    if (getReturnStatus__14gfFileIOHandleCFv(&self->h390) == 0x15) {
        b = nullptr;
    } else {
        b = getBuffer__14gfFileIOHandleCFv(&self->h390);
        release__14gfFileIOHandleFv(&self->h390);
    }
    if (b != nullptr) {
        r08 = b;
        Init__Q34nw4r3g3d7ResFileFPv(&r08);
    }
    self->unk36C = r08;

    if (getReturnStatus__14gfFileIOHandleCFv(&self->h394) == 0x15) {
        b = nullptr;
    } else {
        b = getBuffer__14gfFileIOHandleCFv(&self->h394);
        release__14gfFileIOHandleFv(&self->h394);
    }
    self->unk370 = b;

    if (getReturnStatus__14gfFileIOHandleCFv(&self->h398) == 0x15) {
        b = nullptr;
    } else {
        b = getBuffer__14gfFileIOHandleCFv(&self->h398);
        release__14gfFileIOHandleFv(&self->h398);
    }
    self->unk374 = b;

    if (getReturnStatus__14gfFileIOHandleCFv(&self->h39C) == 0x15) {
        b = nullptr;
    } else {
        b = getBuffer__14gfFileIOHandleCFv(&self->h39C);
        release__14gfFileIOHandleFv(&self->h39C);
    }
    self->unk378 = b;

    u32 size = getSize__14gfFileIOHandleCFv(&self->h3A0);
    void* b3a0;
    if (getReturnStatus__14gfFileIOHandleCFv(&self->h3A0) == 0x15) {
        b3a0 = nullptr;
    } else {
        b3a0 = getBuffer__14gfFileIOHandleCFv(&self->h3A0);
        release__14gfFileIOHandleFv(&self->h3A0);
    }
    self->unk37C = b3a0;

    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    args.a0 = lbl_1_rodata_6D0[*(s32*)(mgr + 0x280)];
    args.a4 = &self->unk360;
    args.a8 = &self->unk364;
    args.aC = &self->unk368;
    args.a10 = &self->unk36C;
    args.a14 = self->unk370;
    args.a20 = self->unk378;
    args.a18 = self->unk374;
    args.a24 = self->unk37C;
    args.a28 = size;
    args.a1C = self->unk35C->unk48;
    args.a2C = fn_80052DB0();
    fn_14_0(&args);
}
