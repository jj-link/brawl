#include <so/so_value_accesser.h>
#pragma force_active on

class Class_7FE8 {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_1552C();
    virtual void fn_113_1C084();
    virtual void fn_113_1C07C();
    virtual int fn_113_1C074(unsigned long);
    virtual void fn_113_1C06C();
    virtual void fn_113_1C064();
    virtual void fn_113_1C05C();
    virtual void fn_113_1C054();
    virtual void fn_113_1C04C();
    virtual void fn_113_1C044();
    virtual void fn_113_1C03C();
    virtual void fn_113_1C034();
    virtual void fn_113_1C02C();
    virtual void fn_113_1BFDC();
    virtual void fn_113_1C024();
    virtual void fn_113_1C014();
    virtual unsigned long fn_113_1C004(unsigned long);
    virtual void fn_113_1BFF4();
    virtual void fn_113_1BFE4(unsigned long);
};

class EventModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void notify(int, void*);
};

struct Modules {
    char pad[0x64];
    Class_7FE8* work;
    char pad2[8];
    EventModule* event;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_113_26470(void*, void*);
extern "C" float fn_113_23CA0(void*, int);
extern "C" unsigned int fn_113_23B54(int);

extern "C" void fn_113_26C2C(void* self, Accesser* arg) {
    fn_113_26470(self, arg);
    if (arg->modules->work->fn_113_1C004(0x22000001UL) == 1UL) {
        arg->modules->work->fn_113_1BFE4(0x22000001UL);
        arg->modules->event->notify(10, arg);
    } else {
        float c = soValueAccesser::getConstantFloat((soModuleAccesser*)arg, 0xfa4, 0);
        if (fn_113_23CA0(arg, 3) >= c) {
            return;
        }
        if (fn_113_23B54(arg->modules->work->fn_113_1C074(0x10000010UL)) == 1U) {
            arg->modules->event->notify(10, arg);
        }
    }
}