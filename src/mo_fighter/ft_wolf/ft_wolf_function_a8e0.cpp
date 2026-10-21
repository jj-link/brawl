#pragma force_active on
extern "C" void fn_27_135CE8(void* self, int a, float b, int c, int d, float e, float f, int g);

struct Obj {
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void n5();
    virtual void n6();
    virtual void n7();
    virtual void n8();
    virtual void n9();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual float n26(int);
};

struct Mid {
    unsigned char pad[0x28];
    Obj* obj;
};

struct Outer {
    unsigned char pad[0xd8];
    Mid* mid;
};

struct Self {
    unsigned char pad[0x60];
    Outer* outer;
};

extern "C" void fn_125_A8E0(void* self, int arg1, float farg0, int arg2, int arg3, float farg1, float farg2, int arg4) {
    if (arg3 == 2) {
        Obj* obj = ((Self*)self)->outer->mid->obj;
        float result = obj->n26(arg3);
        if (farg0 >= result) {
            *(unsigned char*)((char*)self + 0x1CC89) = 1;
            return;
        }
        *(unsigned char*)((char*)self + 0x1CC88) = 1;
    }
    fn_27_135CE8(self, arg1, farg0, arg2, arg3, farg1, farg2, arg4);
}
