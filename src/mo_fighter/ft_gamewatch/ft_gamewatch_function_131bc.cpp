#pragma force_active on
extern "C" void fn_107_13204(void* arg0);
extern "C" void* fn_107_1317C(void* ptr, short count);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" char lbl_107_bss_1EC[];
extern "C" char lbl_107_bss_1E0[];

extern "C" void fn_107_131BC() {
    fn_107_13204(lbl_107_bss_1EC);
    __register_global_object(lbl_107_bss_1EC, (void*)fn_107_1317C, lbl_107_bss_1E0);
}

__declspec(section ".ctors") extern void* const fn_107_131BC_ctor = (void*)fn_107_131BC;
