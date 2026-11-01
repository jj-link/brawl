#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {

struct SonicF4C8 {
    int field0;
    float field1;
    float field2;
    unsigned char field3;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
};

void fn_123_F4C8(SonicF4C8*, int, float, float,
                 unsigned char, unsigned char, unsigned char, unsigned char);
void fn_123_F4E8(void*, soModuleAccesser*);

extern const float lbl_123_rodata_28;
extern const float lbl_123_rodata_2C;

void fn_123_F2B4(void* process, soModuleAccesser* accesser) {
    if (accesser->getSituationModule().getKind() != 0)
        return;

    accesser->getWorkManageModule().offFlag(0x22000012);

    if (accesser->getMotionModule().getKind() == 0x1D9 ||
        accesser->getMotionModule().getKind() == 0x1E4) {
        soWorkManageModule* work = &accesser->getWorkManageModule();
        float threshold = soValueAccesser::getConstantFloat(accesser, 0xFBE, 0);
        if (work->getFloat(0x21000004) > threshold) {
            SonicF4C8 param;
            fn_123_F4C8(&param, 0x1D8, lbl_123_rodata_28,
                        lbl_123_rodata_2C, 0, 0, 0, 0);
            accesser->getMotionModule().changeMotionRequest(
                reinterpret_cast<soMotionChangeParam*>(&param));
            accesser->getGroundModule().setCorrect(
                static_cast<soGroundShapeImpl::CorrectKind>(1), 0);
            fn_123_F4E8(process, accesser);
        }
    } else {
        soWorkManageModule* work = &accesser->getWorkManageModule();
        float threshold = soValueAccesser::getConstantFloat(accesser, 0xFBE, 0);
        if (work->getFloat(0x21000004) <= threshold) {
            SonicF4C8 param;
            fn_123_F4C8(&param, 0x1D9, lbl_123_rodata_28,
                        lbl_123_rodata_2C, 0, 0, 0, 0);
            accesser->getMotionModule().changeMotionRequest(
                reinterpret_cast<soMotionChangeParam*>(&param));
            fn_123_F4E8(process, accesser);
        }
    }
}

}
