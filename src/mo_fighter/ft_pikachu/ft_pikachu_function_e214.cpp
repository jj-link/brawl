#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

struct Reg { void* a; void* b; void* c; };
struct BssBlock {
    Reg r1;
    char obj1[0x1C8];
    Reg r2;
    char obj2[0xC];
};

extern "C" {
extern BssBlock lbl_98_bss_8;
void* fn_98_E278(void*);
void* fn_98_E2C0(void*);
void* fn_98_9AB0(void*, int);
void* fn_98_E318(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_98_E214() {
    Reg BssBlock::* rp = &BssBlock::r1;
    fn_98_E278(&lbl_98_bss_8.obj1);
    __register_global_object(&lbl_98_bss_8.obj1, (void*)fn_98_9AB0, &(lbl_98_bss_8.*rp));
    fn_98_E2C0(&lbl_98_bss_8.obj2);
    __register_global_object(&lbl_98_bss_8.obj2, (void*)fn_98_E318, &lbl_98_bss_8.r2);
}

__declspec(section ".ctors") extern void* const fn_98_E214_ctor = (void*)fn_98_E214;
