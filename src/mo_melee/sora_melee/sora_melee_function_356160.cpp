#pragma force_active on
extern "C" void fn_27_3562E4(void* p);

class Sub {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
};

struct Mid {
    char pad[0x14];
    Sub* sub;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_356160(void* r3, Obj* r4) {
    if (r4->mid->sub->f3() == 2) {
        fn_27_3562E4(r4);
    }
}
