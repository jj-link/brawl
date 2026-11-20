#include <new>
#include <so/so_array_vector_calculator.h>

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
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_3C688[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_3ED00[];
extern char lbl_27_data_929B4[];
extern char g_soGeneralWork[];
extern signed char lbl_27_bss_76B4;
extern char lbl_27_bss_83B0[];
extern GlobalObject lbl_27_bss_76B8;

void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void fn_27_82B54(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* __register_global_object(void*, void*, void*);
void fn_27_73930(void*, int, void*, void*, void*, void*, void*, int, int, int);
}

static inline GlobalObject* getGlobal() {
    if (!lbl_27_bss_76B4) {
        GlobalObject* object = new (&lbl_27_bss_76B8) GlobalObject;
        __register_global_object(object, (void*)fn_27_82B54, lbl_27_bss_83B0);
        lbl_27_bss_76B4 = 1;
    }
    return &lbl_27_bss_76B8;
}

struct Array {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(const void*);
    virtual void v11();
    virtual void v12(const void*);
    virtual void v13();
    virtual void v14();
    virtual int v15();
    virtual bool v16();
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
    virtual void v27();
    virtual void v28();
    virtual int v29();
    virtual int v30();

    void* calc;
    unsigned int flags;
};

struct Object {
    void* vtable;
    int zero;
    int status;
    int enabled;
    char pad10[4];
    char sub[0x58];
    Array* arrayPtr;
    Array array;
    char impl[1];
};

extern "C" Object* fn_27_3702B8(Object* self, int arg1, int arg2, int arg3) {
    self->zero = 0;
    self->vtable = lbl_27_data_20950;
    self->status = arg2;
    self->enabled = 3;
    if (!arg2) {
        self->enabled = 0;
    }

    char* p = (char*)self + 0x14;
    *(void**)p = lbl_27_data_1D4E8;
    *(void**)(p + 4) = lbl_27_data_1D4E8 + 0x48;
    *(unsigned int*)(p + 8) &= 0x01ffffff;
    __construct_array(p + 0xc, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);

    *(void**)(p + 0x20) = lbl_27_data_3C688;
    *(void**)(p + 0x24) = lbl_27_data_3C688 + 0x48;
    *(unsigned int*)(p + 0x28) &= 0x01ffffff;
    __construct_array(p + 0x2c, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 1);

    *(void**)(p + 0x40) = p;
    *(void**)(p + 0x3c) = lbl_27_data_8E80;
    *(int*)(p + 0x44) = 0;
    *(int*)(p + 0x50) = 0;
    *(int*)(p + 0x48) = -1;
    *(int*)(p + 0x4c) = -1;

    char temp[0x14];
    for (int j = 0; j < 1; ++j) {
        fn_27_AB15C(temp, j == 0 ? p + 0x20 : 0);
        ((Array*)p)->v12(temp);
        fn_27_AB18C(temp, -1);
    }

    Array* a = &self->array;
    self->arrayPtr = a;
    *(void**)a = lbl_27_data_3ED00;
    a->calc = lbl_27_data_3ED00 + 0x48;
    a->flags &= 0x01ffffff;
    int n = soArrayVectorCalculator::resize(
        *(soArrayVectorCalcInterface*)&a->calc, 1, a->v6(), a->v16(), a->v15(), a->v29(), a->v30()
    );
    int i = 0;
    for (; i < n; i++) {
        a->v12(&lbl_27_data_929B4);
    }
    self->array.v15();

    fn_27_73930((char*)self + 0x80, arg1, self, getGlobal(), &g_soGeneralWork,
                (char*)self + 0x50, (char*)self + 0x6c, arg3, 0, 1);
    return self;
}
