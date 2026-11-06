#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern const float lbl_93_rodata_64;
void fn_93_FF14(soModuleAccesser*);
}

class Class_8D00 {
public:
    virtual void fn_93_22F8();
    virtual void fn_93_12B10();
    virtual void fn_93_147F4();
    virtual void fn_93_147EC();
    virtual void fn_93_147E4();
    virtual void fn_93_147DC();
    virtual void fn_93_147D4();
    virtual void fn_93_147CC();
    virtual void fn_93_147C4();
    virtual void fn_93_147BC();
    virtual void fn_93_147B4();
    virtual void fn_93_147AC();
    virtual void fn_93_147A4();
    virtual void fn_93_1479C();
    virtual void fn_93_1474C();
    virtual void fn_93_14794();
    virtual void fn_93_14784();
    virtual bool fn_93_14774(unsigned int);
    virtual void fn_93_14764(unsigned int);
    virtual void fn_93_14754(unsigned int);
};

struct SearchData {
    float x, y, z, size;
    unsigned node:9;
    unsigned kind:7;
    unsigned group:10;
    unsigned mode:3;
    unsigned flag1:1;
    unsigned flag2:1;
    unsigned flag3:1;
    unsigned a:4;
    unsigned b:4;
    unsigned c:1;
    unsigned d:17;
    unsigned e:1;
    unsigned f:1;
    unsigned g:4;
};

extern "C" void fn_93_FA94(void*, soModuleAccesser* accesser) {
    Class_8D00* work = reinterpret_cast<Class_8D00*>(accesser->m_enumerationStart->m_workManageModule);
    if (work->fn_93_14774(0x22000017) && !work->fn_93_14774(0x22000018)) {
        work->fn_93_14764(0x22000018);
        SearchData data;
        memset(&data, 0, 0x18);
        data.node = accesser->getModelModule().getCorrectNodeId(0x12c);
        data.size = soValueAccesser::getConstantFloat(accesser, 0xfac, 0);
        data.x = lbl_93_rodata_64;
        data.y = lbl_93_rodata_64;
        data.z = soValueAccesser::getConstantFloat(accesser, 0xfad, 0);
        data.kind = 2;
        data.group = 1;
        data.mode = 3;
        data.flag1 = 0;
        data.a = 9;
        data.b = 1;
        data.c = 0;
        data.e = 1;
        data.d = 0;
        data.e = 1;
        data.f = 0;
        accesser->getCollisionSearchModule().set(0, 0, reinterpret_cast<soCollisionSearchData*>(&data));
    }
    if (work->fn_93_14774(0x22000019)) {
        work->fn_93_14754(0x22000019);
        fn_93_FF14(accesser);
    }
}