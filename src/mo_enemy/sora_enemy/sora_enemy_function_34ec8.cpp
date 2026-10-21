#pragma force_active on
struct fnObj41 {
    void* m_vt;
    unsigned char m_flag;
    void* m_ptr;
};

extern "C" {
extern fnObj41 lbl_41_bss_28C;
extern unsigned char lbl_41_bss_280[];
void fn_41_34F10(fnObj41*);
void* fn_41_34E68(void*, int);
void __register_global_object(void*, void* (*)(void*, int), void*);

void fn_41_34EC8() {
    fnObj41* p = &lbl_41_bss_28C;
    fn_41_34F10(p);
    __register_global_object(p, fn_41_34E68, lbl_41_bss_280);
}
}

__declspec(section ".ctors") extern void* const fn_41_34EC8_ctor = (void*)fn_41_34EC8;
