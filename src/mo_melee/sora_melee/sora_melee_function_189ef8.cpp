#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct CaptureModule {
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
};

extern float lbl_27_rodata_2520;
extern float lbl_27_rodata_2524;

extern "C" void fn_27_189EF8(void*, soModuleAccesser* accesser) {
    ((CaptureModule*)accesser->m_enumerationStart->m_captureModule)->v13();

    soMotionModule* motion = accesser->m_enumerationStart->m_motionModule;
    int offset = 0;
    motion->setShareAnimObjKind(0x1CB);

    switch (soValueAccesser::getConstantInt(accesser, 0x5A98, 0)) {
    case 1:
        offset = 1;
        break;
    }

    motion->setKindOffset(offset);

    soMotionChangeParam param;
    param.m_kind = 0x1BA;
    param.m_frame = lbl_27_rodata_2520;
    param.m_rate = lbl_27_rodata_2524;
    param._12 = 0;
    param._13 = 1;
    param._14 = 0;
    param._15 = 0;
    motion->changeMotionRequest(&param);
}
