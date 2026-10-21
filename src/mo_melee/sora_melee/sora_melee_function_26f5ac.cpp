#pragma force_active on
extern "C" void fn_27_8B574(void* self, int flag);
extern "C" void fn_27_26F554(void* self, int flag);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern int lbl_27_data_57288[];
extern int lbl_27_bss_6010[];
extern int lbl_27_bss_6000[];

extern "C" void fn_27_26F5AC(void)
{
    fn_27_8B574(lbl_27_bss_6010, 3);
    *(int**)((char*)lbl_27_bss_6010 + 4) = lbl_27_data_57288;
    __register_global_object(lbl_27_bss_6010, (void*)fn_27_26F554, lbl_27_bss_6000);
}

__declspec(section ".ctors") extern void* const fn_27_26F5AC_ctor = (void*)fn_27_26F5AC;
