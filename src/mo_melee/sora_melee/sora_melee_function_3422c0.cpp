#pragma force_active on

extern "C" {

struct SheikNeedleObject
{
    void* vtbl;
};

extern char lbl_27_data_8C448[];
extern char lbl_27_bss_7EA0[0xC];
extern SheikNeedleObject lbl_27_bss_7EAC;
void* fn_27_342280(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_3422C0()
{
    lbl_27_bss_7EAC.vtbl = 0;
    lbl_27_bss_7EAC.vtbl = lbl_27_data_8C448;
    __register_global_object(&lbl_27_bss_7EAC, fn_27_342280, lbl_27_bss_7EA0);
}

}

__declspec(section ".ctors") extern void* const fn_27_3422C0_ctor = (void*)fn_27_3422C0;
