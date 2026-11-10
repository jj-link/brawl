#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class CtrlView {
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
    virtual float getStickY();
};

class WorkView {
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
    virtual float getFloat(u32 index);
    virtual void setFloat(float value, u32 index);
};

struct ModelPad8 {
    u32 pad0;
    u32 pad4;
};

class ModelView : public ModelPad8 {
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
    virtual void setDispatch27(u32 id, float value);
};

extern "C" {
extern const float lbl_91_rodata_50;
}

extern "C" void fn_91_142CC(void* arg, soModuleAccesser* accesser) {
    float stick = reinterpret_cast<CtrlView*>(accesser->m_enumerationStart->m_controllerModule)->getStickY();
    float cur = soValueAccesser::getConstantFloat(accesser, 0xfa0, 0);
    if (stick >= lbl_91_rodata_50) {
        stick = cur + stick * (soValueAccesser::getConstantFloat(accesser, 0xfa1, 0) - cur);
    } else {
        float s2 = -soValueAccesser::getConstantFloat(accesser, 0xfa2, 0);
        stick = cur + (-stick) * (s2 - cur);
    }
    float value = reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->getFloat(0x21000000);
    float limit = soValueAccesser::getConstantFloat(accesser, 0xfa3, 0);
    float diff = stick - value;
    if (diff > limit) {
        diff = limit;
    } else if (diff < -limit) {
        diff = -limit;
    }
    stick = value + diff;
    reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->setFloat(stick, 0x21000000);
    reinterpret_cast<ModelView*>(accesser->m_enumerationStart->m_modelModule)->setDispatch27(5, -stick);
}
