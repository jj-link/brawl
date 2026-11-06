#include <nw4r/math/math_arithmetic.h>
#include <cm/cm_camera_controller.h>
#include <gm/gm_global.h>
#pragma force_active on
extern "C" float fn_8004E94C(GameGlobal*);
extern "C" void fn_8009CEA8(CameraController*, cmStageParam*);
extern "C" void fn_8009D014(CameraController*, cmStageParam*);
extern int lbl_805A0368;
extern const float lbl_27_rodata_33D8;
extern const float lbl_27_rodata_33D0;
inline float clampValue(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate(); virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera(); virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd(); virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init(); virtual ~Stage(); virtual void createObj(); virtual void createObjPokeTrainer(); virtual void getPokeTrainerPointNum(); virtual void getPokeTrainerPointData(); virtual void getPokeTrainerPositionZ(); virtual void getPokeTrainerDrawLayer(); virtual void isAdventureStage(); virtual void getItemPac(); virtual void getItemGenPac(); virtual void getItemPacEnemyFigure(); virtual void getEnemyPac(); virtual void getAdvRadarData(); virtual void initializeStage(); virtual void closeStage(); virtual void renderDebugPositions(); virtual void loading(); virtual void process(); virtual void updateStagePositions();
char pad40[0x38]; cmStageParam* param; char pad7c[0x14]; int enabled; char pad94[0x34]; float c8,cc,d0,d4,d8,dc,e0,e4; unsigned char e8;
};
void Stage::processAnim() {
lbl_805A0368=0;
if (lbl_27_rodata_33D8 != d4) {
d0 += fn_8004E94C(g_GameGlobal);
float ratio = d0 / d4;
float v = clampValue(ratio, lbl_27_rodata_33D8, lbl_27_rodata_33D0);
g_GameGlobal->m_stageData->m_motionRatio = c8 + v*(cc-c8);
if (lbl_27_rodata_33D0 == v) { c8=lbl_27_rodata_33D8; cc=lbl_27_rodata_33D8; d0=lbl_27_rodata_33D8; d4=lbl_27_rodata_33D8; }
}
if (lbl_27_rodata_33D8 != e4) {
e0 += fn_8004E94C(g_GameGlobal);
float ratio = e0 / e4;
float v = clampValue(ratio, lbl_27_rodata_33D8, lbl_27_rodata_33D0);
g_GameGlobal->m_stageData->m_motionSubRatio = d8 + v*(dc-d8);
if (lbl_27_rodata_33D0 == v) { d8=lbl_27_rodata_33D8; dc=lbl_27_rodata_33D8; e0=lbl_27_rodata_33D8; e4=lbl_27_rodata_33D8; }
}
if(e8==1) updateStagePositions();
if(enabled) {
cmStageParam tmp;
cmStageParam* p=param;
tmp.m_range.m_left=p->m_range.m_left; tmp.m_range.m_right=p->m_range.m_right; tmp.m_range.m_up=p->m_range.m_up; tmp.m_range.m_down=p->m_range.m_down;
tmp.m_verticalRotationFactor=param->m_verticalRotationFactor; tmp.m_horizontalRotationFactor=param->m_horizontalRotationFactor;
tmp.m_maxZ=param->m_minZ; tmp.m_minZ=param->m_maxZ;
p=param;
tmp.m_centerPos.m_x=p->m_centerPos.m_x; tmp.m_centerPos.m_y=p->m_centerPos.m_y; tmp.m_centerPos.m_z=p->m_centerPos.m_z;
tmp.m_fighterBubbleBufferMultiplier=param->m_fighterBubbleBufferMultiplier; tmp.m_48=param->m_48; tmp.m_speed=param->m_speed; tmp.m_tiltThreshold=param->m_tiltThreshold; tmp.m_fov=param->m_fov;
fn_8009CEA8(CameraController::getInstance(),param);
fn_8009D014(CameraController::getInstance(),&tmp);
}
}