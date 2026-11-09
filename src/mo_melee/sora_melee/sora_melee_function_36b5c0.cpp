#include <new>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on
extern "C" char lbl_27_data_12998[];
struct GlobalObject {
    void* vtable;
    GlobalObject() { vtable = 0; vtable = lbl_27_data_12998; }
};
extern "C" {
extern char lbl_27_data_20950[];
extern char lbl_27_data_3ED00[];
extern int lbl_27_data_92214;
extern signed char lbl_27_bss_76B4;
extern GlobalObject lbl_27_bss_76B8;
extern char lbl_27_bss_8320[];
extern char lbl_27_bss_D7C[];
extern char g_soGeneralWork[];
void fn_27_82B54(void*, short);
void* __register_global_object(GlobalObject&, void*, void*);
void fn_27_73930(void*, int, void*, void*, void*, void*, void*, int, int, int);
}
static inline GlobalObject* getGlobal() {
    if (!lbl_27_bss_76B4) {
        GlobalObject* object = new (&lbl_27_bss_76B8) GlobalObject;
        __register_global_object(*object, (void*)fn_27_82B54, lbl_27_bss_8320);
        lbl_27_bss_76B4 = 1;
    }
    return &lbl_27_bss_76B8;
}
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
struct Object {
    void* vtable;
    int zero;
    int status;
    int enabled;
    int pad;
    Array* arrayPtr;
    Array array;
    int element;
    char impl[1];
};
extern "C" Object* fn_27_36B5C0(Object* self, int arg1, int arg2, int arg3) {
    self->zero = 0;
    self->vtable = lbl_27_data_20950;
    self->status = arg2;
    self->enabled = 1;
    if (!arg2) self->enabled = 0;
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
    for (; i < n; i++) a->v10(&lbl_27_data_92214);
    self->array.v13();
    fn_27_73930(self->impl, arg1, self, getGlobal(), g_soGeneralWork,
                lbl_27_bss_D7C, &self->arrayPtr, arg3, 0, 1);
    return self;
}