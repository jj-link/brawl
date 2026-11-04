#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct ControllerCall {
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void startClatter(float, float, float, unsigned char, signed char, unsigned int, bool);
};

extern "C" {
extern float lbl_116_rodata_78;
extern float lbl_116_rodata_7C;
}

extern "C" void fn_116_1AFE0(void*, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x113: {
        soControllerModule& controller = accesser->getControllerModule();
        int threshold = soValueAccesser::getConstantInt(accesser, 0x5a04, 0);
        if (controller.getFlickNoResetX() < threshold)
            accesser->getWorkManageModule().onFlag(0x22000011);
        else
            accesser->getWorkManageModule().offFlag(0x22000011);
        break;
    }
    case 0x11c: {
        soMotionChangeParam param;
        param.m_kind = 0x1dd;
        param.m_frame = lbl_116_rodata_78;
        param.m_rate = lbl_116_rodata_7C;
        param._12 = 0;
        param._13 = 0;
        param._14 = 0;
        param._15 = 0;
        accesser->getMotionModule().changeMotionRequest(&param);
        float frame = accesser->getMotionModule().getEndFrame();
        reinterpret_cast<ControllerCall*>(&accesser->getControllerModule())->startClatter(frame, lbl_116_rodata_78, lbl_116_rodata_7C, 0, -1, 0, false);
        accesser->getWorkManageModule().setFloat(frame, 0x21000004);
        break;
    }
    }
}