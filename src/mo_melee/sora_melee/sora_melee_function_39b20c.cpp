#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_39F2B0(int, float, float, float);
int fn_27_39FA04(void*);
void fn_27_39B854(void*, int);
extern char lbl_27_data_9B6C0[];
extern char lbl_27_data_C938[];
}

class Obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int, int);
    virtual int s6();
    virtual void s7();
    virtual void s8();
    virtual float s9();
    virtual void s10();
    virtual void s11();
    virtual float s12(int);
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual float s22();
};

extern "C" int fn_27_39B20C(void* unused, Obj* obj, char* self) {
    float f31, f30;
    switch (obj->s6()) {
    case 0xd:
    {
        Obj* p = (Obj*)__dynamic_cast(
            obj, 0, lbl_27_data_9B6C0, lbl_27_data_C938, 0);
        if (p != 0) {
            f30 = (*(Obj**)(*(char**)(self + 0xD8) + 0xC))->s9();
            f31 = (*(Obj**)(*(char**)(self + 0xD8) + 0xC))->s22();
            float f2 = (*(Obj**)(*(char**)(self + 0xD8) + 0x64))->s12(0x11000013);
            fn_27_39F2B0((int)p, f30, f2, f31);
            fn_27_39B854(self, fn_27_39FA04(p));
            (*(Obj**)(*(char**)(self + 0xD8) + 0x64))->s5(7, 0x10000042);
            return 0;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}
