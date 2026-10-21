#pragma force_active on
typedef struct Obj Obj;

extern "C" void fn_113_23328(Obj*);
extern "C" void* fn_113_23280(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" unsigned char lbl_113_bss_1C4[];
extern "C" unsigned char lbl_113_bss_1B8[];

extern "C" void fn_113_232E0() {
    fn_113_23328((Obj*)lbl_113_bss_1C4);
    __register_global_object(
        lbl_113_bss_1C4,
        (void*)fn_113_23280,
        lbl_113_bss_1B8
    );
}

__declspec(section ".ctors") extern void* const fn_113_232E0_ctor = (void*)fn_113_232E0;
