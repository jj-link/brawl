#include <so/so_module_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>
#pragma force_active on

#pragma optimization_level 2
#pragma scheduling off

class SpeedEnergy : public soNullable, public soEnable, public soSuspendable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual DededeSpeed getSpeed();
};

inline void copySpeed(Vec2f& dst, const DededeSpeed& src) {
    Vec2f::copy(dst, *reinterpret_cast<const Vec2f*>(&src));
}

extern "C" {
extern const char lbl_118_data_620C[];
extern const char lbl_118_data_6708[];
extern const char lbl_118_data_17B0[];
extern const float lbl_118_rodata_30[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_118_C3EC(void*, const Vec2f*);
float fn_118_EDC4(Vec2f*);
float fn_118_EE38(Vec2f*, Vec2f*);
void fn_8003DBA8(Vec2f*);
bool fn_118_F2D8(int, int, float, soModuleAccesser*);
void fn_118_FF04(soModuleAccesser*, float, float);
}

inline int requestStatus(soModuleAccesser* accesser, soWorkManageModule& work) {
    int status = work.getInt(0x20000001);
    accesser->getStatusModule().changeStatusRequest(status, accesser);
    return status;
}

extern "C" void fn_118_E934(void*, soModuleAccesser* accesser) {
    const float* c = lbl_118_rodata_30;
    soGroundModule* ground = &accesser->getGroundModule();
    soKineticModule& kinetic = accesser->getKineticModule();

    int status;
    if (accesser->getMotionModule().isEnd()) {
        soWorkManageModule& work = accesser->getWorkManageModule();
        work.onFlag(0x22000014);
        status = 0x11c;
        work.setInt(status, 0x20000001);
    }

    if (ground->isTouch((grCollStatus::TouchMask)8, 0)) {
        ground->setCorrect((soGroundShapeImpl::CorrectKind)1, 0);
        kinetic.changeKinetic(13, accesser);
    } else {
        ground->setCorrect((soGroundShapeImpl::CorrectKind)5, 0);
        kinetic.changeKinetic(13, accesser);
    }

    char* energy = static_cast<char*>(__dynamic_cast(
        kinetic.getEnergy(3), 0, lbl_118_data_620C, lbl_118_data_17B0, 1));

    Vec2f speed;
    Vec2f normal;
    Vec2f a(c[8], c[8]);
    fn_118_C3EC(energy + 0x28, &a);

    Vec2f b(c[8], c[8]);
    fn_118_C3EC(energy + 0x18, &b);

    float* energy2 = static_cast<float*>(__dynamic_cast(
        kinetic.getEnergy(1), 0, lbl_118_data_6708, lbl_118_data_17B0, 1));
    energy2[7] = c[8];
    energy2[5] = c[8];

    if (!accesser->getSituationModule().getKind() &&
        ground->isTouch((grCollStatus::TouchMask)8, 0)) {
        SpeedEnergy* e = static_cast<SpeedEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0,
            lbl_118_data_620C, lbl_118_data_17B0, 1));

        copySpeed(speed, e->getSpeed());

        if (fn_118_EDC4(&speed) > c[9]) {
            copySpeed(
                normal,
                reinterpret_cast<DededeGroundSpeedView*>(ground)->getTouchNormal(
                    (grCollStatus::TouchMask)8, 0));
            fn_8003DBA8(&normal);

            if (fn_118_EE38(&normal, &speed) > c[9]) {
                accesser->getSituationModule().setKind((SituationKind)2, false);
            }
        }
    }

    if (ground->isStCliff(0)) {
        soWorkManageModule& work = accesser->getWorkManageModule();
        work.onFlag(0x22000014);
        work.setInt(0x73, 0x20000001);
    } else if (!fn_118_F2D8(8, 0, c[0], accesser) &&
               !fn_118_F2D8(2, 1, c[3], accesser) &&
               !fn_118_F2D8(4, 1, c[2], accesser)) {
        fn_118_F2D8(1, 0, c[0], accesser);
    }

    soWorkManageModule& work = accesser->getWorkManageModule();
    if (work.isFlag(0x22000014)) {
        status = requestStatus(accesser, work);

        if (status == 0x11d) {
            float x = c[3];
            float y = c[0];
            fn_118_FF04(accesser, x, y);
        }

        soWorkManageModule& work2 = accesser->getWorkManageModule();
        work2.offFlag(0x22000014);
        work2.setInt(-1, 0x20000001);
    }
}
