#pragma force_active on
class VirtualTarget {
public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19(unsigned int);
};

class TargetOwner {
public:
    void* padding[25];
    VirtualTarget* target;
};

class Captain {
public:
    void* padding[54];
    TargetOwner* owner;
};

extern "C" void fn_100_FE98(void*, int);

extern "C" void fn_100_E93C(void*, void* self) {
    Captain* captain = (Captain*)self;
    captain->owner->target->method19(0x12000019);
    fn_100_FE98(self, 0x1E);
}
