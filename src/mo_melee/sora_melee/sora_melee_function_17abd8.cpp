#pragma force_active on
typedef unsigned int u32;

extern "C" float lbl_27_rodata_2360[3];

class Status {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int get();
};

class Work {
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
    virtual void set(float, u32);
};

class Motion {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void set(float);
};

struct Modules {
    char pad0[8];
    Motion* motion;
    char pad1[0x58];
    Work* work;
    char pad2[8];
    Status* status;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Owner*, u32, u32);
extern "C" void fn_27_194390(Owner*, float*, float);
extern "C" float fn_27_194B34(Owner*);

extern "C" void fn_27_17ABD8(void*, Owner* owner) {
    float* constants = lbl_27_rodata_2360;
    switch (owner->modules->status->get()) {
    case 0x9a: break;
    default: return;
    }
    float vals[2];
    fn_27_194390(owner, &vals[0], getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(owner, 0xd77, 0));
    float rate = vals[0];
    if (rate <= constants[0]) vals[0] = constants[1];
    if (vals[0] < constants[2]) { vals[0] = constants[2]; rate = vals[0]; }
    owner->modules->work->set(rate, 0x21000004);
    Motion* motion = owner->modules->motion;
    motion->set(vals[0] * fn_27_194B34(owner));
}
