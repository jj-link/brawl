#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_27_372724(void*, void*, void*, void*);
extern char lbl_27_data_C938[];
extern char lbl_27_data_93098[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];

struct Primary {
    void* a;
    void* b;
};

struct V1 : Primary {
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4(void*);
};

struct Target {
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
    virtual void* f6();
    virtual void* f7();
    virtual void* f8();
    virtual void* f9();
    virtual void* f10();
    virtual void* f11();
    virtual void* f12();
    virtual void* f13();
    virtual void* f14();
    virtual void* f15();
    virtual void* f16();
    virtual void* f17();
    virtual void* f18();
    virtual void* f19();
    virtual void* f20();
    virtual void* f21(int);
};

extern "C" void fn_27_372668(void* arg0, void* arg1, void* arg2) {
    void* dc1 = __dynamic_cast(arg1, 0, lbl_27_data_93098, lbl_27_data_C938, 0);
    char* a = (char*)arg2 + 0xd8;
    void* ptr = *(void**)a;
    V1* obj = (V1*)*(void**)ptr;
    void* result = obj->f4(ptr);
    void* dc2 = __dynamic_cast(result, 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
    void* res2 = ((Target*)dc2)->f21(0x1e);
    fn_27_372724(arg0, dc1, arg2, res2);
}
