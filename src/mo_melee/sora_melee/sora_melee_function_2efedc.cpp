#include <so/so_module_accesser.h>
#pragma force_active on

extern float lbl_27_rodata_648C;
extern float lbl_27_rodata_6498;

struct Object_vptr_3c_base { char pad[0x3c]; };

class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    char pad2[0x20];
    soModuleAccesser* accesser;
};

extern "C" void fn_27_1DA868(Object_vptr_3c* self);

extern "C" void fn_27_2EFEDC(Object_vptr_3c* self, float a, float b) {
    soModuleAccesser* acc = self->accesser;
    Vec3f pos = acc->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0, false);
    pos.m_z = acc->m_enumerationStart->m_groundModule->getZ();
    pos.m_x += b * a;
    acc->m_enumerationStart->m_postureModule->init(&pos, a);
    fn_27_1DA868(self);
    soWorkManageModule* work = acc->m_enumerationStart->m_workManageModule;
    float v = a > lbl_27_rodata_648C ? lbl_27_rodata_648C : lbl_27_rodata_6498;
    work->setFloat(v, 0x11000001);
    self->slot43();
    acc->m_enumerationStart->m_statusModule->changeStatusForce(0, acc);
}
