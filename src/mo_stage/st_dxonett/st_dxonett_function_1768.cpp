#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_78_rodata_58;

typedef void (*Method)(void*);
extern "C" Method lbl_78_data_9E0[];

struct Object {
    unsigned char pad0[0x3C];
    Method* vtable;
    unsigned char pad40[0x110];
    unsigned char flag;
    unsigned char pad151[3];
    float value;
    unsigned int state;
};

class Dispatch {
public:
    unsigned char pad[0x3C];
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
};

extern "C" Object* fn_78_1768(Object* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->vtable = lbl_78_data_9E0;
    self->flag = 0;
    self->value = lbl_78_rodata_58;
    self->state = 0;
    ((Dispatch*)self)->method26();
    return self;
}
