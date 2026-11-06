#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

class Class_7FC8 {
public:
    virtual void fn_104_7930();
    virtual void fn_104_12090();
    virtual void fn_104_12990();
    virtual void fn_104_12988();
    virtual void fn_104_12980();
    virtual void fn_104_12978();
    virtual void fn_104_12970();
    virtual void fn_104_12968();
    virtual void fn_104_12960();
    virtual void fn_104_12958();
    virtual void fn_104_12950();
    virtual void fn_104_12948();
    virtual void fn_104_12940();
    virtual void fn_104_12938();
    virtual void fn_104_128E8();
    virtual void fn_104_12930();
    virtual void fn_104_12920();
    virtual void fn_104_12910();
    virtual void fn_104_12900(unsigned int);
};
class ZeldaKineticView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, soKineticEnergy::AttributeFlag);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual Vec2f getSumSpeed(const short&);
};
class ZeldaGroundView : public soNull, public soNullable {

public:
    virtual ~ZeldaGroundView();
    virtual void setup(void*, int taskId, bool);
    virtual void clean();
    virtual void constructGrCollision(int, int, Heaps::HeapType, u8, u8, u8);
    virtual void activate(int taskId, Vec2f*);
    virtual void deactivate();
    virtual void relocate(Vec2f*, u32 index);
    virtual void begin();
    virtual void update(u32);
    virtual void processFixPosition();
    virtual float getRotateYForGrCollisionMatrix();
    virtual void updateCheckGrCollision();
    virtual void updateGrCollisionMatrix();
    virtual void pause(bool);
    virtual void apply();
    virtual bool isReferenceModelNode();
    virtual void setCorrect(soGroundShapeImpl::CorrectKind correct, u32 index);
    virtual soGroundShapeImpl::CorrectKind getCorrect(u32 index);
    virtual void setCalcLineMove(bool calcLineMove, u32 index);
    virtual void setTargetLineCategory(grCollisionLine::CategoryMask targetLineCategory, u32 index);
    virtual void setExclusiveLineAttr(short exclusiveLineAttr, u32 index);
    virtual void setPassableCheck(bool passableCheck, u32 index);
    virtual bool isPassableCheck(u32 index);
    virtual void setCloudThrough(bool cloudThrough, u32 index);
    virtual bool isCloudThrough(u32 index);
    virtual bool isCloudThroughOut(Vec2f* out, u32 index);
    virtual void setCorrectIgnoreSlope(u8 correctIgnoreSlope, u32 index);
    virtual void setCliffCheck(soGroundShapeImpl::CliffCheckKind, u32 index);
    virtual void setCliffHangData(void*);
    virtual void selectCliffHangData(u32 i, u32 index);
    virtual void setCliffBackRangeXMul(float cliffBackRangeXMul);
    virtual bool isStCliff(u32 index);
    virtual Vec3f getCorrectPos(u32 index);
    virtual void setCliffTeam(u8 cliffTeam, u32 index);
    virtual void entryCliff(u32 index);
    virtual void leaveCliff(u32 index);
    virtual Vec3f getCliffPos(u32 index);
    virtual float getCliffDir(u32 index);
    virtual void setStGroundForce(u32 index);
    virtual void setTestCollStop(bool testCollStop, u32 index);
    virtual void setTestCollStopStatus(bool testCollStop, u32 index);
    virtual void setTestPreMap(bool testPreMap, u32 index);
    virtual void setTestPreMapStatus(bool testPreMap, u32 index);
    virtual void setTestDynamicCollisionStatus(bool testDynamicCollision, u32 index);
    virtual void setTestDynamicCollision(bool testDynamicCollision, u32 index);
    virtual void setEventToGround(bool eventToGround, u32 index);
    virtual void setEventToGroundStatus(bool eventToGround, u32 index);
    virtual grCollStatus* getCollStatus(u32 index);
    virtual bool isOttotto(float, u32 index);
    virtual bool isNearCliff(float, float, u32 index);
    virtual bool isMissStepR(u32 index);
    virtual bool isMissStepL(u32 index);
    virtual bool isTouch(grCollStatus::TouchMask, u32 index);
    virtual u8 getTouchCount(u32 index);
    virtual Vec2f getTouchNormal(int, u32 index);
};
struct ZeldaParams {
    char pad[0x28];
    int angle;
};
struct ZeldaData {
    char pad[0x84];
    ZeldaParams* params;
};
extern "C" float fn_8003DDD0(const Vec2f*, const Vec2f*);
extern const float lbl_104_rodata_3C;
extern const float lbl_104_rodata_40;

extern "C" void fn_104_E748(void*, soModuleAccesser* accesser) {
    Class_7FC8* work = reinterpret_cast<Class_7FC8*>(accesser->m_enumerationStart->m_workManageModule);
    soSituationModule* situation = accesser->m_enumerationStart->m_situationModule;
    soGroundModule* ground = accesser->m_enumerationStart->m_groundModule;
    ZeldaParams* params = reinterpret_cast<ZeldaData*>(g_ftCommonDataAccesser.getData((ftKind)13))->params;
    if (situation->getKind() != 0) {
        int touch = 0;
        if (ground->isTouch((grCollStatus::TouchMask)1, 0)) touch = 1;
        if (ground->isTouch((grCollStatus::TouchMask)4, 0)) touch = 4;
        if (ground->isTouch((grCollStatus::TouchMask)2, 0)) touch = 2;
        if (touch != 0) {
            short mask = -1;
            Vec2f speed;
            Vec2f::copy(speed, reinterpret_cast<ZeldaKineticView*>(&accesser->getKineticModule())->getSumSpeed(mask));
            Vec2f normal;
            Vec2f::copy(normal, reinterpret_cast<ZeldaGroundView*>(ground)->getTouchNormal(touch, 0));
            if (fn_8003DDD0(&speed, &normal) > lbl_104_rodata_3C * (lbl_104_rodata_40 + (float)params->angle)) {
                work->fn_104_12900(0x22000012);
            }
        }
    }
}
