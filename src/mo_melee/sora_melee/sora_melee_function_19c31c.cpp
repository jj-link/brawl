#pragma force_active on
#include <so/so_array_vector_calculator.h>
extern "C" {
extern char lbl_27_data_3CE58[];
void __construct_array(void*, void* (*)(void*), void* (*)(void*, short), int, int);
void* fn_27_CCAC0(void*);
void* fn_27_4AD20(void*, short);
}
struct Obj {
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
    virtual void v10(int);
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
    void* p4;
    unsigned int f8;
    char arr[0x170];
};
extern "C" Obj* fn_27_19C31C(Obj* self, int arg1, int arg2) {
    *(void**)self = lbl_27_data_3CE58;
    self->p4 = lbl_27_data_3CE58 + 0x48;
    self->f8 &= 0x7FFFF;
    __construct_array(self->arr, fn_27_CCAC0, fn_27_4AD20, 0x5c, 4);
    bool t31;
    int t30;
    int t29;
    int t28;
    t28 = self->v28();
    t29 = self->v27();
    t30 = self->v13();
    t31 = self->v14();
    bool n = self->v4();
    int cnt = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&self->p4, arg1, n, t31, t30, t29, t28);
    for (int i = 0; i < cnt; i++) {
        self->v10(arg2);
    }
    return self;
}