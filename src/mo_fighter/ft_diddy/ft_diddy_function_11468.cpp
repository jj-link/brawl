#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

class DiddySoundModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual int playSE(SndID, bool, bool, int);
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
void fn_27_89DAC(int, soModuleAccesser*);
void fn_115_12E60(void*, soModuleAccesser*);
extern const float lbl_115_rodata_C0;
extern const float lbl_115_rodata_C4;
}

extern "C" void fn_115_11468(void* process, soModuleAccesser* accesser) {
    accesser->getDamageModule().setDamageMul(
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xfcc, 0));

    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x116: {
        fn_27_89DAC(3, accesser);
        fn_27_89DAC(1, accesser);
        fn_27_89DAC(2, accesser);
        fn_27_89DAC(4, accesser);
        fn_27_89DAC(0, accesser);

        int frames = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0x5dc3, 0) * 60;
        accesser->getWorkManageModule().setInt(frames, 0x20000000);

        if (accesser->getSituationModule().getKind() == 3)
            accesser->getWorkManageModule().onFlag(0x22000017);

        accesser->getWorkManageModule().onFlag(0x22000018);
        accesser->getWorkManageModule().onFlag(0x22000019);
        accesser->getWorkManageModule().setInt(-1, 0x20000004);
        break;
    }
    case 0x12c:
        if (accesser->getWorkManageModule().getInt(0x20000004) < 0) {
            int handle = reinterpret_cast<DiddySoundModule*>(
                &accesser->getSoundModule())->playSE(
                    (SndID)0x1491, false, false, 0);
            accesser->getWorkManageModule().setInt(handle, 0x20000004);
        }
        fn_115_12E60(process, accesser);
        break;

    case 0x12e:
        if (accesser->getWorkManageModule().isFlag(0x22000013))
            accesser->getPostureModule().setLr(lbl_115_rodata_C0);
        else
            accesser->getPostureModule().setLr(lbl_115_rodata_C4);

        accesser->getPostureModule().updateRotYLr();
        accesser->getStageObject().updateNodeSRT();
        accesser->getWorkManageModule().onFlag(0x22000014);
        break;
    }

    accesser->getAreaModule().setWhole(0);
}
