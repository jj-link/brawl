#include <so/so_module_accesser.h>
#pragma force_active on

struct KoopaData {
    int first;
    unsigned char flag;
    unsigned char padding[3];
    int second;
    int value0;
    int value1;
    int value2;
    float scalar;
    unsigned char last;
};

extern "C" void fn_102_E384(KoopaData*, int, int, unsigned char);

class CatchModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void release(int);
};

extern "C" void fn_102_17C0C(void*, soModuleAccesser* accesser, int statusKind)
{
    if (statusKind != 0x120) {
        if (accesser->getWorkManageModule().isFlag(0x22000011)) {
            CatchModule* catchModule =
                static_cast<CatchModule*>(accesser->m_enumerationStart->m_catchModule);
            catchModule->release(0);
            accesser->getWorkManageModule().onFlag(0x1200003E);

            KoopaData data;
            fn_102_E384(&data, 0x26, -1, 1);
            accesser->getLinkModule().sendEventNodes(
                0, reinterpret_cast<soLinkEventArgs&>(data), 0);

            accesser->getWorkManageModule().offFlag(0x22000011);
            accesser->getWorkManageModule().offFlag(0x12000001);
        }
    }
}
