#include <types.h>
#include <so/so_array_vector_calculator.h>
#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_20950[], lbl_27_data_1D4E8[], lbl_27_data_3C578[];
extern char lbl_27_data_8E80[], lbl_27_data_35338[], lbl_27_data_3ED00[], lbl_27_data_8110C[];
extern unsigned char __vt__19soGeneralWorkSimple[];
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_73930(void*, int, void*, void*, void*, void*, void*, int, int, int);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual bool slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(const void*);
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
    virtual bool slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual int slot27();
    virtual int slot28();
    void* calc;
    unsigned int flags;
};

struct WorkBase {
    void* vtable0;
    u8 flag;
    char pad[3];
};

class Work : public WorkBase {
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
};

struct WorkStorage {
    s32 ints[2];
    float floats[2];
    u32 flags;
    soGeneralWorkSimple work;
};

struct Object {
    void* vtable;
    s32 zero;
    s32 status;
    s32 enabled;
    WorkStorage storage;
    char other[0x64];
    void* vt;
    void* vt2;
    u32 fl;
    char pad2[0x24];
    Object_vptr_0* arrayPtr;
    Object_vptr_0 array;
    char impl[0x10];
};

extern "C" Object* fn_27_2FD824(Object* self, s32 arg1, s32 arg2, s32 arg3) {
    self->zero = 0;
    self->vtable = lbl_27_data_20950;
    self->status = arg2;
    self->enabled = 9;
    if (!arg2) self->enabled = 0;

    WorkStorage* st = &self->storage;
    soGeneralWorkSimple* w = &st->work;
    *(u8*)((char*)w + 4) = 0;
    *(void**)((char*)w + 8) = __vt__19soGeneralWorkSimple;
    *(void**)w = __vt__19soGeneralWorkSimple + 8;
    w->m_intWorks = st->ints;
    w->m_intWorkSize = 2;
    w->m_floatWorks = st->floats;
    w->m_floatWorkSize = 2;
    w->m_flagWorks = &st->flags;
    w->m_flagWorkSize = 1;
    ((Work*)w)->f25();

    int x;
    char* p = (char*)self + 0x48;
    *(void**)p = lbl_27_data_1D4E8;
    *(void**)(p + 4) = lbl_27_data_1D4E8 + 0x48;
    *(u32*)(p + 8) &= 0x01ffffff;
    __construct_array(p + 0x0c, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);
    *(void**)(p + 0x20) = lbl_27_data_3C578;
    *(void**)(p + 0x24) = lbl_27_data_3C578 + 0x48;
    *(u32*)(p + 0x28) &= 0x003fffff;
    __construct_array(p + 0x2c, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 2);
    *(void**)(p + 0x4c) = lbl_27_data_8E80;
    *(void**)(p + 0x50) = p;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x58) = -1;
    *(s32*)(p + 0x5c) = -1;
    *(s32*)(p + 0x60) = 0;

    char temp[0x14];
    for (s32 i = 0; i < 1; ++i) {
        fn_27_AB15C(temp, i == 0 ? p + 0x20 : 0);
        ((Object_vptr_0*)p)->slot10(temp);
        fn_27_AB18C(temp, -1);
    }

    self->vt = lbl_27_data_35338;
    self->vt2 = lbl_27_data_35338 + 0x48;
    self->fl &= 0xFFFF;
    Object_vptr_0* a = &self->array;
    self->arrayPtr = a;
    *(void**)a = lbl_27_data_3ED00;
    a->calc = lbl_27_data_3ED00 + 0x48;
    a->flags &= 0x01FFFFFF;
    x = a->slot28();
    int n = soArrayVectorCalculator::resize(
        *(soArrayVectorCalcInterface*)&a->calc, 1,
        a->slot4(), a->slot14(), a->slot13(), a->slot27(), x);
    int i = 0;
    for (; i < n; i++) a->slot10((const void*)lbl_27_data_8110C);
    self->array.slot13();
    fn_27_73930((char*)self + 0xF0, arg1, self, (char*)self + 0xAC,
                (char*)self + 0x24, (char*)self + 0x94, (char*)self + 0xDC, arg3, 0, 1);
    return self;
}