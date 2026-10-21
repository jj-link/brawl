#pragma force_active on
extern "C" void fn_92_FB0C(void** object);
extern "C" void* fn_92_FA84(void* ptr, short count);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" void* lbl_92_bss_254;
extern "C" char lbl_92_bss_248[12];

extern "C" void fn_92_FAC4() {
    fn_92_FB0C(&lbl_92_bss_254);
    __register_global_object(&lbl_92_bss_254, (void*)fn_92_FA84, lbl_92_bss_248);
}

__declspec(section ".ctors") extern void* const fn_92_FAC4_ctor = (void*)fn_92_FAC4;
