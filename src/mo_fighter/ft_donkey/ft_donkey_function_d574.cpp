#pragma force_active on
struct Prefix {
    char pad[8];
};

class Inner : public Prefix {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void target(int, float, float);
};

struct Middle {
    char pad[0x38];
    Inner *inner;
};

struct Fighter {
    char pad[0xD8];
    Middle *middle;
};

extern float lbl_92_rodata_1C;

extern "C" void fn_92_D574(void *unused, Fighter *fighter)
{
    Inner *object = fighter->middle->inner;
    object->target(0, lbl_92_rodata_1C, lbl_92_rodata_1C);
}
