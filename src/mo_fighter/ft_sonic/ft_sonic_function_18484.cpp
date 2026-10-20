#pragma force_active on
struct Slot24Obj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual int s24();
};

struct EnergyBase {
    virtual void s0();
    virtual void s3(void* accesser);
};

class soModuleAccesser;

extern "C" void fn_123_18500(EnergyBase* energy, soModuleAccesser* accesser);

extern "C" void fn_123_18484(EnergyBase* energy, soModuleAccesser* accesser) {
    void* m = *reinterpret_cast<void**>(reinterpret_cast<char*>(accesser) + 0xd8);
    Slot24Obj* o = *reinterpret_cast<Slot24Obj**>(reinterpret_cast<char*>(m) + 0x7c);
    if (o->s24() == 0x21) {
        fn_123_18500(energy, accesser);
    } else {
        energy->s3(accesser);
    }
}
