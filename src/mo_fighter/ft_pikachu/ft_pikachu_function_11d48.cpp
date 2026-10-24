#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct Reg { void* a; void* b; void* c; };
struct G {
    Reg r1; unsigned char o1[4];
    Reg r2; unsigned char o2[4];
    Reg r3; unsigned char o3[4];
};

extern "C" {
extern G lbl_98_bss_2C0;
void fn_98_11DC8(void*);
void fn_98_11DD8(void*);
void fn_98_11DE8(void*);
void* fn_98_11D08(void*, int);
void* fn_98_11CC8(void*, int);
void* fn_98_11C88(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_98_11D48() {
    Reg G::* r = &G::r1;
    fn_98_11DC8(lbl_98_bss_2C0.o1);
    __register_global_object(lbl_98_bss_2C0.o1, (void*)fn_98_11D08, &(lbl_98_bss_2C0.*r));
    fn_98_11DD8(lbl_98_bss_2C0.o2);
    __register_global_object(lbl_98_bss_2C0.o2, (void*)fn_98_11CC8, &lbl_98_bss_2C0.r2);
    fn_98_11DE8(lbl_98_bss_2C0.o3);
    __register_global_object(lbl_98_bss_2C0.o3, (void*)fn_98_11C88, &lbl_98_bss_2C0.r3);
}

__declspec(section ".ctors") extern void* const fn_98_11D48_ctor = (void*)fn_98_11D48;
