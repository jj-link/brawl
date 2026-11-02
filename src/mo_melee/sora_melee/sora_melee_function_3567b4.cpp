#pragma force_active on
#pragma push
#pragma opt_propagation off
extern "C" {
struct Big {
    void* c0_next;   // 0x0
    void* c0_dtor;   // 0x4
    void* c0_obj;    // 0x8
    void* vt0;       // 0xC
    void* c1_next;   // 0x10
    void* c1_dtor;   // 0x14
    void* c1_obj;    // 0x18
    void* vt1;       // 0x1C
};
extern char lbl_27_data_8F1E8[];
extern char lbl_27_data_8F168[];
extern Big lbl_27_bss_7FF8;
void fn_27_356774(void*, int);
void fn_27_356734(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_3567B4() {
    Big* base = &lbl_27_bss_7FF8;
    void* (Big::*first) = &Big::c0_next;
    base->vt0 = lbl_27_data_8F1E8;
    __register_global_object(&base->vt0, fn_27_356774, &(base->*first));
    base->vt1 = lbl_27_data_8F168;
    __register_global_object(&base->vt1, fn_27_356734, &base->c1_next);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_27_3567B4_ctor = (void*)fn_27_3567B4;
