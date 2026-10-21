#pragma force_active on
extern "C" int fn_27_68140(float, float, float, float, float);
extern "C" float lbl_109_rodata_30[];

class Ifc {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16(int, int);
    virtual void f17();
    virtual void f18(int);
};

extern "C" void fn_109_11430(void*, char* obj, int, char* fighter) {
    float* k = lbl_109_rodata_30;
    Ifc* a = (Ifc*)(*(char**)(*(char**)(fighter + 0xd8) + 0x44));
    if (*(float*)(obj + 0xc) > k[6]) {
        if (a->f9() == 0) {
            int r = fn_27_68140(*(float*)(obj + 8), k[8], k[9], k[3], k[10]);
            ((Ifc*)(*(char**)(*(char**)(fighter + 0xd8) + 0x44)))->f16(r, 1);
            ((Ifc*)(*(char**)(*(char**)(fighter + 0xd8) + 0x64)))->f18(0x12000005);
        }
    }
}
