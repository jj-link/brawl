#include <types.h>
#include <ft/fighter.h>
#include <ft/ft_owner.h>
#include <so/motion/so_motion_event_presenter.h>
#pragma force_active on
extern "C" {
extern const char lbl_121_data_8420[];
extern const char lbl_121_data_35E4[];
extern const char lbl_121_data_3474[];
extern const char lbl_121_data_3CF0[];
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
class Class_8E20 {
public:
    virtual void fn_121_22F8();
    virtual void fn_121_12B5C();
    virtual void fn_121_14840();
    virtual void* fn_121_14838(int, int, bool);
    virtual void fn_121_14830();
    virtual void fn_121_14828();
    virtual void fn_121_14820();
    virtual void fn_121_14818();
    virtual void fn_121_14810();
    virtual void fn_121_14808();
    virtual void fn_121_14800();
    virtual void fn_121_147F8();
    virtual void fn_121_147F0();
    virtual void fn_121_147E8(void*);
    virtual void fn_121_14798();
    virtual void fn_121_147E0();
    virtual void fn_121_147D0();
    virtual void fn_121_147C0();
    virtual void fn_121_147B0();
    virtual void fn_121_147A0();
    virtual int fn_121_14788(int);
};
class Obj { public: virtual int f0(); };
class Obj8 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void f8(void*, int, bool, bool);
};
extern "C" void fn_121_F79C(void*, void* accesser) {
    char* acc = (char*)accesser;
    void* modules = *(void**)(acc + 0xd8);
    WorkManage* work = (WorkManage*)*(void**)((char*)modules + 0x64);
    Class_8E20* art = (Class_8E20*)*(void**)((char*)modules + 0x84);
    int one = 1;
    int zero = 0;
    int f1 = work->isFlag(0x22000011);
    int f2 = work->isFlag(0x22000012);
    if (f1 != 0 && f2 == 0) {
        if (art->fn_121_14788(6) != 0) {
            Obj* obj = (Obj*)art->fn_121_14838(6, zero, zero);
            if (obj->f0() == 0) {
                void* casted = __dynamic_cast(obj, 0, lbl_121_data_8420, lbl_121_data_35E4, (short)one);
                art->fn_121_147E8(obj);
                Obj8* a8 = (Obj8*)*(void**)((char*)*(void**)(acc + 0xd8) + 0xa8);
                a8->f8(casted, 0, one, one);
                ((Fighter*)__dynamic_cast(*(void**)(acc + 8), 0x3c, lbl_121_data_3474, lbl_121_data_3CF0, (short)one))->getOwner()->addLogInt(1, 0x1d, 0);
            }
        }
        work->onFlag(0x22000012);
    }
}
