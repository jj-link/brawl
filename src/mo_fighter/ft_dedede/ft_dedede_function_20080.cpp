#include <types.h>
#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>
#pragma force_active on

#pragma pool_data on
#pragma pool_fp_consts on

struct DededeCaptureSoundModule {
    virtual ~DededeCaptureSoundModule();
    virtual void update(Vec3f*);
    virtual void deactivate();
    virtual void activate(Vec3f*);
    virtual void setPos(Vec3f*, int);
    virtual int playSE(SndID, bool, bool, int);
};

class Command {
public:
    virtual void slot08();
    virtual s8 group();
    virtual s8 kind();
};

class Energy : public soNullable, public soEnable, public soSuspendable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual DededeSpeed getSpeed();

    Vec2f speed;
};

class Weapon : public StageObject {
public:
    unsigned char pad[0x2648 - 0x64];
    unsigned char* params;
    float* variant;
};

extern "C" {
int fn_27_1DA24C(void*, void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern const char lbl_117_data_83EC[];
extern const char lbl_117_data_A684[];
extern const char lbl_117_data_36A8[];

DededeSpeed fn_117_2053C(const DededeSpeed*, float);
}

static inline void copySpeed(Vec2f& dst, const DededeSpeed& src) {
    Vec2f::copy(dst, *reinterpret_cast<const Vec2f*>(&src));
}

static inline const DededeSpeed* words(const Vec2f& v) {
    return reinterpret_cast<const DededeSpeed*>(&v);
}

extern "C" int fn_117_20080(Weapon* self, Command* cmd, soModuleAccesser* accesser) {
    float one = 1.0f;
    float negativeOne = -1.0f;
    float zero = 0.0f;
    float angle = 20.0f;
    float two = 2.0f;
    s32 sign;
    float signFloatOld;

    if (fn_27_1DA24C(self, cmd, accesser))
        return 1;

    s8 group = cmd->group();
    if (!self->isObserv(group))
        return 0;

    if (cmd->kind() <= -1 || cmd->kind() >= 11)
        return 0;

    switch (cmd->kind()) {
    case 6:
        if (self->m_moduleAccesser->getWorkManageModule().getInt(0x20000004) == 2) {
            Energy* horizontal = static_cast<Energy*>(__dynamic_cast(
                accesser->getKineticModule().getEnergy(0), 0,
                lbl_117_data_83EC, lbl_117_data_36A8, 1));

            Energy* vertical = static_cast<Energy*>(__dynamic_cast(
                accesser->getKineticModule().getEnergy(1), 0,
                lbl_117_data_A684, lbl_117_data_36A8, 1));

            Vec2f speed;
            Vec2f oldSpeed;
            Vec2f normal;

            const DededeSpeed initialHorizontal = horizontal->getSpeed();
            copySpeed(speed, initialHorizontal);
            Vec2f::copy(oldSpeed, speed);

            const DededeSpeed touchNormal = reinterpret_cast<DededeGroundSpeedView*>(
                &accesser->getGroundModule())->getTouchNormal(
                    static_cast<grCollStatus::TouchMask>(0xff), 0);
            copySpeed(normal, touchNormal);

            float lr = accesser->getPostureModule().getLr();
            const DededeSpeed initialVertical = vertical->getSpeed();
            speed.m_y = initialVertical.y;

            float dot = normal.m_x * speed.m_x + normal.m_y * speed.m_y;
            speed = speed - *reinterpret_cast<const Vec2f*>(
                &fn_117_2053C(&fn_117_2053C(words(normal), 2.0f), dot));

            if (self->m_moduleAccesser->getWorkManageModule().isFlag(0x22000005) &&
                !accesser->getWorkManageModule().isFlag(0x2200000c)) {
                speed.m_x = *reinterpret_cast<float*>(self->params + 0x128) * lr;
                speed.m_y = *reinterpret_cast<float*>(self->params + 0x100);
                accesser->getWorkManageModule().onFlag(0x2200000c);
            } else if ((sign = oldSpeed.m_x < 0.0f ? -1 : 1,
                        signFloatOld = static_cast<float>(sign),
                        sign = speed.m_x < 0.0f ? -1 : 1,
                        static_cast<float>(sign) * signFloatOld < 0.0f)) {
                accesser->getPostureModule().setLr(-1.0f * lr);
                accesser->getPostureModule().updateRotYLr();
                accesser->getStageObject().updateNodeSRT();
            }

            Vec2f horizontalSpeed;
            horizontalSpeed.m_x = speed.m_x * self->variant[5];
            horizontalSpeed.m_y = 0.0f;
            horizontal->speed = horizontalSpeed;

            if (speed.m_y < 0.0f)
                speed.m_y = 0.0f;

            vertical->speed.m_x = speed.m_y * self->variant[6];
            reinterpret_cast<DededeCaptureSoundModule*>(&accesser->getSoundModule())
                ->playSE(static_cast<SndID>(0x401), false, false, 0);
        }
        return 1;
    }

    return 0;
}