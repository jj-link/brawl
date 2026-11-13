#pragma force_active on
#include <so/so_array_vector_calculator.h>

extern "C" {
extern char lbl_27_data_20950[];
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_3EF48[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_3EDE8[];
extern char lbl_27_data_3ED00[];
extern char lbl_27_data_9B01C[];
extern unsigned char __vt__19soGeneralWorkSimple[];

void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_73930(void*, int, void*, void*, void*, void*, void*, int, int, int);
}

struct WorkBase {
    void* vtable0;
    unsigned char flag;
    char pad[3];
};

struct Work : WorkBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();

    void* owner;
    int count1;
    void* data1;
    int count2;
    void* data2;
    int count3;
};

struct ArrayV {
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual bool v4();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void v10(const void*);
    virtual void s13();
    virtual void s14();
    virtual int v13();
    virtual bool v14();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual int v27();
    virtual int v28();
    void* calc;
    unsigned int flags;
};

struct Obj {
    char pad[0xfc];
    ArrayV* arrayPtr;
    ArrayV array;
};

extern "C" void* fn_27_398FD4(Obj* o, int arg1, int arg2, int arg3) {
    int x;
    char* self = (char*)o;
    *(int*)(self + 4) = 0;
    *(void**)self = lbl_27_data_20950;
    *(int*)(self + 8) = arg2;
    *(int*)(self + 0xc) = 1;
    if (arg2 == 0) {
        *(int*)(self + 0xc) = 0;
    }

    char* st = self + 0x10;
    Work* w = (Work*)(st + 0x14);
    w->flag = 0;
    *(void**)((char*)w + 8) = __vt__19soGeneralWorkSimple;
    w->vtable0 = __vt__19soGeneralWorkSimple + 8;
    w->owner = st;
    w->count1 = 1;
    w->data1 = st + 4;
    w->count2 = 3;
    w->data2 = st + 0x10;
    w->count3 = 1;
    w->f25();

    char* p = self + 0x48;
    *(void**)p = lbl_27_data_1D4E8;
    *(void**)(p + 4) = lbl_27_data_1D4E8 + 0x48;
    *(unsigned int*)(p + 8) &= 0x01ffffff;
    __construct_array(p + 0xc, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);

    *(void**)(p + 0x20) = lbl_27_data_3EF48;
    *(void**)(p + 0x24) = lbl_27_data_3EF48 + 0x48;
    *(unsigned int*)(p + 0x28) &= 0x0007ffff;
    __construct_array(p + 0x2c, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 6);

    *(void**)(p + 0x8c) = lbl_27_data_8E80;
    *(void**)(p + 0x90) = p;
    *(int*)(p + 0x94) = 0;
    *(int*)(p + 0x98) = -1;
    *(int*)(p + 0x9c) = -1;
    *(int*)(p + 0xa0) = 0;

    char temp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(temp, i == 0 ? p + 0x20 : 0);
        ((ArrayV*)p)->v10(temp);
        fn_27_AB18C(temp, -1);
    }

    *(void**)(self + 0xec) = lbl_27_data_3EDE8;
    *(void**)(self + 0xf0) = lbl_27_data_3EDE8 + 0x48;
    *(unsigned int*)(self + 0xf4) &= 0x01ffffff;
    ArrayV* a = &o->array;
    o->arrayPtr = a;
    *(void**)a = lbl_27_data_3ED00;
    a->calc = lbl_27_data_3ED00 + 0x48;
    a->flags &= 0x01ffffff;

    x = o->array.v28();
    int n = soArrayVectorCalculator::resize(
        *(soArrayVectorCalcInterface*)&a->calc, 1,
        a->v4(), a->v14(), a->v13(), a->v27(), x);
    int i = 0;
    for (; i < n; i++) {
        a->v10(lbl_27_data_9B01C);
    }
    o->array.v13();

    fn_27_73930(self + 0x110, arg1, self, self + 0xec, self + 0x24,
        self + 0xd4, self + 0xfc, arg3, 1, 1);
    return self;
}
