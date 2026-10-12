#include <so/so_module_accesser.h>
#include <wn/weapon.h>
#include <ft/ft_common_data_accesser.h>
#include <math.h>

extern "C" {
extern const char lbl_98_data_7F08[], lbl_98_data_2F88[];
extern const float lbl_98_rodata_C0[2] = {0.0f, 0.0f};
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_98_1448C();
void fn_98_14A18(StageObject*, float);
void* fn_98_14750(StageObject*);
void fn_98_18494(void*, Vec3f*);
}
struct FinalMovementData { float speed, duration; };
struct FinalDataView { char prefix[0x88]; FinalMovementData* movement; };

// Advance Thunder's vertical position and align its active article to ground.
extern "C" void fn_98_1525C(void*, soModuleAccesser* accesser) {
    bool finished = false;
    StageObject* thunder = static_cast<StageObject*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_7F08, lbl_98_data_2F88, 1));
    soGroundModule& ground = accesser->getGroundModule();
    soPostureModule& posture = accesser->getPostureModule();
    soWorkManageModule& work = accesser->getWorkManageModule();
    float direction = work.getFloat(0x11000004);
    float delay = fn_98_1448C();
    if (work.isFlag(0x12000004) && !work.isFlag(0x12000003) &&
        ((direction >= lbl_98_rodata_C0[0] && ground.isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) ||
         (direction < lbl_98_rodata_C0[0] && ground.isTouch(static_cast<grCollStatus::TouchMask>(1), 0)))) {
        Vec2f touch;
        if (direction >= lbl_98_rodata_C0[0])
            touch = ground.getTouchPos(static_cast<grCollStatus::TouchMask>(8), 0);
        else
            touch = ground.getTouchPos(static_cast<grCollStatus::TouchMask>(1), 0);
        fn_98_14A18(thunder, touch.m_y);
        ground.setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(0), 0);
        void* article = fn_98_14750(thunder);
        if (article) {
            Vec3f pos(touch.m_x, touch.m_y, ground.getZ());
            fn_98_18494(article, &pos);
        }
    }
    bool constrained = work.isFlag(0x12000003);
    float boundary = work.getFloat(0x11000003);
    float position = work.getFloat(0x11000001);
    float endPosition = work.getFloat(0x11000002);
    float speed = accesser->getKineticModule().getSumSpeed(
        soKineticEnergy::AttributeFlag(soKineticEnergy::AttributeFlag::AllAttributes)).m_y;
    position += speed;
    if (constrained) {
        if (direction >= lbl_98_rodata_C0[0] && position < boundary) position = boundary;
        else if (direction < lbl_98_rodata_C0[0] && position > boundary) position = boundary;
    }
    float distance = work.getFloat(0x11000005) + static_cast<float>(fabs(speed));
    work.setFloat(distance, 0x11000005);
    if (distance >= delay) endPosition += speed;
    if (constrained) {
        if (direction >= lbl_98_rodata_C0[0]) {
            if (position < boundary) position = boundary;
            if (endPosition < boundary) endPosition = boundary;
            if (!(position < endPosition)) finished = true;
        } else {
            if (position > boundary) position = boundary;
            if (endPosition > boundary) endPosition = boundary;
            if (!(position > endPosition)) finished = true;
        }
    }
    work.setFloat(position, 0x11000001);
    work.setFloat(endPosition, 0x11000002);
    Vec3f pos = posture.getPos();
    pos.m_y = position;
    posture.setPos(&pos);
    if (!work.isFlag(0x12000004)) {
        const FinalMovementData* movement = reinterpret_cast<const FinalDataView*>(
            g_ftCommonDataAccesser.getData(static_cast<ftKind>(7)))->movement;
        if (distance >= static_cast<float>(fabs(movement->speed * movement->duration))) {
            work.onFlag(0x12000004);
            ground.setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
        }
    }
    if (finished) static_cast<Weapon*>(thunder)->deactivate(false);
}
