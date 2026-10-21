#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/link/so_link_module_impl.h>
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

class KoopaCatchModule {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void release(int);
};

extern "C" void fn_102_E384(KoopaData*, int, int, unsigned char);

extern "C" void fn_102_E920(void*, soModuleAccesser* accesser, int statusKind) {
    if (statusKind != 0x120) {
        if (accesser->getWorkManageModule().isFlag(0x22000011)) {
            static_cast<KoopaCatchModule*>(
                accesser->m_enumerationStart->m_catchModule)->release(0);
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
