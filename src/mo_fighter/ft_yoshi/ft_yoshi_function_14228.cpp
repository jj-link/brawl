#pragma force_active on

struct VtFirst {
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
    virtual void call(int, int);
};

struct VtSecond {
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
    virtual void call(int);
};

struct VtThird {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void call(int);
};

struct Inner {
    char pad[0x8];
    VtSecond* second;
    char pad2[0x4C];
    VtThird* third;
    char pad3[0x28];
    VtFirst* first;
};

struct Owner {
    char pad[0xD8];
    Inner* inner;
};

extern "C" void fn_95_14228(void* unused, Owner* owner, int state) {
    if (state == 0x116) return;
    if (state == 0x120) return;
    if (state == 0x121) return;
    if (state == 0x122) return;
    if (state == 0x123) return;
    if (state == 0x124) return;
    owner->inner->first->call(2, 0);
    owner->inner->second->call(0);
    owner->inner->third->call(1);
}