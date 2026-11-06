#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern const float lbl_27_rodata_64C4;

class Object_vptr_3c_base { public: char pad[0x3c]; };

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
    char pad_40[0x20];
    soModuleAccesser* m_moduleAccesser;
};

extern "C" void fn_27_2F210C(Object_vptr_3c* self, float farg) {
    Vec3f tmp;
    tmp.m_x = lbl_27_rodata_64C4;
    tmp.m_y = lbl_27_rodata_64C4;
    tmp.m_z = lbl_27_rodata_64C4;
    Vec3f pos = self->m_moduleAccesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0, &tmp, false, false);
    pos.m_z = self->m_moduleAccesser->m_enumerationStart->m_groundModule->getZ();
    self->m_moduleAccesser->m_enumerationStart->m_postureModule->init(&pos, farg);
    self->m_moduleAccesser->m_enumerationStart->m_linkModule->removeModelConstraint(true);
    self->m_moduleAccesser->m_enumerationStart->m_statusModule->changeStatusRequest(1, self->m_moduleAccesser);
    self->slot43();
}
