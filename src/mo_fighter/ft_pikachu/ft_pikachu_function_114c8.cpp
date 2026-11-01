#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct R { void* a; void* b; void* c; };
struct S { R r1; unsigned char o1[4]; R r2; unsigned char o2[4]; };

extern "C" {
extern S lbl_98_bss_2A0;
void fn_98_1152C(void*);
void fn_98_1153C(void*);
void* fn_98_11488(void*, int);
void* fn_98_11448(void*, int);
void __register_global_object(void*, void*, void*);

void fn_98_114C8() {
    R S::* r = &S::r1;
    fn_98_1152C(lbl_98_bss_2A0.o1);
    __register_global_object(lbl_98_bss_2A0.o1, (void*)fn_98_11488, &(lbl_98_bss_2A0.*r));
    fn_98_1153C(lbl_98_bss_2A0.o2);
    __register_global_object(lbl_98_bss_2A0.o2, (void*)fn_98_11448, &lbl_98_bss_2A0.r2);
}

__declspec(section ".ctors") extern void* const fn_98_114C8_ctor;
}

__declspec(section ".ctors") extern void* const fn_98_114C8_ctor = (void*)fn_98_114C8;
