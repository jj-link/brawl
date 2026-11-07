#include <sr/sr_common.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

typedef unsigned char u8;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual u8* slot3(u8);
};

class List : public nw4r::ut::detail::LinkListImpl {
public:
    using nw4r::ut::detail::LinkListImpl::Insert;
    using nw4r::ut::detail::LinkListImpl::GetEndIter;
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_63_3C84();
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
    virtual void fn_63_3BE4();
    virtual void fn_63_3D84();
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
    virtual void setNode();
    virtual void fn_63_59C();
    virtual void fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
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
    virtual void fn_63_3334();
    virtual void fn_63_3330();
    virtual void fn_63_3328();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_63_3320();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_63_1884();
    virtual void fn_63_339C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_63_3394();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_63_2D00();
    virtual void fn_63_2E10();
    virtual void fn_63_2ED8();
    virtual void fn_63_8FC();
    virtual void fn_63_904();
    virtual void fn_63_3DD4();
    virtual void fn_63_3E24();
    virtual void fn_63_462C();
    virtual void fn_63_470C();
    virtual void fn_63_484C();
    virtual void fn_63_4D18();
    virtual void fn_63_90C();
    virtual void fn_63_914();
    virtual void fn_63_91C();
    virtual void fn_63_924();
    virtual void fn_63_92C();
    virtual void fn_63_3E58();
    virtual void fn_63_3F00();
    virtual void fn_63_49B8();
    virtual void fn_63_4AE8();

    char pad2[0x184 - 0x40];
    u8* data;
    char pad3[8];
    Object_vptr_0* object;
    char pad4[0x1d0 - 0x194];
    List list;
};

struct Entry {
    nw4r::ut::LinkListNode node;
    u8 index;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, Heaps::HeapType);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8015C2BC(
    void*, nw4r::ut::detail::LinkListImpl::Iterator);

extern "C" void fn_63_49B8(Ground* self) {
    u8* data = self->object->slot3(*self->data);
    if (data) {
        for (u8 i = 0; i != 20; i++) {
            switch (data[i]) {
            case 10:
            case 11:
            case 12:
            case 13:
            case 14: {
                Entry* p = (Entry*)__nw__FUlQ25Heaps8HeapType(
                    12, Heaps::StageInstance);
                if (p) {
                    ((void**)p)[0] = 0;
                    ((void**)p)[1] = 0;
                }
                if (!p)
                    return;
                p->index = i;
                self->list.Insert(self->list.GetEndIter(), &p->node);
                break;
            }
            }
        }

        self->fn_63_4AE8();
        u8 n = self->list.GetSize();
        for (u8 i = 0; i != n; i++) {
            Entry* p = *(Entry**)((char*)&self->list + 4);
            fn_8015C2BC(
                &self->list,
                nw4r::ut::detail::LinkListImpl::Iterator(&p->node));
            if (p)
                __dl__FPv(p);
        }
    }
}
