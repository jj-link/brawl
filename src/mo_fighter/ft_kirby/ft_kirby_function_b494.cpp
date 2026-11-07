#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class Object_vptr_0 {
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
    virtual int slot15();
};
struct Pad8 { char p[8]; };
struct Mod0 : Pad8 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Object_vptr_0* s4();
};
struct Mod64 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(int);
};
extern "C" {
extern const char lbl_96_data_6024[], lbl_96_data_68D8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_96_2AB24(void*, int, int, int, int, float);
}
extern "C" int fn_96_B494(void* self, soModuleAccesser* accesser) {
    Fighter* fighter = (Fighter*)__dynamic_cast(accesser->m_stageObject, 0x3c, lbl_96_data_6024, lbl_96_data_68D8, short(1));
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    Mod64* mod64 = *(Mod64**)((char*)modules + 0x64);
    Mod0* mod0 = *(Mod0**)modules;
    int taskId = accesser->m_stageObject->m_taskId;
    float facing = modules->m_postureModule->getLr();
    int kind = mod64->s4(0x10000047);
    int owner = fn_27_111364(fighter->getOwner());
    int id = mod0->s4()->slot15();
    fn_96_2AB24(self, taskId, id, owner, kind, facing);
    return 1;
}