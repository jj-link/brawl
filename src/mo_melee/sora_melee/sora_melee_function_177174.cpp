#pragma force_active on
struct Query {
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
    virtual int get();
};

struct Modules {
    char pad[0x70];
    Query* query;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_174C08(int, void*, void*);
extern "C" void fn_27_177608(int, void*, void*);
extern "C" void fn_27_177B30(int, void*, void*);
extern "C" void fn_27_177C80(int, void*, void*);
extern "C" void fn_27_177E80(int, void*, void*);

extern "C" void fn_27_177174(int arg0, Owner* arg1) {
    int buf[12];
    buf[0] = 0x14;
    buf[1] = 0;
    fn_27_174C08(arg0, buf, arg1);
    int r = arg1->modules->query->get();
    switch (r) {
    case 0x92:
        fn_27_177B30(arg0, arg1, buf);
        return;
    case 0x93:
        fn_27_177C80(arg0, arg1, buf);
        return;
    case 0x94:
        fn_27_177608(arg0, arg1, buf);
        return;
    case 0x95:
        fn_27_177E80(arg0, arg1, buf);
        return;
    }
}
