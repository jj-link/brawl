#pragma force_active on
extern "C" {
extern char lbl_95_bss_344[];
extern char lbl_95_bss_338[];
void fn_95_F204(void* self);
void* fn_95_F17C(void* self, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_95_F1BC() {
    fn_95_F204(lbl_95_bss_344);
    __register_global_object(lbl_95_bss_344, (void*)fn_95_F17C, lbl_95_bss_338);
}

__declspec(section ".ctors") extern void* const fn_95_F1BC_ctor = (void*)fn_95_F1BC;
