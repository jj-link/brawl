#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern const float lbl_121_rodata_64;
void fn_121_FF60(soModuleAccesser*);
}

class Class_8E20 {
public:
    virtual void fn_121_22F8();
    virtual void fn_121_12B5C();
    virtual void fn_121_14840();
    virtual void fn_121_14838();
    virtual void fn_121_14830();
    virtual void fn_121_14828();
    virtual void fn_121_14820();
    virtual void fn_121_14818();
    virtual void fn_121_14810();
    virtual void fn_121_14808();
    virtual void fn_121_14800();
    virtual void fn_121_147F8();
    virtual void fn_121_147F0();
    virtual void fn_121_147E8();
    virtual void fn_121_14798();
    virtual void fn_121_147E0();
    virtual void fn_121_147D0();
    virtual bool fn_121_147C0(unsigned int);
    virtual void fn_121_147B0(unsigned int);
    virtual void fn_121_147A0(unsigned int);
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

extern "C" void fn_121_FAE0(void*, soModuleAccesser* accesser) {
    Class_8E20* work = reinterpret_cast<Class_8E20*>(accesser->m_enumerationStart->m_workManageModule);
    if (work->fn_121_147C0(0x22000017) && !work->fn_121_147C0(0x22000018)) {
        work->fn_121_147B0(0x22000018);
        SearchData data;
        memset(&data, 0, 0x18);
        data.node = accesser->getModelModule().getCorrectNodeId(0x12c);
        data.size = soValueAccesser::getConstantFloat(accesser, 0xfac, 0);
        data.x = lbl_121_rodata_64;
        data.y = lbl_121_rodata_64;
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
    if (work->fn_121_147C0(0x22000019)) {
        work->fn_121_147A0(0x22000019);
        fn_121_FF60(accesser);
    }
}
