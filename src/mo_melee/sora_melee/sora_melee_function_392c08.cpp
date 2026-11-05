#include <new>
#include <so/so_array_vector_calculator.h>
#include <so/work/so_general_work_simple.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" char lbl_27_data_12998[];

struct GlobalObject {
    void* vtable;
    GlobalObject() {
        vtable = 0;
        vtable = lbl_27_data_12998;
    }
};

extern "C" {
extern char lbl_27_data_20950[];
extern char lbl_27_data_3ED00[];
extern unsigned char __vt__19soGeneralWorkSimple[];
extern int lbl_27_data_9A37C;
extern signed char lbl_27_bss_76B4;
extern char lbl_27_bss_88A0[];
extern char lbl_27_bss_D7C[];
extern GlobalObject lbl_27_bss_76B8;
void fn_27_82B54(void*, short);
void* __register_global_object(GlobalObject&, void*, void*);
void fn_27_73930(void*, int, void*, void*, void*, void*, void*, int, int, int);
}

static inline GlobalObject* getGlobal() {
    if (!lbl_27_bss_76B4) {
        GlobalObject* object = new (&lbl_27_bss_76B8) GlobalObject;
        __register_global_object(*object, (void*)fn_27_82B54, lbl_27_bss_88A0);
        lbl_27_bss_76B4 = 1;
    }
    return &lbl_27_bss_76B8;
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

struct Array {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(const void*);
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual bool v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual int v27();
    virtual int v28();
    void* calc;
    unsigned int flags;
};

struct WorkStorage {
    int ints[1];
    float floats[1];
    int flags;
    Work work;
};
struct Object {
    void* vtable;
    int zero;
    int status;
    int enabled;
    WorkStorage storage;
    int other;
    Array* arrayPtr;
    Array array;
    int element;
    char impl[1];
};

extern "C" Object* fn_27_392C08(Object* self, int arg1, int arg2, int arg3) {
    self->zero = 0;
    self->vtable = lbl_27_data_20950;
    self->status = arg2;
    self->enabled = 1;
    if (!arg2) {
        self->enabled = 0;
    }
    WorkStorage* st = &self->storage;
    Work* w = &st->work;
    w->flag = 0;
    *(void**)((char*)w + 8) = __vt__19soGeneralWorkSimple;
    w->vtable0 = __vt__19soGeneralWorkSimple + 8;
    w->owner = st->ints;
    w->count1 = 1;
    w->data1 = st->floats;
    w->count2 = 0;
    w->data2 = &st->flags;
    w->count3 = 1;
    w->f25();

    int x;
    Array* a = &self->array;
    self->arrayPtr = a;
    *(void**)a = lbl_27_data_3ED00;
    a->calc = lbl_27_data_3ED00 + 0x48;
    a->flags &= 0x01ffffff;
    x = a->v28();
    int n = soArrayVectorCalculator::resize(
        *(soArrayVectorCalcInterface*)&a->calc, 1, a->v4(),
        a->v14(), a->v13(), a->v27(), x
    );
    int i = 0;
    for (; i < n; i++) {
        a->v10(&lbl_27_data_9A37C);
    }
    self->array.v13();

    fn_27_73930(
        self->impl, arg1, self, getGlobal(),
        (char*)self + 0x1c, lbl_27_bss_D7C,
        &self->arrayPtr, arg3, 0, 1
    );
    return self;
}
