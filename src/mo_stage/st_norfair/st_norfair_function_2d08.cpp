#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_54_rodata_68;

typedef void (*Method)(void*);
extern "C" Method lbl_54_data_798[];
extern "C" Method lbl_54_data_578[];

struct Object {
    unsigned char pad0[0x3C];
    Method* vtable;
    unsigned char pad40[0x110];
    unsigned char flag;
    unsigned char pad151[3];
    float value;
    unsigned int state;
    unsigned int b;
    unsigned char c;
    unsigned char pad161[3];
    float d;
    float e;
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
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42(int);
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void method73();
    virtual void method74();
    virtual void method75();
    virtual void method76();
    virtual void method77();
    virtual void method78(int);
};

extern "C" Object* fn_54_2D08(int a, int b, const char* name) {
    Object* self = (Object*)__nw__FUlQ25Heaps8HeapType(0x16c, 15);
    if (self) {
        __ct__10grYakumonoFPCc(self, name);
        self->vtable = lbl_54_data_798;
        self->flag = 0;
        self->value = lbl_54_rodata_68;
        self->state = 0;
        ((Dispatch*)self)->method26();
        self->vtable = lbl_54_data_578;
        self->b = 0;
        self->c = 2;
        self->d = lbl_54_rodata_68;
        self->e = lbl_54_rodata_68;
    }
    if (self) {
        ((Dispatch*)self)->method42(a);
        ((Dispatch*)self)->method78(b);
    }
    return self;
}