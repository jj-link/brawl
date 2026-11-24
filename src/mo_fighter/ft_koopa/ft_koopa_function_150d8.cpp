#pragma always_inline on
#pragma inline all
#pragma scheduling off
#pragma optimization_level 4
#pragma opt_strength_reduction off

#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const float lbl_102_rodata_50;
extern const float lbl_102_rodata_54;
extern const char lbl_102_data_77F0[];
}

// Declaration-only view of the sound module used at this call site: the SE
// handle is passed before the volume.
class KoopaSoundVolView {
public:
    virtual ~KoopaSoundVolView();
    virtual void update(Vec3f* pos);
    virtual void deactivate();
    virtual void activate(Vec3f* pos);
    virtual void setPos(Vec3f* pos, int);
    virtual int playSE(SndID sndId, bool, int, int);
    virtual int playSENo3d(SndID sndId, bool);
    virtual int playSEPos(SndID sndId, Vec3f* pos, bool, int, int);
    virtual int playStatusSE(SndID sndId, bool, int);
    virtual void stopStatusSE();
    virtual void setPlayHitSEFlag(bool);
    virtual bool getPlayHitSEFlag();
    virtual void playHitSE(float, void*);
    virtual void playDamageSE(u32, u32);
    virtual void setSEVol(int handle, float volume, int);
};

inline float clampAngle(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_102_150D8(void* self, soModuleAccesser* a) {
    int state = a->getWorkManageModule().getInt(0x20000002);
    if (state != a->getWorkManageModule().getInt(0x20000003)) {
        a->getWorkManageModule().setInt(state, 0x20000003);
        if (state == 2)
            a->getSoundModule().stopStatusSE();
    }

    switch (state) {
    case 1:
        float low = soValueAccesser::getConstantFloat(a, 0xFA9, 0);
        float high = soValueAccesser::getConstantFloat(a, 0xFA8, 0);
        float ratio = (a->getWorkManageModule().getFloat(0x11000013) - low) /
                      (high - low);
        int count = a->getWorkManageModule().getInt(0x20000000);

        if (count >= 3 && a->getWorkManageModule().getInt(0x20000006) == -1) {
            int handle = a->getSoundModule().playStatusSE((SndID)0x1A20, false, 0);
            a->getWorkManageModule().setInt(handle, 0x20000006);
        } else if (count >= 11 && a->getWorkManageModule().getInt(0x20000007) == -1) {
            int handle = a->getSoundModule().playStatusSE((SndID)0x1A21, false, 0);
            a->getWorkManageModule().setInt(handle, 0x20000007);
        }

        int frame = a->getWorkManageModule().getInt(0x20000004);
        if (frame == 0) {
            a->getWorkManageModule().onFlag(0x22000013);
            int handle = a->getWorkManageModule().getInt(0x20000007);
            if (handle != -1) {
                float volume = ratio;
                float minimum = soValueAccesser::getConstantFloat(a, 0xFB0, 0);
                if (ratio < minimum)
                    volume = minimum;
                reinterpret_cast<KoopaSoundVolView*>(&a->getSoundModule())
                    ->setSEVol(handle, volume, 0);
            }
            soControllerModule& ctrl = a->getControllerModule();
            ctrl.setRumble(ratio > lbl_102_rodata_50 ? 0 : (ratio <= lbl_102_rodata_50 ? 1 : 1), 0, true, -1);
        }

        frame++;
        if (frame >= soValueAccesser::getConstantInt(a, 0x5DC5, 0))
            frame = 0;
        a->getWorkManageModule().setInt(frame, 0x20000004);

        if (ratio > lbl_102_rodata_50 &&
            count % soValueAccesser::getConstantInt(a, 0x5DC4, 0) == 0) {
            a->getCameraModule().reqQuake(soCameraModule::Quake_S, a);
        }

        a->getWorkManageModule().setInt(count + 1, 0x20000000);
        float angle = a->getWorkManageModule().getFloat(0x21000004);
        float stick = a->getControllerModule().getStickY();

        if ((float)(double)nw4r::math::FAbs(stick) > lbl_102_rodata_50) {
            float upper = soValueAccesser::getConstantFloat(a, 0xFA2, 0);
            float lower = soValueAccesser::getConstantFloat(a, 0xFA3, 0);
            float turn = soValueAccesser::getConstantFloat(a, 0xFA4, 0);
            angle += turn * stick;
            angle = clampAngle(angle, -lower, upper);
            a->getWorkManageModule().setFloat(angle, 0x21000004);
        }

        int node = a->getModelModule().getNodeId(lbl_102_data_77F0);
        Vec3f rotation;
        rotation.m_x = -angle * soValueAccesser::getConstantFloat(a, 0xFA5, 0);
        rotation.m_y = lbl_102_rodata_54;
        rotation.m_z = lbl_102_rodata_54;
        a->getModelModule().setNodeRotate(node, &rotation);
        break;
    }
}
