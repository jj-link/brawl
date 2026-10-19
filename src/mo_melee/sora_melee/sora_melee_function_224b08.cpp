#pragma force_active on
typedef int s32;
typedef unsigned long u32;
typedef float f32;

extern f32 lbl_27_rodata_34B4;

class Stage {
public:
    void getDestroyBossParamCommon(u32 param);
};

struct DestroyBossParam {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

void Stage::getDestroyBossParamCommon(u32 param) {
    DestroyBossParam *p = (DestroyBossParam *)this;
    f32 f = lbl_27_rodata_34B4;
    s32 a = 0x3c;
    p->unk0 = a;
    p->unk4 = a;
    p->unk8 = f;
    p->unkC = 0xb4;
    p->unk10 = 0xf0;
    p->unk14 = 0x78;
}
