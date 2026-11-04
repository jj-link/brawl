#pragma fp_contract off
#include <so/so_value_accesser.h>
#include <math.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_2208;
extern "C" float fn_27_1935B4(soModuleAccesser*, float);

extern "C" void fn_27_16F8F0(void*, soModuleAccesser* a) {
    const float* c = &lbl_27_rodata_2208;
    switch (a->getStatusModule().getStatusKind()) {
    case 0x68:
    case 0x69: {
        float lr = a->getPostureModule().getLr();
        float value = fn_27_1935B4(a, lr);
        a->getWorkManageModule().setFloat(value, 0x21000004);
        float first = c[2];
        float second = c[0];
        Vec2f normal(second, first);
        if (first == lr)
            normal = a->getGroundModule().getTouchNormal((grCollStatus::TouchMask)2, 0);
        else
            normal = a->getGroundModule().getTouchNormal((grCollStatus::TouchMask)4, 0);
        float y = normal.m_y;
        float angle = c[6] + c[7] * (-lr * (float)atan2(normal.m_x, y));
        if (angle >= soValueAccesser::getConstantFloat(a, 0xc9c, 0) ||
            angle <= soValueAccesser::getConstantFloat(a, 0xc9d, 0))
            a->getStatusModule().changeStatusRequest(0xe, a);
        break;
    }
    case 0x62:
    case 0x63:
    case 0x67:
        if (c[0] == a->getMotionModule().getRate()) {
            float value = fn_27_1935B4(a, a->getPostureModule().getLr());
            a->getWorkManageModule().setFloat(value, 0x21000004);
        }
        break;
    }
}