#pragma force_active on
extern "C" {
extern char lbl_20_data_8C8[];
extern char lbl_20_data_7B8[];
extern char lbl_20_bss_18[];
extern char lbl_20_bss_C[];
void* fn_20_90F0(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_20_9130() {
    char* obj = lbl_20_bss_18;
    *(char**)(obj + 4) = lbl_20_data_8C8;
    *(int*)lbl_20_bss_18 = 0;
    *(char**)(obj + 4) = lbl_20_data_7B8;
    __register_global_object(obj, (void*)fn_20_90F0, lbl_20_bss_C);
}
}

__declspec(section ".ctors") extern void* const fn_20_9130_ctor = (void*)fn_20_9130;
