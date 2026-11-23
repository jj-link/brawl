// The checker reports a 99.9% match. Three instructions use r28 in place of r27.
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

#pragma opt_common_subs on
#pragma scheduling off
#pragma inline_depth(8)
#pragma inline_max_size(1000)

class Class_6700 {
public:
    virtual void fn_119_58E4();
    virtual void fn_119_11708();
    virtual void fn_119_13614();
    virtual void fn_119_1360C();
    virtual void fn_119_13604();
    virtual void fn_119_135FC();
    virtual void fn_119_135F4();
    virtual void fn_119_135EC();
    virtual void fn_119_135E4();
    virtual void fn_119_135DC();
    virtual void fn_119_135D4();
    virtual void fn_119_135CC();
    virtual void fn_119_135C4();
    virtual void fn_119_135BC();
    virtual void fn_119_1356C(int, float, int);
    virtual float fn_119_135B4(int);
    virtual void fn_119_135A4();
    virtual void fn_119_13594();
    virtual void fn_119_13584();
    virtual void fn_119_13574();
};

struct IkeSpeedPair {
    float x, y;
};

class IkeKinetic {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual soKineticEnergy* getEnergy(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual IkeSpeedPair getSumSpeed(const short&);
};

class IkeStatus {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int getStatusKind();
};

class IkeSituation {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int getKind();
};

class IkeWork {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int getInt(int);
    virtual void setInt(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual bool isFlag(int);
    virtual void slot18();
    virtual void offFlag(int);
};

class IkeEnergy {
public:
    virtual void slot0();
    virtual void slot1();
    virtual IkeSpeedPair getSpeed();
    virtual void slot3();
    virtual void slot4();
    virtual void reset(int, const Vec2f*, const float*, soModuleAccesser*);
};

struct IkeModules {
    char pad0[0x14];
    IkeSituation* situation;
    char pad18[0x38];
    Class_6700* motion;
    char pad54[0x10];
    IkeWork* work;
    char pad68[8];
    IkeStatus* status;
    char pad74[8];
    IkeKinetic* kinetic;
};

extern "C" {
extern const float lbl_119_rodata_50[];
extern const char lbl_119_data_5C14[];
extern const char lbl_119_data_5CF4[];
extern const char lbl_119_data_1374[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
float* fn_119_8F00(float*, float, float, float);
void fn_119_B6CC(Vec2f&, const Vec2f&);
void fn_27_89DAC(int, soModuleAccesser*);
}

static inline IkeModules* ikeModules(soModuleAccesser* accesser) {
    return *reinterpret_cast<IkeModules**>(
        reinterpret_cast<char*>(accesser) + 0xD8);
}

static inline void ikeCopy(Vec2f& out, const IkeSpeedPair& value) {
    __memcpy(&out, &value, 8);
}

extern "C" void fn_119_E4BC(void*, soModuleAccesser* accesser) {
        IkeSituation* situation;
    const float* constants = lbl_119_rodata_50;
    float rotationB4[3];
    float rotationA8[3];
    float rotation9C[3];
    float rotation90[3];
    float rotation84[3];
    int flag = 1;
    short mask = flag;
    Vec2f sum;
    Vec2f speed;
    const IkeSpeedPair summed = ikeModules(accesser)->kinetic->getSumSpeed(mask);
    ikeCopy(sum, summed);
    float horizontal = sum.m_x;

    switch (ikeModules(accesser)->status->getStatusKind()) {
    case 0x113:
    case 0x11A:
        if (ikeModules(accesser)->work->isFlag(0x22000011)) {
            int index = ikeModules(accesser)->work->getInt(0x20000004);
            if (index >= 0 &&
                ikeModules(accesser)->motion->fn_119_135B4(index) > constants[4]) {
                ikeModules(accesser)->motion->fn_119_1356C(index, constants[4], 0);
            }
        }
        break;

    case 0x11B: {
        IkeModules* modules = ikeModules(accesser);
        IkeWork* previousWork = modules->work;
        situation = modules->situation;
        if (situation->getKind() != previousWork->getInt(0x20000000)) {
            IkeEnergy* stop = static_cast<IkeEnergy*>(__dynamic_cast(
                ikeModules(accesser)->kinetic->getEnergy(3), 0,
                lbl_119_data_5C14, lbl_119_data_1374, flag));

            if (ikeModules(accesser)->situation->getKind() == 2) {
                Vec2f stopSpeed;
                stopSpeed.m_x = horizontal;
                stopSpeed.m_y = constants[0];
                stop->reset(6, &stopSpeed,
                    fn_119_8F00(rotationB4, constants[0], constants[0], constants[0]),
                    accesser);
                Vec2f value;
                value.m_x = soValueAccesser::getConstantFloat(accesser, 0xFA8, 0);
                value.m_y = constants[0];
                fn_119_B6CC(*reinterpret_cast<Vec2f*>(
                    reinterpret_cast<char*>(stop) + 0x20), value);
            } else {
                Vec2f stopSpeed;
                stopSpeed.m_x = horizontal;
                stopSpeed.m_y = constants[0];
                stop->reset(0, &stopSpeed,
                    fn_119_8F00(rotationA8, constants[0], constants[0], constants[0]),
                    accesser);
                Vec2f value;
                value.m_x = soValueAccesser::getConstantFloat(accesser, 0xFA7, 0);
                value.m_y = constants[0];
                fn_119_B6CC(*reinterpret_cast<Vec2f*>(
                    reinterpret_cast<char*>(stop) + 0x20), value);
            }

            Vec2f limit;
            limit.m_x = constants[1];
            limit.m_y = constants[0];
            fn_119_B6CC(*reinterpret_cast<Vec2f*>(
                reinterpret_cast<char*>(stop) + 0x28), limit);
            reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;

            IkeWork* work = ikeModules(accesser)->work;
            work->setInt(ikeModules(accesser)->situation->getKind(), 0x20000000);
            fn_27_89DAC(1, accesser);
            fn_27_89DAC(2, accesser);
            fn_27_89DAC(0, accesser);
        }
        break;
    }

    case 0x11C:
        if (ikeModules(accesser)->work->isFlag(0x22000015)) {
            IkeEnergy* stop = static_cast<IkeEnergy*>(__dynamic_cast(
                ikeModules(accesser)->kinetic->getEnergy(3), 0,
                lbl_119_data_5C14, lbl_119_data_1374, flag));

            if (ikeModules(accesser)->situation->getKind() == 2)
                horizontal *= soValueAccesser::getConstantFloat(accesser, 0xFAD, 0);
            else
                horizontal *= soValueAccesser::getConstantFloat(accesser, 0xFAC, 0);

            Vec2f value;
            const IkeSpeedPair currentSpeed = stop->getSpeed();
            const float vertical = currentSpeed.y;
            value.m_x = horizontal;
            value.m_y = vertical;
            fn_119_B6CC(*reinterpret_cast<Vec2f*>(
                reinterpret_cast<char*>(stop) + 8), value);
            ikeModules(accesser)->work->offFlag(0x22000015);
        }
        /* fall through */
    case 0x11D: {
        flag = 1;
        IkeModules* modules = ikeModules(accesser);
        IkeWork* previousWork = modules->work;
        IkeSituation* situation = modules->situation;
        if (situation->getKind() != previousWork->getInt(0x20000000)) {
            IkeEnergy* stop = static_cast<IkeEnergy*>(__dynamic_cast(
                ikeModules(accesser)->kinetic->getEnergy(3), 0,
                lbl_119_data_5C14, lbl_119_data_1374, flag));
            IkeEnergy* gravity = static_cast<IkeEnergy*>(__dynamic_cast(
                ikeModules(accesser)->kinetic->getEnergy(1), 0,
                lbl_119_data_5CF4, lbl_119_data_1374, flag));

            short attributes = 1;
            const IkeSpeedPair summed = ikeModules(accesser)->kinetic->getSumSpeed(attributes);
            ikeCopy(speed, summed);

            if (ikeModules(accesser)->situation->getKind() == 2) {
                Vec2f stopSpeed;
                stopSpeed.m_x = speed.m_x;
                stopSpeed.m_y = constants[0];
                stop->reset(6, &stopSpeed,
                    fn_119_8F00(rotation9C, constants[0], constants[0], constants[0]),
                    accesser);

                Vec2f gravitySpeed(constants[0], speed.m_y);
                gravity->reset(0, &gravitySpeed,
                    fn_119_8F00(rotation90, constants[0], constants[0], constants[0]),
                    accesser);
                reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
            } else {
                Vec2f stopSpeed;
                stopSpeed.m_x = speed.m_x;
                stopSpeed.m_y = constants[0];
                stop->reset(0, &stopSpeed,
                    fn_119_8F00(rotation84, constants[0], constants[0], constants[0]),
                    accesser);
                fn_27_89DAC(1, accesser);
            }

            Vec2f limit;
            limit.m_x = constants[1];
            limit.m_y = constants[0];
            fn_119_B6CC(*reinterpret_cast<Vec2f*>(
                reinterpret_cast<char*>(stop) + 0x28), limit);
            reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;

            IkeWork* work = ikeModules(accesser)->work;
            work->setInt(ikeModules(accesser)->situation->getKind(), 0x20000000);
            fn_27_89DAC(2, accesser);
            fn_27_89DAC(0, accesser);
        }
        break;
    }
    }
}
