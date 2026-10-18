#include <so/so_module_accesser.h>
#pragma force_active on

struct PikachuVerticalRangeStorage {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

struct WorkX {
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void setFloat(float, unsigned) = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void onFlag(unsigned) = 0;
};

extern "C" {
void* fn_98_14878(void*);
void fn_98_14A18(void*, float);

void fn_98_14A18(void* storage, float value) {
    soWorkManageModule* work = &static_cast<PikachuVerticalRangeStorage*>(storage)->accesser->getWorkManageModule();
    WorkX* wk = reinterpret_cast<WorkX*>(work);
    wk->onFlag(0x12000003);
    wk->setFloat(value, 0x11000003);
    void* next = fn_98_14878(storage);
    if (next) {
        fn_98_14A18(next, value);
    }
}
}
