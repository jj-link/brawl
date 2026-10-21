#pragma force_active on
extern "C" void fn_27_35F540(int, int, int);

class Svc {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int s6(unsigned int);
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
    virtual int s19(unsigned int);
};

extern "C" int fn_27_35A64C(int arg1, int arg2, char* arg3) {
    char* t = *(char**)(arg3 + 0xD8);
    Svc* a = *(Svc**)(t + 0x64);
    int x;
    Svc* b = *(Svc**)(t + 0xC);
    x = a->s6(0x20000000);
    int y = a->s19(0x22000011);
    b->s11();
    fn_27_35F540(arg2, y, x);
    return 0;
}
