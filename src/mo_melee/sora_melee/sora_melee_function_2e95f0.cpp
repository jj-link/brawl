#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on
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
    char pad_40[0x20];
    soModuleAccesser* m_moduleAccesser;
};
extern "C" void fn_27_2E95F0(Object_vptr_3c* self, float a, float b, float c, float d) {
    Vec3f pos = self->m_moduleAccesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0, false);
    double z = self->m_moduleAccesser->m_enumerationStart->m_groundModule->getZ();
    pos.m_x += b * a;
    pos.m_y += c;
    pos.m_z = (float)z + d;
    self->m_moduleAccesser->m_enumerationStart->m_postureModule->init(&pos, a);
    self->m_moduleAccesser->m_enumerationStart->m_linkModule->removeModelConstraint(true);
    self->slot43();
}