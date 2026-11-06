#pragma force_active on

struct GlobalObject86D50
{
    void* vtable;
};

extern "C" {
extern void* lbl_27_data_86D50;
extern GlobalObject86D50 lbl_27_bss_7C64;
extern unsigned int lbl_27_bss_7C58[3];
void* fn_27_324898(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_3248D8();
}

void fn_27_3248D8()
{
    lbl_27_bss_7C64.vtable = 0;
    lbl_27_bss_7C64.vtable = &lbl_27_data_86D50;
    __register_global_object(&lbl_27_bss_7C64, (void*)fn_27_324898, lbl_27_bss_7C58);
}

__declspec(section ".ctors") extern void* const fn_27_3248D8_ctor = (void*)fn_27_3248D8;
