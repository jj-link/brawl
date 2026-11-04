#include <so/so_module_accesser.h>
#pragma force_active on

#define DUMMY(n) virtual void d##n();

struct PikachuVerticalRangeStorage {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

class WorkModule {
public:
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3)
    virtual int getInt(unsigned int index);
    virtual void setInt(int value, unsigned int index);
    DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9) DUMMY(10) DUMMY(11)
    virtual float getFloat(unsigned int index);
    DUMMY(13) DUMMY(14) DUMMY(15) DUMMY(16)
    virtual int isFlag(unsigned int index);
};

class Class_8424 {
public:
    virtual void fn_98_744C();
    virtual void fn_98_139F0();
    virtual void fn_98_14EE4();
    virtual void fn_98_14EDC();
    virtual void fn_98_14ED4();
    virtual void fn_98_14ECC();
    virtual void fn_98_14EC4();
    virtual void fn_98_14EBC();
    virtual void fn_98_14EB4();
    virtual void fn_98_14EAC();
    virtual void fn_98_14EA4();
    virtual void fn_98_14E9C();
    virtual void fn_98_14E94();
    virtual void fn_98_14E8C();
    virtual void fn_98_14E3C();
    virtual void fn_98_14E84();
    virtual void fn_98_14E74();
    virtual void fn_98_14E64();
    virtual void fn_98_14E54();
    virtual void fn_98_14E44();
    virtual void fn_98_14E2C(int value);
};

extern "C" {
void fn_98_14A18(void* storage, float value);

void fn_98_14774(void* arg0, void* arg1) {
    PikachuVerticalRangeStorage* storage = static_cast<PikachuVerticalRangeStorage*>(arg0);
    soModuleAccesser* accesser = storage->accesser;
    WorkModule* work = reinterpret_cast<WorkModule*>(accesser->m_enumerationStart->m_workManageModule);

    int value = work->getInt(0x1000000B);
    Class_8424* sub = reinterpret_cast<Class_8424*>(accesser->m_enumerationStart->m_effectModule);
    sub->fn_98_14E2C(value);

    work->setInt(0, 0x1000000B);
    int flag = work->isFlag(0x12000003);
    if (arg1 != 0 && flag != 0) {
        fn_98_14A18(arg1, work->getFloat(0x11000003));
    }
}
}
