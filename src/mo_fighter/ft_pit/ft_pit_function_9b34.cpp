#include <so/so_value_accesser.h>
#pragma force_active on

struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(float, unsigned long);
};
struct Stop {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void set(float, int);
};
struct Shield {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void action(int, int, bool);
};
struct Fighter { char pad[0x60]; soModuleAccesser* accesser; };
extern "C" const float lbl_112_rodata_8;
extern "C" void fn_27_1963F0(soModuleAccesser*, float, float);
extern "C" int fn_27_135A70(Fighter*);

extern "C" int fn_112_9B34(Fighter* self) {
    float value = ((Work*)self->accesser->m_enumerationStart->m_workManageModule)->getFloat(0x11000015);
    if (value > lbl_112_rodata_8) {
        soValueAccesser::getConstantFloat(self->accesser, 0xfbd, 0);
        ((Stop*)self->accesser->m_enumerationStart->m_stopModule)->set((float)(int)value, 0);
        soModuleAccesser* accesser = self->accesser;
        fn_27_1963F0(accesser, value, ((Work*)accesser->m_enumerationStart->m_workManageModule)->getFloat(0x11000016));
        float remaining = ((Work*)self->accesser->m_enumerationStart->m_workManageModule)->getFloat(0x11000014) - value;
        if (remaining < lbl_112_rodata_8) {
            ((Shield*)self->accesser->m_enumerationStart->m_collisionShieldModule)->action(0, 0, true);
            remaining = lbl_112_rodata_8;
        }
        ((Work*)self->accesser->m_enumerationStart->m_workManageModule)->setFloat(remaining, 0x11000014);
        return 0;
    }
    return fn_27_135A70(self);
}