#include <so/so_module_accesser.h>
#pragma force_active on

class CaptureModule {
public:
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual unsigned int getState();
    virtual void slot24();
    virtual void slot28();
    virtual void setState(unsigned int, int);
    virtual void slot30();
    virtual void reset();
};

struct Self {
    char pad[0x1b4];
    soModuleEnumeration* modules;
};

extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned int, unsigned int);
extern "C" void fn_41_4C20(Self*, Vec3f*);

extern "C" void fn_41_4EB8(Self* self) {
    if (((CaptureModule*)self->modules->m_catchModule)->getState() == 1U) {
        soModelModule* model;
        unsigned int state = self->modules->m_linkModule->isModelConstraint();
        model = self->modules->m_modelModule;

        Vec3f position = model->getNodeGlobalPosition(
            getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
                (char*)self + 0xdc, 0x59e6, 0),
            false);

        if (state == 1U) {
            ((CaptureModule*)self->modules->m_catchModule)->reset();
        }

        ((CaptureModule*)self->modules->m_catchModule)->setState(state, 0);

        if (state == 1U) {
            fn_41_4C20(self, &position);
        }
    }
}
