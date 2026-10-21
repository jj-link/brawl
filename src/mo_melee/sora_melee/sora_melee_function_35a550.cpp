#pragma force_active on

extern "C" void fn_27_35F540(void*, int, int);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_8F788[];
extern "C" char lbl_27_data_C938[];

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int kind();
};

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

extern "C" int fn_27_35A550(void*, Obj* obj, char* ctx) {
    if (obj->kind() == 14) {
        Svc* a;
        int x;
        Svc* b;
        void* p = __dynamic_cast(obj, 0, lbl_27_data_8F788, lbl_27_data_C938, 0);
        char* t = *(char**)(ctx + 0xD8);
        a = *(Svc**)(t + 0x64);
        b = *(Svc**)(t + 0xC);
        x = a->s6(0x20000000);
        int y = a->s19(0x22000011);
        b->s11();
        fn_27_35F540(p, y, x);
        return 0;
    }
    return 0;
}
