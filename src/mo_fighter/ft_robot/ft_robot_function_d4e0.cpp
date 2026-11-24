#include <so/so_value_accesser.h>
#pragma force_active on

struct Pair {
    float x, y;
};

struct Kinetic {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual soKineticEnergy* getEnergy(int);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual Pair getSumSpeed(const short&);
};

struct Control {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual unsigned int getButton();
};

extern "C" {
extern const float lbl_120_rodata_18;
extern const char lbl_120_data_6FE4[];
extern const char lbl_120_data_2208[];
extern const char lbl_120_data_6EEC[];
extern const char lbl_120_data_7028[];
extern const char lbl_120_data_6F90[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_120_8718(Vec3f*, float, float, float);
float fn_120_DE7C(float);
void fn_27_89DAC(int, soModuleAccesser*);
}

static inline Vec3f* initializeRotation(
    const Vec3f& rotation, float x, float y, float z
) {
    return fn_120_8718(const_cast<Vec3f*>(&rotation), x, y, z);
}

static inline void resetHorizontal(
    soKineticEnergy* energy, int type, Vec2f* speed,
    const Vec3f& rotation, soModuleAccesser* a
) {
    energy->resetEnergy(
        type, speed,
        initializeRotation(rotation, lbl_120_rodata_18,
                           lbl_120_rodata_18, lbl_120_rodata_18),
        a);
}

extern "C" void fn_120_D4E0(void*, soModuleAccesser* a) {
    void* gravityOrController;
    soKineticEnergy* energy;
    void* object;
    soWorkManageModule& work = a->getWorkManageModule();

    switch (a->getStatusModule().getStatusKind()) {
    case 0x117: {
        short mask = 1;
        Vec2f speed;
        Pair sum = ((Kinetic*)a->m_enumerationStart->m_kineticModule)
                       ->getSumSpeed(mask);
        __memcpy(&speed, &sum, 8);

        float x = speed.m_x;
        float y = speed.m_y;
        float lr = a->getPostureModule().getLr();
        float scale = soValueAccesser::getConstantFloat(a, 0xfbe, 0);
        float factor = soValueAccesser::getConstantFloat(a, 0xbd5, 0);
        factor *= scale;
        int situation = a->getSituationModule().getKind();
        enum WorkValue {
            ResetMotion = 0,
            MinimumWorkValue = -2147483647 - 1,
            MaximumWorkValue = 2147483647
        };
        WorkValue count;

        if (work.isFlag(0x22000014)) {
            float offset;
            if (situation == 2) {
                if (work.isFlag(0x22000012))
                    offset = lr * soValueAccesser::getConstantFloat(a, 0xfb4, 0);
                else
                    offset = lr * soValueAccesser::getConstantFloat(a, 0xfb3, 0);
            } else {
                if (work.isFlag(0x22000012))
                    offset = lr * soValueAccesser::getConstantFloat(a, 0xfb2, 0);
                else
                    offset = lr * soValueAccesser::getConstantFloat(a, 0xfb1, 0);
            }
            x += offset;
        }

        if (work.isFlag(0x22000014) ||
            a->getSituationModule().getKind() != work.getInt(0x20000003)) {
            if (situation == 2) {
                soKineticEnergy* motion = (soKineticEnergy*)__dynamic_cast(
                    a->getKineticModule().getEnergy(2), 0,
                    lbl_120_data_6FE4, lbl_120_data_2208, 1);
                gravityOrController = __dynamic_cast(
                    a->getKineticModule().getEnergy(1), 0,
                    lbl_120_data_7028, lbl_120_data_2208, 1);

                count = ResetMotion;
                Vec2f horizontal(x, lbl_120_rodata_18);
                resetHorizontal(motion, count, &horizontal, Vec3f(), a);

                Vec2f limit(factor, lbl_120_rodata_18);
                *(float*)((char*)motion + 0x18) = limit.m_x;
                *(float*)((char*)motion + 0x1c) = limit.m_y;
                ((unsigned char*)motion)[5] |= 0x80;

                Vec2f vertical(lbl_120_rodata_18, y);
                resetHorizontal(static_cast<soKineticEnergy*>(gravityOrController), 0, &vertical, Vec3f(), a);
                static_cast<unsigned char*>(gravityOrController)[5] |= 0x80;
                fn_27_89DAC(3, a);
            } else {
                object = __dynamic_cast(
                    a->getKineticModule().getEnergy(3), 0,
                    lbl_120_data_6EEC, lbl_120_data_2208, 1);

                Vec2f horizontal(x, lbl_120_rodata_18);
                resetHorizontal(static_cast<soKineticEnergy*>(object), 0, &horizontal, Vec3f(), a);
                static_cast<unsigned char*>(object)[5] |= 0x80;
                fn_27_89DAC(1, a);
                fn_27_89DAC(2, a);
            }
            work.offFlag(0x22000014);
            work.setInt(situation, 0x20000003);
        }

        WorkValue frame = static_cast<WorkValue>(work.getInt(0x20000000));
        Vec3f pos = a->getPostureModule().getRot(0);
        float power = work.getFloat(0x21000004);
        count = static_cast<WorkValue>(work.getInt(0x20000001));
        work.setInt(frame + 1, 0x20000000);

        if (situation == 2) {
            energy = (soKineticEnergy*)__dynamic_cast(
                a->getKineticModule().getEnergy(1), 0,
                lbl_120_data_7028, lbl_120_data_2208, 1);
            if (frame + 1 <= soValueAccesser::getConstantInt(a, 0x5dc2, 0)) {
                float mul = soValueAccesser::getConstantFloat(a, 0xfb5, 0);
                float acceleration = -soValueAccesser::getConstantFloat(a, 0xbcf, 0);
                acceleration *= mul;
                *(float*)((char*)energy + 0x10) = acceleration;
            } else {
                *(float*)((char*)energy + 0x10) =
                    -soValueAccesser::getConstantFloat(a, 0xbcf, 0);
            }
        }

        gravityOrController = a->m_enumerationStart->m_controllerModule;
        unsigned int button =
            soController::getButtonMask(soController::Pad_Button_Special);
        unsigned int buttons = static_cast<Control*>(gravityOrController)->getButton();
        if (!(buttons & button))
            work.onFlag(0x22000011);

        if (count >= soValueAccesser::getConstantInt(a, 0x5dc4, 0) &&
            work.isFlag(0x22000011)) {
            int max = soValueAccesser::getConstantInt(a, 0x5dc5, 0);
            if (work.getInt(0x20000002) < max) {
                object = a->m_enumerationStart->m_controllerModule;
                unsigned int b =
                    soController::getButtonMask(soController::Pad_Button_Special);
                unsigned int buttons2 = static_cast<Control*>(object)->getButton();
                if (buttons2 & b) {
                    power += soValueAccesser::getConstantFloat(a, 0xfbc, 0);
                    work.addInt(1, 0x20000002);
                    work.offFlag(0x22000011);
                    count = ResetMotion;
                }
            }
        }

        if (count < soValueAccesser::getConstantInt(a, 0x5dc4, 0))
            count = static_cast<WorkValue>(count + 1);
        work.setInt(count, 0x20000001);

        int node = a->getModelModule().getNodeId(lbl_120_data_6F90);
        Vec3f rot = a->getModelModule().getNodeRotate(node);
        work.addFloat(power, 0x21000009);
        rot.m_x = work.getFloat(0x21000009);

        float stick = a->getControllerModule().getStickX();
        float angle = a->getWorkManageModule().getFloat(0x21000007);
        if (fn_120_DE7C(stick) > lbl_120_rodata_18) {
            float direction = a->getPostureModule().getLr();
            float delta = stick * -soValueAccesser::getConstantFloat(a, 0xfb7, 0);
            stick = delta * direction;
            float max = soValueAccesser::getConstantFloat(a, 0xfb6, 0);
            angle += stick;
            if (fn_120_DE7C(angle) > max) {
                if (angle < lbl_120_rodata_18)
                    max = -max;
                angle = max;
            }
        } else {
            float step = soValueAccesser::getConstantFloat(a, 0xfbd, 0);
            if (angle < lbl_120_rodata_18) {
                angle += step;
                if (angle > lbl_120_rodata_18)
                    angle = lbl_120_rodata_18;
            } else if (angle > lbl_120_rodata_18) {
                angle -= step;
                if (angle < lbl_120_rodata_18)
                    angle = lbl_120_rodata_18;
            }
        }

        rot.m_y = angle;
        a->getModelModule().setNodeRotate(node, &rot);
        work.setFloat(angle, 0x21000007);

        float decay = a->getWorkManageModule().getFloat(0x21000005);
        if (frame + 1 >= soValueAccesser::getConstantInt(a, 0x5dc3, 0))
            decay = soValueAccesser::getConstantFloat(a, 0xfb9, 0);
        power -= decay;
        work.setFloat(power, 0x21000004);
        break;
    }
    }
}
