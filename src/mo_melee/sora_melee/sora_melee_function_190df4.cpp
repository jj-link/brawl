#pragma force_active on
#pragma opt_propagation off

extern "C" {

extern char lbl_27_data_32438[];
extern char jumptable_27_data_32070[];

void fn_27_190DB4(void*, int);
void fn_27_190D74(void*, int);
void fn_27_190D34(void*, int);
void fn_27_190CF4(void*, int);
void fn_27_190CB4(void*, int);
void __register_global_object(void*, void*, void*);

struct Obj {
    void* a;
    void* b;
    void* c;
    void* d;
};
extern Obj lbl_27_bss_4F40[5];

void fn_27_190DF4() {
    Obj* base = lbl_27_bss_4F40;
    char* data = jumptable_27_data_32070;

    base[0].d = (void*)lbl_27_data_32438;

    void* (Obj::*first) = &Obj::a;
    __register_global_object(&base[0].d, fn_27_190DB4, &(base->*first));

    base[1].d = (void*)(data + 0x348);
    __register_global_object(&base[1].d, fn_27_190D74, &base[1].a);

    base[2].d = (void*)(data + 0x2C8);
    __register_global_object(&base[2].d, fn_27_190D34, &base[2].a);

    base[3].d = (void*)(data + 0x248);
    __register_global_object(&base[3].d, fn_27_190CF4, &base[3].a);

    base[4].d = (void*)(data + 0x1D0);
    __register_global_object(&base[4].d, fn_27_190CB4, &base[4].a);
}

}

__declspec(section ".ctors") extern void* const fn_27_190DF4_ctor = (void*)fn_27_190DF4;
