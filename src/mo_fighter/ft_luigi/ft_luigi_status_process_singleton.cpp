struct LuigiStatusProcess { void* vtable; };
struct LuigiStatusRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern const char lbl_99_data_63A8[];
void* fn_99_CD7C(void*, short);
void __register_global_object(void*, void*, void*);
LuigiStatusRegistration lbl_99_bss_1C0;
LuigiStatusProcess lbl_99_bss_1CC;
LuigiStatusProcess* fn_99_CE08(LuigiStatusProcess*);
}

extern "C" void fn_99_CDC0() {
    fn_99_CE08(&lbl_99_bss_1CC);
    __register_global_object(&lbl_99_bss_1CC, reinterpret_cast<void*>(fn_99_CD7C), &lbl_99_bss_1C0);
}

#pragma dont_inline on
extern "C" LuigiStatusProcess* fn_99_CE08(LuigiStatusProcess* process) {
    process->vtable = const_cast<char*>(lbl_99_data_63A8);
    return process;
}
#pragma dont_inline reset

__declspec(section ".ctors") extern void (*const luigiStatusInitializer)() = fn_99_CDC0;
