#include <gf/gf_archive.h>
#include <types.h>
#pragma force_active on

struct grCollData {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

struct CollHdr {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u32 e;
    u32 f;
    u32 g;
};

struct CollPad { char pad[0x28]; };
struct CollSrc : CollPad {
    virtual void v0();
    virtual void v1(int);
};

struct Stage {
    char pad0[0x8C];
    CollSrc* unk8C;
    void testCollDataInit(gfArchive* arg0, grCollData* arg1, u32 arg2);
};

extern "C" void fn_27_2230F0(...);
extern "C" CollSrc* fn_801385AC();
extern "C" u16 fn_80138708(void*);
extern "C" u16 fn_80138710(void*);
extern "C" u16 fn_80138718(void*);
extern "C" u32 fn_80138720(void*);
extern "C" u32 fn_80138728(void*);
extern "C" u32 fn_80138730(void*);
extern "C" char lbl_27_data_4A17C[];

void Stage::testCollDataInit(gfArchive* arg0, grCollData* arg1, u32 arg2) {
    CollHdr* temp_r31 = (CollHdr*)arg0->getData((ARCNodeType)1, arg2, 0xFFFE);
    memset(arg1, 0, 0x28);
    if (temp_r31 != NULL) {
        arg1->unk0 = temp_r31->a;
        arg1->unk2 = temp_r31->b;
        arg1->unk4 = temp_r31->c;
        arg1->unk6 = temp_r31->d;
        arg1->unk8 = temp_r31->e + (u32)temp_r31;
        arg1->unkC = temp_r31->f + (u32)temp_r31;
        arg1->unk10 = temp_r31->g + (u32)temp_r31;
        return;
    }
    fn_27_2230F0(lbl_27_data_4A17C);
    if (this->unk8C == NULL) {
        CollSrc* obj = fn_801385AC();
        this->unk8C = obj;
        obj->v1(0);
    }
    arg1->unk0 = fn_80138708(this->unk8C);
    arg1->unk2 = fn_80138710(this->unk8C);
    arg1->unk4 = fn_80138718(this->unk8C);
    arg1->unk6 = ((CollHdr*)this->unk8C)->d;
    arg1->unk8 = fn_80138720(this->unk8C);
    arg1->unkC = fn_80138728(this->unk8C);
    arg1->unk10 = fn_80138730(this->unk8C);
}