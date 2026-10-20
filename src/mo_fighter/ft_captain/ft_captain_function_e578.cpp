#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_100_rodata_30;
extern const float lbl_100_rodata_34;
Vec3f* fn_100_CC84(Vec3f*, float, float, float);
void fn_100_FE98(void*, int);
void fn_100_10C78(int);
void fn_100_1070C();
void fn_100_10CEC(int);
}

class CaptainStage {
    unsigned char padding[0x3C];

public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void update();
};

extern "C" void fn_100_E578(void*, soModuleAccesser* accesser) {
    soPostureModule* posture = &accesser->getPostureModule();
    accesser->getWorkManageModule().offFlag(0x12000019);

    Vec3f position;
    posture->setPos(fn_100_CC84(
        &position, lbl_100_rodata_30, lbl_100_rodata_34, lbl_100_rodata_30));
    posture->setLr(lbl_100_rodata_30);

    Vec3f rotation;
    posture->setRot(fn_100_CC84(
        &rotation, lbl_100_rodata_30, lbl_100_rodata_30, lbl_100_rodata_30), 0);

    CaptainStage* stage =
        reinterpret_cast<CaptainStage*>(&accesser->getStageObject());
    stage->update();

    fn_100_FE98(accesser, 10);
    fn_100_10C78(0);
    fn_100_1070C();
    fn_100_10CEC(1);
}
