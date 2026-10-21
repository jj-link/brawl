#pragma force_active on
#pragma scheduling off

typedef unsigned int u32;

extern unsigned char lbl_27_bss_7B0C[];
extern "C" int fn_27_30FACC(void*, u32, u32, void*, u32);

struct Task {
    char pad[0x3c];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual int kind();
};

struct Iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void set(int, int);
};

struct Modules {
    char pad[0x84];
    Iface* target;
};

struct Owner {
    char pad0[8];
    Task* task;
    char pad1[0xd8 - 0xc];
    Modules* modules;
};

extern "C" void fn_27_364D40(void*, Owner* obj, u32 status) {
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, obj, 1)) {
    case 0x117:
    case 0x118:
    case 0x119:
    case 0x11a:
        return;
    default:
        break;
    }

    if (obj->task->kind() == 5) {
        obj->modules->target->set(13, 0);
    } else {
        obj->modules->target->set(0, 0);
    }
}
