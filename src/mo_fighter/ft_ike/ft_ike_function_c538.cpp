#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
struct IkeReg { void* next; void* obj; void* dtor; };
struct IkeBss {
    IkeReg reg;
    unsigned char param[0x1e8];
    unsigned char a[8];
    unsigned char b[8];
    IkeReg reg2;
    unsigned char info[0xc];
};
extern IkeBss lbl_119_bss_8;
void* fn_119_C5BC(void*);
void fn_119_C604(void*, unsigned int, unsigned int);
void* fn_119_C610(void*);
void* fn_119_93F4(void*, short);
void* fn_119_C668(void*, short);
void __register_global_object(void*, void*, void*);
}
extern "C" void fn_119_C538() {
    IkeReg IkeBss::* m = &IkeBss::reg;
    fn_119_C5BC(lbl_119_bss_8.param);
    __register_global_object(lbl_119_bss_8.param, reinterpret_cast<void*>(fn_119_93F4), &(lbl_119_bss_8.*m));
    fn_119_C604(lbl_119_bss_8.a, 255, 0);
    fn_119_C604(lbl_119_bss_8.b, 255, 1);
    fn_119_C610(lbl_119_bss_8.info);
    __register_global_object(lbl_119_bss_8.info, reinterpret_cast<void*>(fn_119_C668), &lbl_119_bss_8.reg2);
}

__declspec(section ".ctors") extern void* const fn_119_C538_ctor = (void*)fn_119_C538;
