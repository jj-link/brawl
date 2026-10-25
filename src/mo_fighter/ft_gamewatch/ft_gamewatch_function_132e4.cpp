#include <so/so_module_accesser.h>
#pragma force_active on

struct V2 { float x, y; };

extern "C" {
extern const float lbl_107_rodata_90;
extern const float lbl_107_rodata_94;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
void fn_107_14328(void*, soModuleAccesser*);
}

class Class_9E14 {
public:
    virtual void fn_107_8720();
    virtual void fn_107_16090();
    virtual void fn_107_168B4();
    virtual void fn_107_168AC();
    virtual void fn_107_168A4();
    virtual void fn_107_1689C();
    virtual void fn_107_16894();
    virtual void fn_107_1688C(float value);
    virtual void fn_107_16884();
    virtual void fn_107_1687C();
    virtual void fn_107_16874();
    virtual void fn_107_1686C();
    virtual float fn_107_16864(unsigned long index);
    virtual V2 fn_107_1685C(short* flag);
    virtual void fn_107_1680C();
    virtual void fn_107_16854();
    virtual void fn_107_16844(float value, unsigned long index);
    virtual unsigned long fn_107_16834(unsigned long index);
    virtual void fn_107_16824(unsigned long index);
    virtual void fn_107_16814(unsigned long index);
};

extern "C" void fn_107_132E4(void* owner, soModuleAccesser* accesser) {
    if (reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_workManageModule)->fn_107_16834(0x22000010) == 1) {
        float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xC39, 0);
        short flag;
        flag = 1;
        V2 speed = reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_kineticModule)->fn_107_1685C(&flag);
        float v = speed.x;
        if (reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_workManageModule)->fn_107_16834(0x22000011) == 0) {
            if ((float)fabs((double)v) >= c) {
                reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_motionModule)->fn_107_1688C(lbl_107_rodata_90);
                reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_workManageModule)->fn_107_16824(0x22000011);
            }
        } else {
            if ((float)fabs((double)v) <= c) {
                reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_motionModule)->fn_107_1688C(lbl_107_rodata_94);
                reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_workManageModule)->fn_107_16814(0x22000010);
            }
        }
    }
    if (reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_workManageModule)->fn_107_16864(0x21000006) > lbl_107_rodata_90) {
        reinterpret_cast<Class_9E14*>(accesser->m_enumerationStart->m_workManageModule)->fn_107_16844(lbl_107_rodata_94, 0x21000006);
    }
    fn_107_14328(owner, accesser);
}
