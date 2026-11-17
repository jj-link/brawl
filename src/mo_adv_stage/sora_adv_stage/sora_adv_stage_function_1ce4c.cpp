#include <types.h>
#include <cm/cm_camera_controller.h>
#pragma force_active on
class grYakumono_base { public: char pad[0x3C]; };
class grYakumono : public grYakumono_base {
public:
    virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate();
    virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
    virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
    virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
    virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init();
    virtual void fn_40_1C140(); virtual void fn_40_1CCE0(); virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee();
    virtual void setVisibility(); virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing(); virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack(); virtual void unloadData(); virtual void getModelCount(); virtual void fn_40_1C3DC();
    virtual void setNode(); virtual void setStageData(); virtual void getStageData(); virtual void initStageData(); virtual void setMdlIndex();
    virtual void getMdlIndex(); virtual void isEnableCalcCollision(); virtual void enableCalcCollision(); virtual void disableCalcCollision();
    virtual void getNodeIndex(); virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
    virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
    virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
    virtual void setValid(); virtual void setValidAttachedEffect(); virtual void setInitializeFlag(); virtual void fn_40_1CB5C(); virtual void fn_40_1CC10();
    virtual void setMotionRatio(); virtual void setMotionFrame(); virtual void getMotionFrame(); virtual void setMotionLoop();
    virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld(); virtual void preExit();
    virtual void adventureEventGetItem(); virtual void fn_40_1CE4C(); virtual void setTransparencyFlag(char);
    virtual void updateCallback(); virtual void fixedPosition(); virtual void setTgtNode(); virtual void getTgtNode(); virtual void setGimmickData();
    virtual void getGimmickData(); virtual void changeNodeAnim(); virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel(); virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction(); virtual void fn_40_1D24C(); virtual void setTransparency(u32, u32);
    virtual int getTransparencyFlag();
    void setSleepHit(bool);
};
extern "C" int fn_80019C10(int manager, float* position, float, float, float);
extern "C" void fn_40_1CE4C(grYakumono* self) {
    CameraController* camera = CameraController::getInstance();
    gfCameraController* controller = camera->m_currentController;
    if (controller != 0 && *(int*)controller != 0) {
        float f3 = *(float*)((char*)self + 0xF8);
        float f2 = *(float*)((char*)self + 0xF4);
        float f1 = *(float*)((char*)self + 0xF0);
        float position[4];
        position[0] = *(float*)((char*)self + 0xEC);
        position[1] = f1;
        position[2] = f2;
        position[3] = f3;
        if (fn_80019C10(*(int*)controller, position, f1, f2, f3) == 0) {
            if (self->getTransparencyFlag() != 0) {
                int offset;
                u32 i;
                i = 0;
                offset = 0;
                while (i < *(u32*)((char*)self + 0x150)) {
                    grYakumono* entry = *(grYakumono**)((char*)*(grYakumono*** )((char*)self + 0x154) + offset);
                    entry->setTransparency(0, *(u32*)((char*)self + 0xE4));
                    offset += 4;
                    i++;
                }
                self->setSleepHit(true);
                self->setTransparencyFlag(0);
            }
        } else {
            if (self->getTransparencyFlag() == 0) {
                u32 i = 0;
                int offset = 0;
                while (i < *(u32*)((char*)self + 0x150)) {
                    grYakumono* entry = *(grYakumono**)((char*)*(grYakumono*** )((char*)self + 0x154) + offset);
                    entry->setTransparency(1, *(u32*)((char*)self + 0xE4));
                    offset += 4;
                    i++;
                }
                self->setSleepHit(false);
                self->setTransparencyFlag(1);
            }
        }
    }
}