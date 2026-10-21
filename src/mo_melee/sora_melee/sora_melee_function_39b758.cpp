#pragma force_active on

class WorkModule {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int getInt(unsigned int);
    virtual void setInt(int, unsigned int);
};

class EffectModule {
public:
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
    virtual void remove(int);
};

extern "C" void fn_27_39B758(char* self) {
    WorkModule* work = *(WorkModule**)(*(char**)(self + 0xd8) + 0x64);
    int handle = work->getInt(0x10000043);
    if (handle != 0) {
        EffectModule* effect = *(EffectModule**)(*(char**)(self + 0xd8) + 0x88);
        effect->remove(handle);
    }
    work->setInt(0, 0x10000043);

    work = *(WorkModule**)(*(char**)(self + 0xd8) + 0x64);
    handle = work->getInt(0x10000044);
    if (handle != 0) {
        EffectModule* effect = *(EffectModule**)(*(char**)(self + 0xd8) + 0x88);
        effect->remove(handle);
    }
    work->setInt(0, 0x10000044);
}
