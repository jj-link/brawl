#pragma once

#include <so/ground/so_ground_module_impl.h>

// Declaration-only ABI view of soGroundModule through getTouchNormal. The
// original speed getter returns a trivial two-word aggregate rather than the
// nontrivial Vec2f class, so its result is carried in r3/r4.
struct DededeSpeed { float x, y; };
class DededeGroundSpeedView : public soNull, public soNullable {
public:
    virtual ~DededeGroundSpeedView();
    virtual void setup(void*, int, bool);
    virtual void clean();
    virtual void constructGrCollision(int, int, Heaps::HeapType, u8, u8, u8);
    virtual void activate(int, Vec2f*);
    virtual void deactivate();
    virtual void relocate(Vec2f*, u32);
    virtual void begin();
    virtual void update(u32);
    virtual void processFixPosition();
    virtual float getRotateYForGrCollisionMatrix();
    virtual void updateCheckGrCollision();
    virtual void updateGrCollisionMatrix();
    virtual void pause(bool);
    virtual void apply();
    virtual bool isReferenceModelNode();
    virtual void setCorrect(soGroundShapeImpl::CorrectKind, u32);
    virtual soGroundShapeImpl::CorrectKind getCorrect(u32);
    virtual void setCalcLineMove(bool, u32);
    virtual void setTargetLineCategory(grCollisionLine::CategoryMask, u32);
    virtual void setExclusiveLineAttr(short, u32);
    virtual void setPassableCheck(bool, u32);
    virtual bool isPassableCheck(u32);
    virtual void setCloudThrough(bool, u32);
    virtual bool isCloudThrough(u32);
    virtual bool isCloudThroughOut(Vec2f*, u32);
    virtual void setCorrectIgnoreSlope(u8, u32);
    virtual void setCliffCheck(soGroundShapeImpl::CliffCheckKind, u32);
    virtual void setCliffHangData(void*);
    virtual void selectCliffHangData(u32, u32);
    virtual void setCliffBackRangeXMul(float);
    virtual bool isStCliff(u32);
    virtual Vec3f getCorrectPos(u32);
    virtual void setCliffTeam(u8, u32);
    virtual void entryCliff(u32);
    virtual void leaveCliff(u32);
    virtual Vec3f getCliffPos(u32);
    virtual float getCliffDir(u32);
    virtual void setStGroundForce(u32);
    virtual void setTestCollStop(bool, u32);
    virtual void setTestCollStopStatus(bool, u32);
    virtual void setTestPreMap(bool, u32);
    virtual void setTestPreMapStatus(bool, u32);
    virtual void setTestDynamicCollisionStatus(bool, u32);
    virtual void setTestDynamicCollision(bool, u32);
    virtual void setEventToGround(bool, u32);
    virtual void setEventToGroundStatus(bool, u32);
    virtual grCollStatus* getCollStatus(u32);
    virtual bool isOttotto(float, u32);
    virtual bool isNearCliff(float, float, u32);
    virtual bool isMissStepR(u32);
    virtual bool isMissStepL(u32);
    virtual bool isTouch(grCollStatus::TouchMask, u32);
    virtual u8 getTouchCount(u32);
    virtual DededeSpeed getTouchNormal(grCollStatus::TouchMask, u32);
};
