#include <so/so_module_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int);
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
    virtual int slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int);
};

struct DiddyContext {
    char pad[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_27_13604C(void*, int, int, soModuleAccesser*);

extern "C" void fn_115_9A20(DiddyContext* self, int a, int b, soModuleAccesser* accesser) {
    if (b != 0) {
        if (((Object_vptr_0*)accesser->m_enumerationStart->m_statusModule)->slot16() != 0x125 &&
            ((Object_vptr_0*)accesser->m_enumerationStart->m_statusModule)->slot16() != 0x127) {
            ((Object_vptr_0*)self->accesser->m_enumerationStart->m_workManageModule)->slot19(0x1200003D);
            ((Object_vptr_0*)self->accesser->m_enumerationStart->m_workManageModule)->slot5(0, 0x10000040);
        }
        ((Object_vptr_0*)self->accesser->m_enumerationStart->m_workManageModule)->slot19(0x1200003E);
        ((Object_vptr_0*)self->accesser->m_enumerationStart->m_workManageModule)->slot19(0x1200003F);
    }
    fn_27_13604C(self, a, b, accesser);
}
