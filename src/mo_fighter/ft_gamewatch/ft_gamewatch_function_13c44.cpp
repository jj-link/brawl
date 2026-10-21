#pragma force_active on
struct ClassWithVtable;

extern "C" {
extern char lbl_107_bss_21C[4];
extern char lbl_107_bss_210[12];
void fn_107_13C8C(ClassWithVtable* object);
void* fn_107_13C04(void* ptr, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_107_13C44() {
    fn_107_13C8C((ClassWithVtable*)lbl_107_bss_21C);
    __register_global_object(lbl_107_bss_21C, (void*)fn_107_13C04, lbl_107_bss_210);
}

__declspec(section ".ctors") extern void* const fn_107_13C44_ctor = (void*)fn_107_13C44;
