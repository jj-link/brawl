#pragma force_active on

struct Buf {
    float x, y, v;
    Buf(const Buf& b) : x(b.x), y(b.y), v(b.v) {}
};

struct Obj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Buf get();
    virtual void set(const Buf&);
};

struct B {
    char pad[0xC];
    Obj* o;
};

struct A {
    char pad[0xD8];
    B* b;
};

struct Prefix {
    char pad[0x3C];
};

struct Item : Prefix {
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
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void update();

    char pad1[0x20];
    A* a;
};

extern "C" float getParamFloat__8BaseItemFUl(void*, unsigned long);
extern "C" float lbl_27_rodata_479C;

extern "C" int fn_27_29F7D4(void* unused, Item* self) {
    float f = getParamFloat__8BaseItemFUl(self, 0x403);
    if (f > lbl_27_rodata_479C) {
        Obj* o = self->a->b->o;
        Buf buf = o->get();
        if (buf.v < f) {
            buf.v = f;
        }
        o->set(buf);
        self->update();
    }
    return 1;
}
