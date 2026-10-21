#pragma force_active on
extern "C" {
    typedef void (*DestructorFn)(void*, short);

    extern char lbl_95_bss_3AC[];
    extern char lbl_95_bss_3A0[];

    void fn_95_FB4C(void* self);
    void fn_95_FAC4(void* p, short flag);
    void* __register_global_object(void* object, DestructorFn destructor, void* chain);

    void fn_95_FB04() {
        fn_95_FB4C(lbl_95_bss_3AC);
        __register_global_object(lbl_95_bss_3AC, fn_95_FAC4, lbl_95_bss_3A0);
    }
}

__declspec(section ".ctors") extern void* const fn_95_FB04_ctor = (void*)fn_95_FB04;
