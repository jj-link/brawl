#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

#pragma opt_common_subs off

struct SpeedPair {
    float x, y;
};

struct KineticSpeedView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual SpeedPair getSumSpeed(const short&);
};

struct SoundView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int playSE(int, bool, bool, int);
};

struct AttackView {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44();
    virtual void setPower(float);
};

inline void copySpeed(Vec2f& out, const SpeedPair& value) {
    __memcpy(&out, &value, 8);
}

extern "C" {
extern const char lbl_119_data_5C14[];
extern const char lbl_119_data_5CF4[];
extern const char lbl_119_data_1374[];
extern const float lbl_119_rodata_50;
extern const float lbl_119_rodata_54;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_119_8F00(Vec3f*, float, float, float);
void fn_119_B6CC(void*, const Vec2f*);
void fn_119_ECC0(void*, soModuleAccesser*);
void fn_27_89DAC(int, soModuleAccesser*);
}

extern "C" void fn_119_DDB4(void* self, soModuleAccesser* accesser) {
    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_119_data_5C14, lbl_119_data_1374, 1));
    soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_119_data_5CF4, lbl_119_data_1374, 1));

    short mask = 1;
    Vec2f speed;
    const SpeedPair& summed = reinterpret_cast<KineticSpeedView*>(
        &accesser->getKineticModule())->getSumSpeed(mask);
    copySpeed(speed, summed);
    float horizontal = speed.m_x;
    float vertical = speed.m_y;
    float facing = accesser->getPostureModule().getLr();

    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x113:
        if (accesser->getSituationModule().getKind() == 2 &&
            vertical < lbl_119_rodata_50) {
            vertical *= soValueAccesser::getConstantFloat(accesser, 0xFAE, 0);
            Vec2f value(lbl_119_rodata_50, vertical);
            Vec3f rotation;
            gravity->resetEnergy(
                0, &value,
                fn_119_8F00(&rotation, lbl_119_rodata_50,
                           lbl_119_rodata_50, lbl_119_rodata_50),
                accesser);
            *(reinterpret_cast<unsigned char*>(gravity) + 5) |= 0x80;
        }
        break;

    case 0x11A: {
        int value = reinterpret_cast<SoundView*>(
            &accesser->getSoundModule())->playSE(0x1717, false, false, 0);
        accesser->getWorkManageModule().setInt(value, 0x20000004);
        break;
    }

    case 0x11B: {
        fn_119_ECC0(self, accesser);
        int count = accesser->getWorkManageModule().getInt(0x20000002);
        if (accesser->getSituationModule().getKind() == 2) {
            horizontal = facing *
                (soValueAccesser::getConstantFloat(accesser, 0xFA4, 0) +
                 static_cast<float>(count) *
                     soValueAccesser::getConstantFloat(accesser, 0xFA6, 0));
            Vec2f vector(horizontal, lbl_119_rodata_50);
            Vec3f rotation;
            stop->resetEnergy(
                6, &vector,
                fn_119_8F00(&rotation, lbl_119_rodata_50,
                           lbl_119_rodata_50, lbl_119_rodata_50),
                accesser);
            Vec2f offset(
                soValueAccesser::getConstantFloat(accesser, 0xFA8, 0),
                lbl_119_rodata_50);
            fn_119_B6CC(reinterpret_cast<char*>(stop) + 0x20, &offset);
            accesser->getWorkManageModule().setInt(2, 0x20000000);
        } else {
            horizontal = facing *
                (soValueAccesser::getConstantFloat(accesser, 0xFA3, 0) +
                 static_cast<float>(count) *
                     soValueAccesser::getConstantFloat(accesser, 0xFA5, 0));
            Vec2f vector(horizontal, lbl_119_rodata_50);
            Vec3f rotation;
            stop->resetEnergy(
                0, &vector,
                fn_119_8F00(&rotation, lbl_119_rodata_50,
                           lbl_119_rodata_50, lbl_119_rodata_50),
                accesser);
            Vec2f offset(
                soValueAccesser::getConstantFloat(accesser, 0xFA7, 0),
                lbl_119_rodata_50);
            fn_119_B6CC(reinterpret_cast<char*>(stop) + 0x20, &offset);
            accesser->getWorkManageModule().setInt(0, 0x20000000);
        }

        Vec2f duration(lbl_119_rodata_54, lbl_119_rodata_50);
        fn_119_B6CC(reinterpret_cast<char*>(stop) + 0x28, &duration);
        *(reinterpret_cast<unsigned char*>(stop) + 5) |= 0x80;
        fn_27_89DAC(1, accesser);
        fn_27_89DAC(2, accesser);
        fn_27_89DAC(0, accesser);
        break;
    }

    case 0x11C: {
        float power = static_cast<float>(
                accesser->getWorkManageModule().getInt(0x20000001)) *
            soValueAccesser::getConstantFloat(accesser, 0xFAB, 0);
        reinterpret_cast<AttackView*>(
            accesser->m_enumerationStart->m_collisionAttackModule)
            ->setPower(power);
    }
    case 0x11D: {
        int mode;
        if (accesser->getSituationModule().getKind() == 2) {
            if (accesser->getStatusModule().getStatusKind() == 0x11C)
                horizontal *= soValueAccesser::getConstantFloat(
                    accesser, 0xFAA, 0);
            else
                horizontal *= soValueAccesser::getConstantFloat(
                    accesser, 0xFAD, 0);

            mode = 6;
            Vec2f vector(lbl_119_rodata_50, vertical);
            Vec3f rotation;
            gravity->resetEnergy(
                0, &vector,
                fn_119_8F00(&rotation, lbl_119_rodata_50,
                           lbl_119_rodata_50, lbl_119_rodata_50),
                accesser);
            *(reinterpret_cast<unsigned char*>(gravity) + 5) |= 0x80;
        } else {
            if (accesser->getStatusModule().getStatusKind() == 0x11C)
                horizontal *= soValueAccesser::getConstantFloat(
                    accesser, 0xFA9, 0);
            else
                horizontal *= soValueAccesser::getConstantFloat(
                    accesser, 0xFAC, 0);

            mode = 0;
            fn_27_89DAC(1, accesser);
        }

        Vec2f vector(horizontal, lbl_119_rodata_50);
        Vec3f rotation;
        stop->resetEnergy(
            mode, &vector,
            fn_119_8F00(&rotation, lbl_119_rodata_50,
                       lbl_119_rodata_50, lbl_119_rodata_50),
            accesser);
        Vec2f duration(lbl_119_rodata_54, lbl_119_rodata_50);
        fn_119_B6CC(reinterpret_cast<char*>(stop) + 0x28, &duration);
        *(reinterpret_cast<unsigned char*>(stop) + 5) |= 0x80;

        soWorkManageModule& work = accesser->getWorkManageModule();
        work.setInt(accesser->getSituationModule().getKind(), 0x20000000);
        break;
    }
    }
}
