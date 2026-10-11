struct NessFollowingProcess { void* vtable; };
struct NessFollowingProcessRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern NessFollowingProcess lbl_101_bss_25C;
extern NessFollowingProcessRegistration lbl_101_bss_250;
extern unsigned char lbl_101_data_8D68[];
NessFollowingProcess* fn_101_131EC(NessFollowingProcess*);
void* fn_101_13164(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_131A4() {
    fn_101_131EC(&lbl_101_bss_25C);
    __register_global_object(&lbl_101_bss_25C,
        reinterpret_cast<void*>(fn_101_13164), &lbl_101_bss_250);
}

#pragma dont_inline on
extern "C" NessFollowingProcess* fn_101_131EC(NessFollowingProcess* process) {
    process->vtable = lbl_101_data_8D68;
    return process;
}
#pragma dont_inline reset

__declspec(section ".ctors") extern void (*const nessFollowingProcessInitializer)() = fn_101_131A4;
