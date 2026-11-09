#include <types.h>
#include <ft/fighter.h>
#include <ft/ft_owner.h>
#include <so/motion/so_motion_event_presenter.h>
#pragma force_active on
extern "C" {
extern const char lbl_93_data_8318[];
extern const char lbl_93_data_34EC[];
extern const char lbl_93_data_337C[];
extern const char lbl_93_data_3BF8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
class WorkManage {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual int isFlag(int);
    virtual void onFlag(int);
};
class Class_8D00 {
public:
    virtual void fn_93_22F8();
    virtual void fn_93_12B10();
    virtual void fn_93_147F4();
    virtual void* fn_93_147EC(int, int, bool);
    virtual void fn_93_147E4();
    virtual void fn_93_147DC();
    virtual void fn_93_147D4();
    virtual void fn_93_147CC();
    virtual void fn_93_147C4();
    virtual void fn_93_147BC();
    virtual void fn_93_147B4();
    virtual void fn_93_147AC();
    virtual void fn_93_147A4();
    virtual void fn_93_1479C(void*);
    virtual void fn_93_1474C();
    virtual void fn_93_14794();
    virtual void fn_93_14784();
    virtual void fn_93_14774();
    virtual void fn_93_14764();
    virtual void fn_93_14754();
    virtual int fn_93_1473C(int);
};
class Obj { public: virtual int f0(); };
class Obj8 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void f8(void*, int, bool, bool);
};
extern "C" void fn_93_F750(void*, void* accesser) {
    char* acc = (char*)accesser;
    void* modules = *(void**)(acc + 0xd8);
    WorkManage* work = (WorkManage*)*(void**)((char*)modules + 0x64);
    Class_8D00* art = (Class_8D00*)*(void**)((char*)modules + 0x84);
    int one = 1;
    int zero = 0;
    int f1 = work->isFlag(0x22000011);
    int f2 = work->isFlag(0x22000012);
    if (f1 != 0 && f2 == 0) {
        if (art->fn_93_1473C(6) != 0) {
            Obj* obj = (Obj*)art->fn_93_147EC(6, zero, zero);
            if (obj->f0() == 0) {
                void* casted = __dynamic_cast(obj, 0, lbl_93_data_8318, lbl_93_data_34EC, (short)one);
                art->fn_93_1479C(obj);
                Obj8* a8 = (Obj8*)*(void**)((char*)*(void**)(acc + 0xd8) + 0xa8);
                a8->f8(casted, 0, one, one);
                ((Fighter*)__dynamic_cast(*(void**)(acc + 8), 0x3c, lbl_93_data_337C, lbl_93_data_3BF8, (short)one))->getOwner()->addLogInt(1, 0x1d, 0);
            }
        }
        work->onFlag(0x22000012);
    }
}