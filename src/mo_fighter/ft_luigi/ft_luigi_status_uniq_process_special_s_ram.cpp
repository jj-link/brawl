#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_prng.h>
#include <math.h>

struct LuigiRamProcess { void* vtable; };
struct LuigiRamTypeInfo { const char* name; const void* bases; };
struct LuigiRamBaseInfo { const void* type; int adjustment; const void* end; };
struct LuigiRamRegistration { void* next; void* object; void* destructor; };
typedef void (*LuigiRamMethod)();
struct LuigiRamVtable { const LuigiRamTypeInfo* type; unsigned long reserved; LuigiRamMethod methods[14]; };

// As in the other fighter status units, the kinetic mask is passed by
// address. The three-component entry writes its result to caller storage.
class LuigiRamKineticModuleView : public soNullable {
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
    virtual Vec3f getSumSpeed3f(const short&);
};

// The original ground slots pass the full-width touch mask unchanged.
// Preserve the shared virtual order while keeping those ABI corrections local.
class LuigiRamGroundModuleView : public soNull, public soNullable {
public:
    virtual ~LuigiRamGroundModuleView();
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
    virtual Vec2f getTouchNormal(grCollStatus::TouchMask, u32 index);
    virtual Vec2f getTouchSpeed(grCollStatus::TouchMask, u32 index);
    virtual Vec2f getAttachMovementSpeed(u32 index);
    virtual Vec2f getAttachNormal(u32 index);
    virtual unsigned long getTouchFlag(u32 index);
    virtual grCollisionLine::MaterialType getTouchMaterialType(grCollStatus::TouchMask, u32 index);
    virtual Vec2f getTouchPos(grCollStatus::TouchMask, u32 index);
    virtual bool getTouchAttackData(soCollisionAttackData* outAttackData, int* out2, int* out3, u32 index);
    virtual float getTouchLength(grCollStatus::TouchMask, u32 index);
    virtual float getTouchLineRate(grCollStatus::TouchMask, u32 index);
    virtual bool getTouchNextNormal(bool getNext, Vec2f* outNormal, grCollStatus::TouchMask, u32 index);
    virtual void ignoreTouchLine(grCollStatus::TouchMask, u32 index);
    virtual bool isDiveDown(u32 index);
    virtual bool isCrush(float, u32 index);
    virtual bool isOnDynamicCollision(u32 index);
    virtual u32 getDownLineId(u32 index);
    virtual u32 getRightLineId(u32 index);
    virtual u32 getLeftLineId(u32 index);
    virtual u32 getUpLineId(u32 index);
    virtual u32 getDownLeftLineId(u32 index);
    virtual u32 getDownRightLineId(u32 index);
    virtual u32 getUpLeftLineId(u32 index);
    virtual u32 getUpRightLineId(u32 index);
    virtual u32 getCliffId(u32 index);
    virtual bool isSameJoint(int*, int*);
    virtual Vec2f getUpPos(u32 index);
    virtual Vec2f getDownPos(u32 index);
    virtual Vec2f getLeftPos(u32 index);
    virtual Vec2f getRightPos(u32 index);
    virtual Vec2f getCenterPos(u32 index);
    virtual float getWidth(u32 index);
    virtual Vec2f getDownMovementSpeed(u32 index);
    virtual bool getDownCorrectPos(Vec3f*, Vec3f*, u32 index);
    virtual float getDownFriction(u32 index);
    virtual bool isCliffOver(u8, u32 index);
    virtual bool isCliffOverPos(Vec2f* pos, u8, u32 index);
    virtual void initRhombus(u32 index);
    virtual void modifyRhombus(float newRhombusUp, float newRhombusDown, float newRhombusWidth, u32 index);
    virtual void modifyRhombusUp(float newRhombusUp, u32 index);
    virtual void modifyRhombusDown(float newRhombusDown, u32 index);
    virtual void modifyRhombusWidth(float newRhombusWidth, u32 index);
    virtual void modifyRhombusFollowNode(float newRhombusUp, float newRhombusDown, float newRhombusWidth, int newRhombusFollowNode, u32 index);
    virtual void getRhombus(float* outRhombusUp, float* outRhombusDown, float* outRhombusWidth, u32 index);
    virtual void getRhombus(float* outRhombusUp, float* outRhombusDown, float* outRhombusWidth, int* outRhombusFollowNode, u32 index);
    virtual void getRhombus(clRhombus2D* outPrevCollShape, clRhombus2D* outCurrentCollShape, u32 index);
    virtual void calcRhombusModify(float* out1, float* out2, float* out3, float* out4, u32 index);
    virtual void setOffsetX(float offsetX, u32 index);
    virtual void setOffsetY(float offsetY, u32 index);
    virtual void setShapeFlag(soGroundShapeImpl::ShapeFlagId flag, bool setFlag, u32 index);
    virtual bool checkShapeFlag(soGroundShapeImpl::ShapeFlagId flag, u32 index);
    virtual void setShapeSafePos(Vec2f* safePos, u32 index);
    virtual void setShapeKind(soGroundShapeImpl::ShapeKind shapeKind, u32 index);
    virtual bool isPassableGround(u32 index);
    virtual void setZ(float Z);
    virtual float getZ();
    virtual bool attachGround(u32 index);
    virtual bool isAttachable(unsigned long, u32 index);
};

extern "C" {
extern const float lbl_99_rodata_30, lbl_99_rodata_34;
extern const char lbl_99_data_6434[];
extern LuigiRamVtable lbl_99_data_6440;
extern LuigiRamTypeInfo lbl_99_data_64B0;
void __register_global_object(void*, void*, void*);
LuigiRamProcess* fn_99_D174(LuigiRamProcess*);
}

extern "C" void fn_99_CE18(LuigiRamProcess*, soModuleAccesser* accesser) {
    accesser->getGroundModule().setTestCollStopStatus(true, 0);
}

extern "C" void fn_99_CE38(LuigiRamProcess*, soModuleAccesser* accesser) {
    unsigned long touch;
    int status;
    {
        soGroundModule& ground = accesser->getGroundModule();
        touch = reinterpret_cast<LuigiRamGroundModuleView*>(&ground)->getTouchFlag(0);
    }
    if (touch & (grCollStatus::TOUCH_MASK_LEFT | grCollStatus::TOUCH_MASK_RIGHT)) {
        short attributes = -1;
        Vec3f speed = reinterpret_cast<LuigiRamKineticModuleView*>(&accesser->getKineticModule())->getSumSpeed3f(attributes);
        status = 0x119;
        soGroundModule& ground = accesser->getGroundModule();
        if (reinterpret_cast<LuigiRamGroundModuleView*>(&ground)->isAttachable(touch, 0) == true) {
            double absoluteSpeed = fabs(speed.m_x);
            float horizontalSpeed = absoluteSpeed;
            if (horizontalSpeed >= soValueAccesser::getConstantFloat(accesser, 0xfbb, 0)) {
                float probability = soValueAccesser::getConstantFloat(accesser, 0xfbc, 0);
                if (randf() < probability) {
                    if (touch & grCollStatus::TOUCH_MASK_LEFT) {
                        if (accesser->getPostureModule().getLr() == lbl_99_rodata_30) status = 0x11a;
                    } else {
                        if (accesser->getPostureModule().getLr() == lbl_99_rodata_34) status = 0x11a;
                    }
                }
            }
        }
        accesser->getStatusModule().changeStatusRequest(status, accesser);
    } else if (!accesser->getWorkManageModule().isFlag(0x22000012)
            && !accesser->getWorkManageModule().isFlag(0x22000015)
            && accesser->getCollisionAttackModule().isAttack(0, false) == true) {
        soWorkManageModule& work = accesser->getWorkManageModule();
        float multiplier = soValueAccesser::getConstantFloat(accesser, 0xfac, 0);
        float hitCount = work.getInt(0x20000000);
        float power = hitCount * multiplier;
        float basePower = soValueAccesser::getConstantFloat(accesser, 0xfab, 0);
        float newPower = basePower + power;
        accesser->getCollisionAttackModule().setPower(0, static_cast<int>(newPower), false);
        accesser->getWorkManageModule().onFlag(0x22000015);
    }
}

extern "C" LuigiRamProcess* fn_99_D0EC(LuigiRamProcess* process, short deleting) {
    if (process && deleting > 0) operator delete(process);
    return process;
}

extern "C" {
LuigiRamRegistration lbl_99_bss_1D0;
LuigiRamProcess lbl_99_bss_1DC;
}
extern "C" void fn_99_D12C() {
    fn_99_D174(&lbl_99_bss_1DC);
    __register_global_object(&lbl_99_bss_1DC, reinterpret_cast<void*>(fn_99_D0EC), &lbl_99_bss_1D0);
}
#pragma dont_inline on
extern "C" LuigiRamProcess* fn_99_D174(LuigiRamProcess* process) {
    process->vtable = &lbl_99_data_6440;
    return process;
}
#pragma dont_inline reset

extern "C" {
void fn_99_CD78(); void fn_99_CDBC(); void fn_99_CD74(); void fn_99_CD70();
void fn_99_CD6C(); void fn_99_CD64(); void fn_99_CD5C(); void fn_99_CD58();
void fn_99_CD50(); void fn_99_CD4C(); void fn_99_CD44();
LuigiRamVtable lbl_99_data_6440 = { &lbl_99_data_64B0, 0, {
    reinterpret_cast<LuigiRamMethod>(fn_99_D0EC), reinterpret_cast<LuigiRamMethod>(fn_99_CE18),
    fn_99_CD78, fn_99_CDBC, fn_99_CD74, fn_99_CD70, fn_99_CD6C,
    reinterpret_cast<LuigiRamMethod>(fn_99_CE38), fn_99_CD64, fn_99_CD5C,
    fn_99_CD58, fn_99_CD50, fn_99_CD4C, fn_99_CD44 }};
char lbl_99_data_6480[] = "ftLuigiStatusUniqProcessSpecialSRam";
LuigiRamBaseInfo lbl_99_data_64A4 = { lbl_99_data_6434, 0, 0 };
LuigiRamTypeInfo lbl_99_data_64B0 = { lbl_99_data_6480, &lbl_99_data_64A4 };
}
__declspec(section ".ctors") extern void (*const luigiRamInitializer)() = fn_99_D12C;
