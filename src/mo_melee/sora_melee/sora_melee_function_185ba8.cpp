#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <mt/mt_vector.h>
#include <internal/fdlibm_public.h>
#pragma force_active on

struct GfTaskSlotsBase { char pad[0x3c]; };
class GfTaskSlots : public GfTaskSlotsBase {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void fn_27_248088();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
};

struct CaptureModuleSlots {
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
    virtual void v10(int, int);
};

class ControllerSlots {
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
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
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_24B0;
}

extern "C" void fn_27_185BA8(void* self, soModuleAccesser* acc) {
    acc->getVisibilityModule().setWhole(1);
    acc->getEffectModule().setWhole(true);
    float lr = acc->getLinkModule().getParentLr(0U);
    acc->getPostureModule().setLr(lr);
    acc->getPostureModule().updateRotYLr();
    ((GfTaskSlots*)acc->m_stageObject)->slot43();
    u32 nodeId = 0;
    Vec3f tmp = acc->getLinkModule().getParentModelNodeGlobalPosition(0U, nodeId, true);
    ((CaptureModuleSlots*)acc->m_enumerationStart->m_captureModule)->v10(1, 0);
    Vec3f pos = tmp;
    pos.m_x += lr * soValueAccesser::getConstantFloat(acc, 0xd5a, 0);
    pos.m_y += soValueAccesser::getConstantFloat(acc, 0xd5b, 0);
    acc->getPostureModule().initPos(&pos);
    float f29 = soValueAccesser::getConstantFloat(acc, 0xd5d, 0);
    float f31 = soValueAccesser::getConstantFloat(acc, 0xd5c, 0);
    Vec3f vel;
    float cosv = (float)cos(f29);
    vel.m_x = -lr * (f31 * cosv);
    float sinv = (float)sin(f29);
    vel.m_y = f31 * sinv;
    soKineticEnergy* e1 = (soKineticEnergy*)__dynamic_cast(acc->getKineticModule().getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    Vec2f v1;
    v1.m_x = vel.m_x;
    Vec3f w1;
    w1.m_x = lbl_27_rodata_24B0;
    w1.m_y = lbl_27_rodata_24B0;
    w1.m_z = lbl_27_rodata_24B0;
    v1.m_y = lbl_27_rodata_24B0;
    e1->resetEnergy(6, &v1, &w1, acc);
    reinterpret_cast<unsigned char*>(e1)[5] |= 0x80;
    soKineticEnergy* e2 = (soKineticEnergy*)__dynamic_cast(acc->getKineticModule().getEnergy(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    e2->resetEnergy(0, &Vec2f(lbl_27_rodata_24B0, vel.m_y), &Vec3f(lbl_27_rodata_24B0, lbl_27_rodata_24B0, lbl_27_rodata_24B0), acc);
    reinterpret_cast<unsigned char*>(e2)[5] |= 0x80;
    float a = soValueAccesser::getConstantFloat(acc, 0xd5e, 0);
    float b = soValueAccesser::getConstantFloat(acc, 0xd55, 0);
    float c = soValueAccesser::getConstantFloat(acc, 0xd54, 0);
    ((ControllerSlots*)acc->m_enumerationStart->m_controllerModule)->slot48(0, -1, a, b, c, 0, 0);
}
