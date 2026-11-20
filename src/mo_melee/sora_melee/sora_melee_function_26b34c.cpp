#include <types.h>
#include <gr/gr_gimmick.h>
#include <gr/gr_gimmick_motion_path.h>
#include <sr/sr_common.h>
#include <st/st_trigger.h>
#pragma force_active on

#define MP_AT(g) ((g)->m_gimmickMotionPath)

extern "C" {
grGimmickMotionPath* create__19grGimmickMotionPathFiPCcPCc(short, const char*, const char*);
extern const char lbl_27_data_56784[];
extern const char lbl_27_data_56D70[];
extern const char lbl_27_data_4C640[];
extern const char lbl_27_data_4C5E8[];
extern const f32 lbl_27_rodata_4388;
extern const f32 lbl_27_rodata_4398;
void fn_27_26E428(grGimmickMotionPath*);
void fn_27_26E434(grGimmickMotionPath*);
void fn_27_26ED70(grGimmickMotionPath*);
void fn_27_233F58(void*, void*);
void fn_27_233FCC(void*, void*);
}

struct PathSlotsBase {
    char pad[0x3C];
};

class PathSlots : public PathSlotsBase {
public:
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
    virtual ~PathSlots();
    virtual void update();
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
    virtual void getModelCount();
    virtual void startup(gfArchive*, u32, gfSceneRoot::LayerType);
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual u32 getNodeIndex(u32, const char*);
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
    virtual void setInitializeFlag();
    virtual void setInitializeInfo();
    virtual void getInitializeInfo();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void adventureEventGetItem();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fn_27_26E95C();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData(void*);
};

#define SND_AT(g, off, idx) ((grGimmick::Effect_Info*)((char*)(g)->m_soundEffects + (off)))[idx]
#define EF_AT(g, off, idx) ((grGimmick::Effect_Info*)((char*)(g)->m_effects + (off)))[idx]

template <int OFF>
inline void setSndEffect(grGimmick* g, int idx, grGimmick::SimpleEffectData* e, const Vec2f& off)
{
    if (e->m_id > 0) {
        SND_AT(g, OFF, idx).m_id = e->m_id;
        SND_AT(g, OFF, idx).m_repeatFrame = (u16)e->m_repeatFrame;
        SND_AT(g, OFF, idx).m_nodeIndex = (u16)e->m_nodeIndex;
        SND_AT(g, OFF, idx).m_endFrame = (u16)e->m_endFrame;
        SND_AT(g, OFF, idx).m_generatorIndex = 0;
        if (OFF == 0) {
            SND_AT(g, OFF, idx).m_offsetPos = off;
        } else {
            int displacement = idx * (int)sizeof(grGimmick::Effect_Info);
            u32 address = displacement + reinterpret_cast<u32>(g->m_soundEffects);
            reinterpret_cast<grGimmick::Effect_Info*>(address + OFF)->m_offsetPos = off;
        }
    }
}

template <int OFF>
inline void setEfEffect(grGimmick* g, int idx, grGimmick::SimpleEffectData* e, const Vec2f& off, float scale)
{
    if (e->m_id > 0) {
        EF_AT(g, OFF, idx).m_id = e->m_id;
        EF_AT(g, OFF, idx).m_repeatFrame = (u16)e->m_repeatFrame;
        u16 node = e->m_nodeIndex;
        if (node == 0) {
            EF_AT(g, OFF, idx).m_nodeIndex = ((PathSlots*)g)->getNodeIndex(0, lbl_27_data_56D70);
        } else {
            EF_AT(g, OFF, idx).m_nodeIndex = node;
        }
        EF_AT(g, OFF, idx).m_endFrame = (u16)e->m_endFrame;
        if (OFF == 0) {
            EF_AT(g, OFF, idx).m_offsetPos = off;
        } else {
            int displacement = idx * (int)sizeof(grGimmick::Effect_Info);
            u32 address = displacement + reinterpret_cast<u32>(g->m_effects);
            reinterpret_cast<grGimmick::Effect_Info*>(address + OFF)->m_offsetPos = off;
        }
        EF_AT(g, OFF, idx).m_scale = scale;
    }
}

template <int OFF>
inline void setSndEffectWithOffset(grGimmick* g, int idx, grGimmick::SimpleEffectData* e, Vec2f& source, Vec2f& copy)
{
    source.m_x = lbl_27_rodata_4388;
    source.m_y = lbl_27_rodata_4388;
    __memcpy(&copy, &source, sizeof(Vec2f));
    setSndEffect<OFF>(g, idx, e, copy);
}

template <int OFF>
inline void setEfEffectWithOffset(grGimmick* g, int idx, grGimmick::SimpleEffectData* e, Vec2f& source, Vec2f& copy, float scale)
{
    source.m_x = lbl_27_rodata_4388;
    source.m_y = lbl_27_rodata_4388;
    __memcpy(&copy, &source, sizeof(Vec2f));
    setEfEffect<OFF>(g, idx, e, copy, scale);
}

void grGimmick::createAttachMotionPath(grGimmickMotionPathInfo* info, stTriggerData* trig, const char* name)
{
    if ((u8)info->m_motionPathData->m_mdlIndex <= 9 ||
        (u8)info->m_motionPathData->m_mdlIndex == 0xff) {
        return;
    }
    {
        m_motionRatio = info->m_motionPathData->m_motionRatio;
        MP_AT(this) = create__19grGimmickMotionPathFiPCcPCc(*reinterpret_cast<const u8*>(&info->m_motionPathData->m_mdlIndex), name, lbl_27_data_56784);

        if (info->m_0xc != NULL || info->m_0x10 != NULL || info->m_0x14 != NULL) {
            fn_27_26E428(MP_AT(this));
        }
        if (info->m_0x18 != NULL || info->m_0x1c != NULL || info->m_0x20 != NULL) {
            fn_27_26E434(MP_AT(this));
        }
        m_motionPathFlags = *(u8*)((char*)info + 8);
        ((PathSlots*)MP_AT(this))->setGimmickData(info->m_motionPathData);

        grGimmickMotionPath* listPath = MP_AT(this);
        listPath->m_connectedTask = this;

        if (m_attachedTask == NULL) {
            m_attachedTask = listPath;
        } else {
            gfTask* node = m_attachedTask;
            while (node->m_nextTask != NULL) {
                node = node->m_nextTask;
            }
            node->m_nextTask = listPath;
        }

        ((PathSlots*)MP_AT(this))->startup(info->m_archive, 0, (gfSceneRoot::LayerType)0);

        struct Offsets {
            Vec2f ef2Copy, ef3Copy, snd2Copy, snd3Copy;
            Vec2f ef3Source, ef2Source, ef1Source, ef1Copy;
            Vec2f snd3Source, snd2Source, snd1Source, snd1Copy;
        } offsets;

        for (int i = 0; i < 3; i++) {
            if (info->m_0xc != NULL) {
                SimpleEffectData* e = &info->m_0xc[i];
                if (e->m_id > 0) {
                    setSndEffectWithOffset<0>(MP_AT(this), i, e, offsets.snd1Source,
                                               offsets.snd1Copy);
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (info->m_0x10 != NULL) {
                SimpleEffectData* e = &info->m_0x10[i];
                if (e->m_id > 0) {
                    setSndEffectWithOffset<0x78>(MP_AT(this), i, e, offsets.snd2Source,
                                               offsets.snd2Copy);
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            if (info->m_0x14 != NULL) {
                SimpleEffectData* e = &info->m_0x14[i];
                if (e->m_id > 0) {
                    setSndEffectWithOffset<0x140>(MP_AT(this), i, e, offsets.snd3Source,
                                               offsets.snd3Copy);
                }
            }
        }

        for (int i = 0; (u32)i < 3; i++) {
            if (info->m_0x18 != NULL) {
                if (info->m_0x18[i].m_id > 0) {
                    setEfEffectWithOffset<0>(MP_AT(this), i, &info->m_0x18[i], offsets.ef1Source,
                                               offsets.ef1Copy, lbl_27_rodata_4398);
                }
            }
        }

        for (int i = 0; (u32)i < 5; i++) {
            if (info->m_0x1c != NULL) {
                if (info->m_0x1c[i].m_id > 0) {
                    setEfEffectWithOffset<0x78>(MP_AT(this), i, &info->m_0x1c[i], offsets.ef2Source,
                                               offsets.ef2Copy, lbl_27_rodata_4398);
                }
            }
        }

        for (int i = 0; (u32)i < 3; i++) {
            if (info->m_0x20 != NULL) {
                if (info->m_0x20[i].m_id > 0) {
                    setEfEffectWithOffset<0x140>(MP_AT(this), i, &info->m_0x20[i], offsets.ef3Source,
                                               offsets.ef3Copy, lbl_27_rodata_4398);
                }
            }
        }

        fn_27_26ED70(MP_AT(this));
        if (trig != NULL) {
            if (trig->m_triggerId != 0) {
                char* b1;
                char* b2;
                stTrigger* t = g_stTriggerMng->createTrigger(Gimmick::Area_MotionPath, trig);
                b1 = (char*)operator new(0x14, Heaps::StageInstance);
                if (b1 != NULL) {
                    f32 ratio = info->m_motionPathData->m_motionRatio;
                    grGimmickMotionPath* path = MP_AT(this);
                    *(s32*)(b1 + 0) = 0;
                    *(s32*)(b1 + 8) = 0;
                    *(const char**)(b1 + 4) = lbl_27_data_4C640;
                    *(grGimmickMotionPath**)(b1 + 0xC) = path;
                    *(f32*)(b1 + 0x10) = ratio;
                }
                b2 = (char*)operator new(0x10, Heaps::StageInstance);
                if (b2 != NULL) {
                    grGimmickMotionPath* path = MP_AT(this);
                    *(s32*)(b2 + 0) = 0;
                    *(s32*)(b2 + 8) = 0;
                    *(const char**)(b2 + 4) = lbl_27_data_4C5E8;
                    *(grGimmickMotionPath**)(b2 + 0xC) = path;
                }
                if (trig->m_isValid) {
                    fn_27_233F58(t, b1);
                    fn_27_233FCC(t, b2);
                } else {
                    fn_27_233F58(t, b2);
                    fn_27_233FCC(t, b1);
                    MP_AT(this)->startMove();
                }
            } else {
                MP_AT(this)->startMove();
            }
        } else {
            MP_AT(this)->startMove();
        }
    }
}
