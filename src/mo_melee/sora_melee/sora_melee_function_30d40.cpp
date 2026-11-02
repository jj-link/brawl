#pragma force_active on
#pragma push
#pragma opt_propagation off

extern "C" {
void fn_27_30D00(void*, int);
void fn_27_30CC0(void*, int);
void* __register_global_object(void*, void*, void*);
}

struct Bss80 {
    void* chain1;
    void* _p1;
    void* _p2;
    void* obj1;
    void* chain2;
    void* _p3;
    void* _p4;
    void* obj2;
};

extern Bss80 lbl_27_bss_80;
extern char lbl_27_data_3118[];
extern char lbl_27_data_30B8[];

extern "C" void fn_27_30D40(void) {
    Bss80* base = &lbl_27_bss_80;
    void* (Bss80::*chain1Mem) = &Bss80::chain1;

    base->obj1 = (void*)lbl_27_data_3118;
    __register_global_object(&base->obj1, (void*)fn_27_30D00, &(base->*chain1Mem));

    base->obj2 = (void*)lbl_27_data_30B8;
    __register_global_object(&base->obj2, (void*)fn_27_30CC0, &base->chain2);
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_27_30D40_ctor = (void*)fn_27_30D40;
