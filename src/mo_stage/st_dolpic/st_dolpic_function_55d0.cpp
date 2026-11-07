#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <snd/snd_3d_generator.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Words12 { unsigned int v[12]; };

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();  // offset 0x8
    virtual void processBegin();  // offset 0xc
    virtual void processAnim();  // offset 0x10
    virtual void processUpdate();  // offset 0x14
    virtual void processPreMapCorrection();  // offset 0x18
    virtual void processMapCorrection();  // offset 0x1c
    virtual void processFixPosition();  // offset 0x20
    virtual void processPreCollision();  // offset 0x24
    virtual void processCollision();  // offset 0x28
    virtual void processCatch();  // offset 0x2c
    virtual void processHit();  // offset 0x30
    virtual void processCamera();  // offset 0x34
    virtual void processFixCamera();  // offset 0x38
    virtual void processEffect();  // offset 0x3c
    virtual void processGameProc();  // offset 0x40
    virtual void processEnd();  // offset 0x44
    virtual void renderPre();  // offset 0x48
    virtual void renderOpa();  // offset 0x4c
    virtual void renderXlu();  // offset 0x50
    virtual void processDebug();  // offset 0x54
    virtual void renderDebug();  // offset 0x58
    virtual void init();  // offset 0x5c
    virtual void fn_46_5428();  // offset 0x60
    virtual void fn_46_5490();  // offset 0x64
    virtual void loadGroundData();  // offset 0x68
    virtual void bindData();  // offset 0x6c
    virtual void setupMelee();  // offset 0x70
    virtual void setVisibility();  // offset 0x74
    virtual void setVisibilityByClipping();  // offset 0x78
    virtual void setVisibilityAttachedEffect();  // offset 0x7c
    virtual void receiveCollMsg();  // offset 0x80
    virtual void receiveCollMsg_Landing();  // offset 0x84
    virtual void receiveCollMsg_Heading();  // offset 0x88
    virtual void receiveCollMsg_Wall();  // offset 0x8c
    virtual void receiveCollMsg_Attack();  // offset 0x90
    virtual void unloadData();  // offset 0x94
    virtual void fn_46_4860();  // offset 0x98
    virtual void startup();  // offset 0x9c
    virtual void setNode();  // offset 0xa0
    virtual void fn_46_8D0();  // offset 0xa4
    virtual void fn_46_4858();  // offset 0xa8
    virtual void fn_46_4854();  // offset 0xac
    virtual void fn_46_44AC();  // offset 0xb0
    virtual void fn_46_484C();  // offset 0xb4
    virtual void fn_46_4840();  // offset 0xb8
    virtual void fn_46_4830();  // offset 0xbc
    virtual void fn_46_4820();  // offset 0xc0
    virtual void getNodeIndex();  // offset 0xc4
    virtual void getNodePosition(Vec3f* pos, unsigned long a, unsigned long b);  // offset 0xc8
};

extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator* self, Vec3f* pos);

extern "C" void fn_46_55D0(Ground* self) {
    char* cb = (char*)self + 0xd0;
    if (cb != 0) {
        nw4r::g3d::ScnMdlSimple* model = *(nw4r::g3d::ScnMdlSimple**)(*(char**)((char*)self + 0x44));
        if (model != 0) {
            if (model->m_calcWorldCallBack == 0) {
                *(int*)(cb + 0xc) = 0;
                *(int*)(*(char**)(cb + 4)) = *(int*)((char*)self + 0xc4);
                model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)cb;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = (short)*(int*)(*(char**)(cb + 4));
            }
            char* dst = *(char**)(cb + 4);
            char* src = *(char**)((char*)self + 0x164);
            *(Words12*)(dst + 0x50) = *(Words12*)src;
            Vec3f pos;
            self->getNodePosition(&pos, 0, 1);
            setPos__14snd3DGeneratorFP5Vec3f((snd3DGenerator*)((char*)self + 0x168), &pos);
        }
    }
}
