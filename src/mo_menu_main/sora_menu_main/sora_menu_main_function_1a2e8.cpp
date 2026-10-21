#include <types.h>
#pragma force_active on

class MenuWorkInterface {
public:
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
    virtual void processStep(int arg);
};

class MenuWorkInner {
public:
    char pad[0x3C];
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void destroy();
};

struct MenuTaskData {
    char pad[8];
    int c;
    int d;
};

class MenuTask {
public:
    char pad1[0x650];
    MenuTaskData* m650;
    MenuWorkInterface* m654;
    char pad2[0x71c - 0x658];
    MenuWorkInner* m71c;
};

extern "C" {
void fn_2_1A2E8(MenuTask* self) {
    self->m654->processStep(self->m650->c);
    self->m654->processStep(self->m650->d);
    if (self->m71c) {
        self->m71c->destroy();
        self->m71c = 0;
    }
}
}
