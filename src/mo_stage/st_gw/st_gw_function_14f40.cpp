#include <types.h>
#pragma force_active on

struct GroundBase {
    char pad[0x3C];
};

struct Ground : GroundBase {
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_63_14838();
    virtual void fn_63_148BC();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_63_3378();
    virtual void startup();
    virtual void fn_63_14F40_slot();
    virtual void fn_63_59C();
    virtual void fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual u32 getNodeIndex(u32, const char*);

    char pad40[0x140];
    u32 nodes[24];
};

extern "C" char jumptable_63_data_5970[];
extern "C" void* setNode__9grGimmickFv(void*);

extern "C" void* fn_63_14F40(Ground* self) {
    char* base = (char*)&jumptable_63_data_5970;
    void* result = setNode__9grGimmickFv(self);

    self->nodes[0] = self->getNodeIndex(0, base + 0x40);
    self->nodes[1] = self->getNodeIndex(0, base + 0x48);
    self->nodes[2] = self->getNodeIndex(0, base + 0x54);
    self->nodes[3] = self->getNodeIndex(0, base + 0x60);
    self->nodes[4] = self->getNodeIndex(0, base + 0x6C);
    self->nodes[5] = self->getNodeIndex(0, base + 0x78);
    self->nodes[6] = self->getNodeIndex(0, base + 0x84);
    self->nodes[7] = self->getNodeIndex(0, base + 0x90);
    self->nodes[8] = self->getNodeIndex(0, base + 0x9C);
    self->nodes[9] = self->getNodeIndex(0, base + 0xA8);
    self->nodes[10] = self->getNodeIndex(0, base + 0xB4);
    self->nodes[11] = self->getNodeIndex(0, base + 0xC0);
    self->nodes[12] = self->getNodeIndex(0, base + 0xCC);
    self->nodes[13] = self->getNodeIndex(0, base + 0xD8);
    self->nodes[14] = self->getNodeIndex(0, base + 0xE4);
    self->nodes[15] = self->getNodeIndex(0, base + 0xF0);
    self->nodes[16] = self->getNodeIndex(0, base + 0xFC);
    self->nodes[17] = self->getNodeIndex(0, base + 0x108);
    self->nodes[18] = self->getNodeIndex(0, base + 0x114);
    self->nodes[19] = self->getNodeIndex(0, base + 0x120);
    self->nodes[20] = self->getNodeIndex(0, base + 0x12C);
    self->nodes[21] = self->getNodeIndex(0, base + 0x138);
    self->nodes[22] = self->getNodeIndex(0, base + 0x144);
    self->nodes[23] = self->getNodeIndex(0, base + 0x150);

    return result;
}
