#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

class GroundPad {
    u32 pad[2];
};

class GroundCall : public GroundPad {
public:
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26(u8, u32);
};

extern "C" void fn_27_195788(soModuleAccesser* accesser) {
    float threshold = soValueAccesser::getConstantFloat(accesser, 0xcdb, 0);
    float y = accesser->m_enumerationStart->m_kineticModule->getEnergy(4)->getSpeed().m_y;
    if ((float)(double)nw4r::math::FAbs(y) > threshold) {
        reinterpret_cast<GroundCall*>(accesser->m_enumerationStart->m_groundModule)->v26(1, 0);
    } else {
        reinterpret_cast<GroundCall*>(accesser->m_enumerationStart->m_groundModule)->v26(0, 0);
    }
}