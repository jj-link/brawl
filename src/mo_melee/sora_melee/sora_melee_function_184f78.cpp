#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, Vec2f*, Vec3f*, soModuleAccesser*);
    virtual Object_vptr_0* slot6(int);
    virtual void slot7(int);
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned long);
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26(int);
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33(int);
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48(int, int, float, float, float, int, int);
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_24A0;
}

extern "C" void fn_27_184F78(void*, soModuleAccesser* a) {
    ((Object_vptr_0*)a->m_enumerationStart->m_visibilityModule)->slot7(1);
    ((Object_vptr_0*)a->m_enumerationStart->m_effectModule)->slot33(1);
    ((Object_vptr_0*)a->m_enumerationStart->m_collisionHitModule)->slot26(0);
    float f30, f29, f28, f27, f26;
    if (((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot4(0x20000001) == 0x20 ||
        ((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot17(0x22000013)) {
        f30 = soValueAccesser::getConstantFloat(a, 0xD57, 0);
        f29 = soValueAccesser::getConstantFloat(a, 0xD55, 0);
        f28 = soValueAccesser::getConstantFloat(a, 0xD54, 0);
        f27 = soValueAccesser::getConstantFloat(a, 0xD58, 0);
        f26 = soValueAccesser::getConstantFloat(a, 0xD59, 0);
    } else if (((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot4(0x20000001) == 5) {
        f30 = soValueAccesser::getConstantFloat(a, 0xD41, 0);
        f29 = soValueAccesser::getConstantFloat(a, 0xD3E, 0);
        f28 = soValueAccesser::getConstantFloat(a, 0xD3D, 0);
        f27 = soValueAccesser::getConstantFloat(a, 0xD42, 0);
        f26 = soValueAccesser::getConstantFloat(a, 0xD43, 0);
    }
    float y = ((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot12(0x21000006);
    Vec2f saved(((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot12(0x21000005), y);
    float lr = ((Object_vptr_0*)a->m_enumerationStart->m_postureModule)->slot9();
    Vec2f speed;
    if (!((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot17(0x22000010)) {
        float stick = ((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot12(0x21000004);
        if (stick != lbl_27_rodata_24A0) {
            speed.m_x = f27 * ((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot12(0x21000004);
        } else {
            speed.m_x = f27 * -lr;
        }
        speed.m_y = f26;
    } else {
        speed.m_x = saved.m_x;
        speed.m_y = saved.m_y;
    }
    Object_vptr_0* stop = (Object_vptr_0*)__dynamic_cast(
        ((Object_vptr_0*)a->m_enumerationStart->m_kineticModule)->slot6(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    stop->slot5(6, &Vec2f(speed.m_x, lbl_27_rodata_24A0),
        &Vec3f(lbl_27_rodata_24A0, lbl_27_rodata_24A0, lbl_27_rodata_24A0), a);
    ((unsigned char*)stop)[5] |= 0x80;
    Object_vptr_0* gravity = (Object_vptr_0*)__dynamic_cast(
        ((Object_vptr_0*)a->m_enumerationStart->m_kineticModule)->slot6(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    gravity->slot5(0, &Vec2f(lbl_27_rodata_24A0, speed.m_y),
        &Vec3f(lbl_27_rodata_24A0, lbl_27_rodata_24A0, lbl_27_rodata_24A0), a);
    ((unsigned char*)gravity)[5] |= 0x80;
    ((Object_vptr_0*)a->m_enumerationStart->m_controllerModule)->slot48(0, -1, f30, f29, f28, 0, 0);
}
