#pragma force_active on
extern "C" {
struct GlobalObject { void* vtable; };
struct DtorArg { int a, b, c; };
void __register_global_object(void* object, void* destructor, void* chain);
void* fn_27_18A67C(void* ptr, int count);
extern int lbl_27_data_31840;
extern GlobalObject lbl_27_bss_4E5C;
extern DtorArg lbl_27_bss_4E50;

void fn_27_18B190() {
    lbl_27_bss_4E5C.vtable = 0;
    lbl_27_bss_4E5C.vtable = &lbl_27_data_31840;
    __register_global_object(&lbl_27_bss_4E5C, fn_27_18A67C, &lbl_27_bss_4E50);
}
}

__declspec(section ".ctors") extern void* const fn_27_18B190_ctor = (void*)fn_27_18B190;
