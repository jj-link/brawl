#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct Reg { void* a; void* b; void* c; };
struct G {
    Reg r1; unsigned char o1[4];
    Reg r2; unsigned char o2[4];
    Reg r3; unsigned char o3[4];
    Reg r4; unsigned char o4[4];
    Reg r5; unsigned char o5[4];
};

extern "C" {
extern G lbl_98_bss_250;
void fn_98_10FF0(void*);
void fn_98_11000(void*);
void fn_98_11010(void*);
void fn_98_11020(void*);
void fn_98_11030(void*);
void* fn_98_10EF8(void*, int);
void* fn_98_10EB8(void*, int);
void* fn_98_10E78(void*, short);
void* fn_98_10E38(void*, int);
void* fn_98_10DF8(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_98_10F38() {
    Reg G::* r = &G::r1;
    fn_98_10FF0(lbl_98_bss_250.o1);
    __register_global_object(lbl_98_bss_250.o1, (void*)fn_98_10EF8, &(lbl_98_bss_250.*r));
    fn_98_11000(lbl_98_bss_250.o2);
    __register_global_object(lbl_98_bss_250.o2, (void*)fn_98_10EB8, &lbl_98_bss_250.r2);
    fn_98_11010(lbl_98_bss_250.o3);
    __register_global_object(lbl_98_bss_250.o3, (void*)fn_98_10E78, &lbl_98_bss_250.r3);
    fn_98_11020(lbl_98_bss_250.o4);
    __register_global_object(lbl_98_bss_250.o4, (void*)fn_98_10E38, &lbl_98_bss_250.r4);
    fn_98_11030(lbl_98_bss_250.o5);
    __register_global_object(lbl_98_bss_250.o5, (void*)fn_98_10DF8, &lbl_98_bss_250.r5);
}

__declspec(section ".ctors") extern void* const fn_98_10F38_ctor = (void*)fn_98_10F38;
