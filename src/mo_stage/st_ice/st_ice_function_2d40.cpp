#pragma force_active on
#include <mt/mt_vector.h>
#include <st/se_util.h>

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" const float lbl_62_rodata_68[];
extern "C" unsigned char lbl_62_data_7D8[];
extern "C" unsigned char lbl_62_data_588[];
extern "C" unsigned char lbl_62_data_798[];

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
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
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_62_3114();
    virtual void startup();
    virtual void slot38();
    virtual void fn_62_A44();
    virtual void fn_62_310C();
    virtual void fn_62_3108();
    virtual void fn_62_2C7C(int);
    virtual void fn_62_3100();
    virtual void fn_62_30F4();
    virtual void fn_62_30E4();
    virtual void fn_62_30D4();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_62_30D0();
    virtual void fn_62_30CC();
    virtual void fn_62_30C4();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_62_30BC();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(int);
};

struct Object {
    char pad[0x3c];
    void* vtable;
    char pad40[0x110];
    unsigned char flag;
    float value;
    int state;
    char seq[0x3c];
    SndID id;
    StSeUtil::UnkStruct entries[6];
};

extern "C" Object* fn_62_2D40(int a, int b, const char* name) {
    const float* data = lbl_62_rodata_68;
    Object* self = (Object*)__nw__FUlQ25Heaps8HeapType(0x1fc, 15);
    if (self) {
        __ct__10grYakumonoFPCc(self, name);
        self->vtable = lbl_62_data_7D8;
        self->flag = 0;
        self->value = data[0];
        ((Ground*)self)->setupMelee();
        self->vtable = lbl_62_data_588;
        char* seq = self->seq;
        __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(
            seq, seq + 0x20, 1, seq + 0x2c, 1);
        *(void**)seq = lbl_62_data_798;
        self->state = 0;
        self->id = (SndID)0x1c8c;
        self->entries[0].id = (SndID)0x1c8c;
        self->entries[0].unk4 = data[0];
        self->entries[0].unk8 = data[0];
        self->entries[0].unkC = data[0];
        self->entries[1].id = (SndID)0x1c8c;
        self->entries[1].unk4 = data[0];
        self->entries[1].unk8 = data[1];
        self->entries[1].unkC = data[0];
        self->entries[2].id = (SndID)0x1c8c;
        self->entries[2].unk4 = data[0];
        self->entries[2].unk8 = data[2];
        self->entries[2].unkC = data[0];
        self->entries[3].id = (SndID)0x1c8c;
        self->entries[3].unk4 = data[0];
        self->entries[3].unk8 = data[3];
        self->entries[3].unkC = data[0];
        self->entries[4].id = (SndID)0x1c8c;
        self->entries[4].unk4 = data[0];
        self->entries[4].unk8 = data[4];
        self->entries[4].unkC = data[0];
        self->entries[5].id = (SndID)0x1c8c;
        self->entries[5].unk4 = data[0];
        self->entries[5].unk8 = data[5];
        self->entries[5].unkC = data[0];
        ((StSeUtil::SeSeq*)seq)->registId(&self->id, 1);
        ((StSeUtil::SeSeq*)seq)->registSeq(
            0, self->entries, 6, (Heaps::HeapType)15);
    }
    if (self) {
        ((Ground*)self)->fn_62_2C7C(a);
        ((Ground*)self)->setTgtNode(b);
    }
    return self;
}
