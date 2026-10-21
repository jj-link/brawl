#pragma force_active on
struct Flags {
    char pad[5];
    unsigned char f0 : 1;
    unsigned char rest : 7;
};

class Iface {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Flags* v8(int a);
};

extern "C" void fn_94_F574(char* self) {
    Flags* p;
    p = (*(Iface**)(*(char**)(self + 0xd8) + 0x7c))->v8(0);
    p->f0 = 0;
    p = (*(Iface**)(*(char**)(self + 0xd8) + 0x7c))->v8(1);
    p->f0 = 0;
    p = (*(Iface**)(*(char**)(self + 0xd8) + 0x7c))->v8(2);
    p->f0 = 0;
    p = (*(Iface**)(*(char**)(self + 0xd8) + 0x7c))->v8(3);
    p->f0 = 0;
}
