#include <so/so_module_accesser.h>
#pragma force_active on

struct WorkVt {
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
    virtual bool isFlag(u32 index);
};

struct SitVt {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setKeepAir(bool keep);
};

extern "C" void fn_95_138D8(void* unk, soModuleAccesser* accesser) {
    WorkVt* work = reinterpret_cast<WorkVt*>(&accesser->getWorkManageModule());
    if (work->isFlag(0x22000010)) {
        SitVt* situation = reinterpret_cast<SitVt*>(&accesser->getSituationModule());
        situation->setKeepAir(false);
    }
}
