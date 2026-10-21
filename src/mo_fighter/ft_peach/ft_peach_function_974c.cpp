#pragma force_active on

struct Iface {
    virtual void f2();
    virtual void f3();
    virtual Iface* f4();
    virtual void f5();
    virtual Iface* f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual int f17();
};

struct Sec {
    int pad[2];
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual Iface* f6();
};

extern "C" void fn_103_12F24(void*, int, int, int, int);

extern "C" int fn_103_974C(void* self, char* input) {
    int teamAnother;
    int parameter;
    int resource;
    Sec* a;
    char* modules = *(char**)(input + 0xd8);
    a = *(Sec**)modules;
    resource = *(int*)(*(char**)(input + 8) + 0x28);
    Iface* b = *(Iface**)(modules + 0x18);
    parameter = (int)b->f4()->f4();
    teamAnother = a->f6()->f10();
    int team = a->f6()->f17();
    fn_103_12F24(self, resource, team, teamAnother, parameter);
    return 1;
}
