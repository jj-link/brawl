#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <types.h>

#pragma force_active on
#pragma switch_tables on

struct DispatchSpeed {
    float x;
    float y;
};

struct ResetContext {
    unsigned char initialized;

    ResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual u64 slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual Object_vptr_0* slot6(int);

    char pad04[4];
    float speedX;
    float speedY;
    float field10;
    float field14;
    float field18;
    float field1C;
    float field20;
    float field24;
    char pad28[0x14];
    float field3C;
    float field40;
    float field44;
    float field48;
};

struct KineticHolder {
    char pad[0x7C];
    Object_vptr_0* kinetic;
};

struct AccesserLayout {
    char pad[0xD8];
    KineticHolder* holder;
};

extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
DispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_15FBC8(int, int, Vec2f*, soModuleAccesser*);
void fn_27_160268(soModuleAccesser*);
float fn_27_192278(soModuleAccesser*, unsigned long);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
void* __memcpy(void*, const void*, unsigned long);

extern char lbl_27_data_2E380[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_79F8;
extern const float lbl_27_rodata_79FC;
}

extern "C" void fn_27_35A6FC(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }

    Vec2f speed;
    DispatchSpeed returnedSpeed = fn_27_164B10(accesser, true, true);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));

    switch (kind) {
    case 0x64: {
        fn_27_15FBC8(0, resetKind, &speed, accesser);
        Object_vptr_0* energy = ((AccesserLayout*)accesser)->holder->kinetic->slot6(2);
        Object_vptr_0* p = (Object_vptr_0*)__dynamic_cast(
            energy, 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
        float factor = fn_27_192278(accesser, 0xFA0);
        float constant = soValueAccesser::getConstantFloat(accesser, 0xBD5, 0);
        Vec2f value;
        value.m_x = constant * factor;
        value.m_y = lbl_27_rodata_79F8;
        p->field18 = value.m_x;
        p->field1C = value.m_y;
        break;
    }
    case 0x65: {
        fn_27_15FBC8(0, resetKind, &speed, accesser);
        Object_vptr_0* energy = ((AccesserLayout*)accesser)->holder->kinetic->slot6(2);
        Object_vptr_0* p = (Object_vptr_0*)__dynamic_cast(
            energy, 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
        float factor = soValueAccesser::getConstantFloat(accesser, 0xFA7, 0);
        float constant = soValueAccesser::getConstantFloat(accesser, 0xBD5, 0);
        Vec2f value;
        value.m_x = constant * factor;
        value.m_y = lbl_27_rodata_79F8;
        p->field18 = value.m_x;
        p->field1C = value.m_y;
        break;
    }
    case 0x66: {
        fn_27_15FBC8(0, resetKind, &speed, accesser);
        Object_vptr_0* energy = ((AccesserLayout*)accesser)->holder->kinetic->slot6(2);
        Object_vptr_0* p = (Object_vptr_0*)__dynamic_cast(
            energy, 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
        DispatchSpeed secondReturned;
        DispatchSpeed firstReturned;
        DispatchSpeed second;
        DispatchSpeed first;
        *reinterpret_cast<u64*>(&firstReturned) = p->slot2();
        __memcpy(&first, &firstReturned, sizeof(first));
        first.x *= soValueAccesser::getConstantFloat(accesser, 0xFA9, 0);
        p->speedX = first.x;
        p->speedY = first.y;

        energy = ((AccesserLayout*)accesser)->holder->kinetic->slot6(1);
        p = (Object_vptr_0*)__dynamic_cast(
            energy, 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        *reinterpret_cast<u64*>(&secondReturned) = p->slot2();
        __memcpy(&second, &secondReturned, sizeof(second));
        second.y *= soValueAccesser::getConstantFloat(accesser, 0xFAA, 0);
        p->speedY = second.y;
        break;
    }
    case 0x67: {
        Vec3f zero3;
        Vec3f zero2;
        Vec3f zero1;
        Vec2f tmpB;
        Vec2f tmpA;
        Vec2f control;
        Vec2f motion;
        Vec2f gravity;

        gravity.m_y = speed.m_y;
        zero1.m_x = lbl_27_rodata_79FC;
        zero1.m_y = lbl_27_rodata_79FC;
        zero1.m_z = lbl_27_rodata_79FC;
        gravity.m_x = lbl_27_rodata_79FC;
        fn_27_89D08(1, accesser, 0, &gravity, &zero1);

        zero2.m_x = lbl_27_rodata_79FC;
        zero2.m_y = lbl_27_rodata_79FC;
        zero2.m_z = lbl_27_rodata_79FC;
        motion.m_x = lbl_27_rodata_79FC;
        motion.m_y = lbl_27_rodata_79FC;
        fn_27_89D08(2, accesser, 11, &motion, &zero2);

        float sx = speed.m_x;
        zero3.m_x = lbl_27_rodata_79FC;
        zero3.m_y = lbl_27_rodata_79FC;
        zero3.m_z = lbl_27_rodata_79FC;
        control.m_x = sx;
        control.m_y = lbl_27_rodata_79FC;
        fn_27_89D08(3, accesser, 6, &control, &zero3);

        Object_vptr_0* energy = ((AccesserLayout*)accesser)->holder->kinetic->slot6(4);
        *((unsigned char*)energy + 5) |= 0x80;

        energy = ((AccesserLayout*)accesser)->holder->kinetic->slot6(1);
        Object_vptr_0* p = (Object_vptr_0*)__dynamic_cast(
            energy, 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        p->field14 = soValueAccesser::getConstantFloat(accesser, 0xFB1, 0);

        energy = ((AccesserLayout*)accesser)->holder->kinetic->slot6(2);
        p = (Object_vptr_0*)__dynamic_cast(
            energy, 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
        p->field3C = soValueAccesser::getConstantFloat(accesser, 0xFAB, 0);
        p->field40 = lbl_27_rodata_79FC;

        float y = soValueAccesser::getConstantFloat(accesser, 0xFAF, 0);
        float x = soValueAccesser::getConstantFloat(accesser, 0xFAC, 0);
        tmpA.m_x = x;
        tmpA.m_y = y;
        p->field18 = tmpA.m_x;
        p->field1C = tmpA.m_y;

        y = soValueAccesser::getConstantFloat(accesser, 0xFB0, 0);
        x = soValueAccesser::getConstantFloat(accesser, 0xFAD, 0);
        tmpB.m_x = x;
        tmpB.m_y = y;
        p->field20 = tmpB.m_x;
        p->field24 = tmpB.m_y;

        p->field44 = soValueAccesser::getConstantFloat(accesser, 0xFAE, 0);
        p->field48 = lbl_27_rodata_79FC;
        break;
    }
    case 0x68: {
        ResetContext context;
        break;
    }
    case 0x69: {
        ResetContext context;
        break;
    }
    case 0x6A: {
        ResetContext context;
        break;
    }
    case 0x6B: {
        ResetContext context;
        break;
    }
    case 0x6C: {
        ResetContext context;
        break;
    }
    case 0x6D: {
        ResetContext context;
        break;
    }
    default:
        return;
    }

    fn_27_160268(accesser);
}
