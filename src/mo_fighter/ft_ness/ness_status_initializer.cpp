struct NessStatusProcess { void* vtable; };
struct NessStatusRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern NessStatusProcess lbl_101_bss_20C;
extern NessStatusRegistration lbl_101_bss_200;
NessStatusProcess* fn_101_117A8(NessStatusProcess*);
void* fn_101_11720(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_11760() {
    fn_101_117A8(&lbl_101_bss_20C);
    __register_global_object(&lbl_101_bss_20C,
        reinterpret_cast<void*>(fn_101_11720), &lbl_101_bss_200);
}

__declspec(section ".ctors") extern void (*const nessStatusInitializer)() = fn_101_11760;
