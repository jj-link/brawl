#include <so/so_module_accesser.h>
#include <memory.h>

struct LuigiWallProcess { void* vtable; };
struct LuigiWallTypeInfo { const char* name; const void* bases; };
struct LuigiWallBaseInfo { const void* type; int adjustment; const void* end; };
struct LuigiWallRegistration { void* next; void* object; void* destructor; };
struct LuigiWallRttiBase { const void* type; int adjustment; };
struct LuigiWallGroundBases { LuigiWallRttiBase bases[4]; const void* end; };
typedef void (*LuigiWallMethod)();
struct LuigiWallVtable { const LuigiWallTypeInfo* type; unsigned long reserved; LuigiWallMethod methods[14]; };

struct LuigiWallNormal { float m_x, m_y; };
struct LuigiWallEnableByte { unsigned char enabled : 1; };
// The attach-normal slot returns two raw words. Preserve its virtual order
// without invoking the shared owning-vector copy constructor.
class LuigiWallGroundModuleView : public soNull, public soNullable {
public:
    virtual ~LuigiWallGroundModuleView();
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
    virtual LuigiWallNormal getAttachNormal(u32 index);
};

extern "C" {
extern const char lbl_99_data_171C[], lbl_99_data_1734[], lbl_99_data_19AC[], lbl_99_data_22F8[];
extern const char lbl_99_data_6434[];
extern LuigiWallTypeInfo lbl_99_data_64FC, lbl_99_data_6578;
extern LuigiWallVtable lbl_99_data_6504;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_19397C(soModuleAccesser*, float, float, float, int);
void fn_27_B7548(soKineticEnergy*, const Vec2f*);
LuigiWallProcess* fn_99_D418(LuigiWallProcess*);
}

extern "C" void fn_99_D184(LuigiWallProcess*, soModuleAccesser* accesser) {
    accesser->getGroundModule().update(1);
    soMotionChangeParam motion;
    motion.m_kind = 0x1d5;
    motion.m_frame = 0.0f;
    motion.m_rate = 1.0f;
    motion._12 = 0;
    motion._13 = 0;
    motion._14 = 0;
    motion._15 = 0;
    accesser->getMotionModule().changeMotionRequest(&motion);
    float lr = accesser->getPostureModule().getLr();
    if (lr == -1.0f) accesser->getGroundModule().attach(grCollStatus::TOUCH_MASK_LEFT, 0);
    else accesser->getGroundModule().attach(grCollStatus::TOUCH_MASK_RIGHT, 0);
    fn_27_19397C(accesser, lr, -lr, -1.0f, 1);
    fn_27_19397C(accesser, lr, static_cast<float>(lr == -1.0f), 1.0f, 0);
    soKineticEnergy* groundEnergy = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(6), 0, &lbl_99_data_64FC, lbl_99_data_171C, 1));
    Vec2f normal;
    LuigiWallNormal attachedNormal = reinterpret_cast<LuigiWallGroundModuleView*>(&accesser->getGroundModule())->getAttachNormal(0);
    __memcpy(&normal, &attachedNormal, sizeof(normal));
    fn_27_B7548(groundEnergy, &normal);
    soKineticEnergy* motionEnergy = accesser->getKineticModule().getEnergy(5);
    reinterpret_cast<LuigiWallEnableByte*>(reinterpret_cast<unsigned char*>(motionEnergy) + 5)->enabled = 0;
}

extern "C" LuigiWallProcess* fn_99_D390(LuigiWallProcess* process, short deleting) {
    if (process && deleting > 0) operator delete(process);
    return process;
}
extern "C" {
LuigiWallRegistration lbl_99_bss_1E0;
LuigiWallProcess lbl_99_bss_1EC;
}
extern "C" void fn_99_D3D0() {
    fn_99_D418(&lbl_99_bss_1EC);
    __register_global_object(&lbl_99_bss_1EC, reinterpret_cast<void*>(fn_99_D390), &lbl_99_bss_1E0);
}
#pragma dont_inline on
extern "C" LuigiWallProcess* fn_99_D418(LuigiWallProcess* process) {
    process->vtable = &lbl_99_data_6504;
    return process;
}
#pragma dont_inline reset

extern "C" {
void fn_99_CD78(); void fn_99_CDBC(); void fn_99_CD74(); void fn_99_CD70();
void fn_99_CD6C(); void fn_99_CD68(); void fn_99_CD64(); void fn_99_CD5C();
void fn_99_CD58(); void fn_99_CD50(); void fn_99_CD4C(); void fn_99_CD44();
char lbl_99_data_64B8[] = "soKineticEnergyGroundMovement";
LuigiWallGroundBases lbl_99_data_64D8 = { {
    { lbl_99_data_1734, 6 }, { lbl_99_data_19AC, 5 },
    { lbl_99_data_22F8, 0 }, { lbl_99_data_171C, 0 } }, 0 };
LuigiWallTypeInfo lbl_99_data_64FC = { lbl_99_data_64B8, &lbl_99_data_64D8 };
LuigiWallVtable lbl_99_data_6504 = { &lbl_99_data_6578, 0, {
    reinterpret_cast<LuigiWallMethod>(fn_99_D390), reinterpret_cast<LuigiWallMethod>(fn_99_D184),
    fn_99_CD78, fn_99_CDBC, fn_99_CD74, fn_99_CD70, fn_99_CD6C, fn_99_CD68,
    fn_99_CD64, fn_99_CD5C, fn_99_CD58, fn_99_CD50, fn_99_CD4C, fn_99_CD44 }};
char lbl_99_data_6544[] = "ftLuigiStatusUniqProcessSpecialSWall";
LuigiWallBaseInfo lbl_99_data_656C = { lbl_99_data_6434, 0, 0 };
LuigiWallTypeInfo lbl_99_data_6578 = { lbl_99_data_6544, &lbl_99_data_656C };
}
__declspec(section ".ctors") extern void (*const luigiWallInitializer)() = fn_99_D3D0;
