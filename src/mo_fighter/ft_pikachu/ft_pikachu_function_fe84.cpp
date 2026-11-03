#pragma force_active on
extern "C" void fn_98_FE84(void*, void* self);

class Class_8424 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual int m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13(float, int);
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18(int);
};

struct Params {
    char pad[0x50];
    float v50;
    float v54;
};
struct View {
    int a;
    int b;
    const Params* parameters;
};

extern "C" {
extern const char lbl_98_data_600[], lbl_98_data_2F88[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
View* fn_98_9530(void*);
}

extern "C" void fn_98_FE84(void*, void* self) {
    char* a = (char*)self;
    Class_8424* situation = *(Class_8424**)(*(char**)(a + 0xD8) + 0x14);
    if (situation->m3() == 2) {
        void* stageObject = *(void**)(a + 0x8);
        const Params* parameters = fn_98_9530(__dynamic_cast(stageObject, 0x3c, lbl_98_data_600, lbl_98_data_2F88, 1))->parameters;
        (*(Class_8424**)(*(char**)(a + 0xD8) + 0x64))->m13(parameters->v54, 0x11000000);
        (*(Class_8424**)(*(char**)(a + 0xD8) + 0x64))->m13(parameters->v50, 0x11000001);
        (*(Class_8424**)(*(char**)(a + 0xD8) + 0x64))->m18(0x12000003);
    }
}