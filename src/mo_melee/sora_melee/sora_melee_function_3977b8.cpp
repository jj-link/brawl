#pragma force_active on
#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>

class KineticView {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Vec2f slot13(short*);
};

class ObjView {
public:
    virtual void isNull();
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
    virtual float slot16();
    virtual int slot17(int);
};

class EnergyView {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, const Vec2f&, const Vec3f&, soModuleAccesser*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    char pad[0x38];
    float unk3C;
};

extern "C" {
float fn_27_192278(void*, unsigned long);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_2E380[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7DB0;
}

extern "C" void fn_27_3977B8(void*, soModuleAccesser* a) {
    short mask = 1;
    Vec2f speed;
    __memcpy(&speed, &((KineticView*)a->m_enumerationStart->m_kineticModule)->slot13(&mask), sizeof(speed));
    float f31 = fn_27_192278(a, 0xFA4);
    float f30 = soValueAccesser::getConstantFloat(a, 0xBC4, 0);
    f30 = f30 * ((ObjView*)a->m_enumerationStart->m_controllerModule)->slot16();
    speed.m_x = speed.m_x * soValueAccesser::getConstantFloat(a, 0xBC6, 0);
    speed.m_x += f30;
    speed.m_x *= f31;
    float lim = soValueAccesser::getConstantFloat(a, 0xBC7, 0);
    if (nw4r::math::FAbs(speed.m_x) > lim) {
        if (speed.m_x < lbl_27_rodata_7DB0) {
            lim = -lim;
        }
        speed.m_x = lim;
    }
    if (((ObjView*)a->m_enumerationStart->m_workManageModule)->slot17(0x2200000A) != 0) {
        float g = soValueAccesser::getConstantFloat(a, 0xD7E, 0);
        float c = soValueAccesser::getConstantFloat(a, 0xBC5, 0);
        g = c * g;
        float t = speed.m_y * soValueAccesser::getConstantFloat(a, 0xC46, 0);
        speed.m_y = t + g;
    } else if (((ObjView*)a->m_enumerationStart->m_workManageModule)->slot17(0x22000006) != 0) {
        float g = soValueAccesser::getConstantFloat(a, 0xBC8, 0);
        float t = speed.m_y * soValueAccesser::getConstantFloat(a, 0xC46, 0);
        speed.m_y = t + g;
    } else {
        float g = soValueAccesser::getConstantFloat(a, 0xBC5, 0);
        float t = speed.m_y * soValueAccesser::getConstantFloat(a, 0xC46, 0);
        speed.m_y = t + g;
    }
    speed.m_y *= f31;
    EnergyView* e2 = (EnergyView*)__dynamic_cast(
        ((KineticView*)a->m_enumerationStart->m_kineticModule)->slot6(2), 0,
        lbl_27_data_2E380, lbl_27_data_CDF8, 1);
    Vec3f z1(lbl_27_rodata_7DB0, lbl_27_rodata_7DB0, lbl_27_rodata_7DB0);
    e2->slot5(0, Vec2f(speed.m_x, lbl_27_rodata_7DB0), z1, a);
    e2->unk3C = f31;
    ((unsigned char*)e2)[5] |= 0x80;
    EnergyView* e1 = (EnergyView*)__dynamic_cast(
        ((KineticView*)a->m_enumerationStart->m_kineticModule)->slot6(1), 0,
        lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    Vec3f z2(lbl_27_rodata_7DB0, lbl_27_rodata_7DB0, lbl_27_rodata_7DB0);
    e1->slot5(0, Vec2f(lbl_27_rodata_7DB0, speed.m_y), z2, a);
    ((unsigned char*)e1)[5] |= 0x80;
}
