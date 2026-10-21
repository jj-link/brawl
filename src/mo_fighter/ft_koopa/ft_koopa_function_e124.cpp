#pragma force_active on
struct Flags {
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char f2 : 1;
    unsigned char f3 : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
};

struct IfaceD {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual unsigned char* v6(int a);
};

extern "C" void fn_102_E124(char* self) {
    unsigned char* a = ((IfaceD*)*(char**)(*(char**)(self + 0xd8) + 0x7c))->v6(0);
    ((Flags*)(a + 5))->f0 = 0;
    unsigned char* b = ((IfaceD*)*(char**)(*(char**)(self + 0xd8) + 0x7c))->v6(1);
    ((Flags*)(b + 5))->f0 = 0;
    unsigned char* c = ((IfaceD*)*(char**)(*(char**)(self + 0xd8) + 0x7c))->v6(2);
    ((Flags*)(c + 5))->f0 = 0;
    unsigned char* d = ((IfaceD*)*(char**)(*(char**)(self + 0xd8) + 0x7c))->v6(3);
    ((Flags*)(d + 5))->f0 = 0;
}
