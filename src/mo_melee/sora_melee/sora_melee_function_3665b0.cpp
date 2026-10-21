#pragma force_active on
extern "C" {
    void fn_27_1E82E8(void*, int);
    void fn_27_1E847C(void*, int, void*);
    void fn_27_36662C(void*);
    void __register_global_object(void*, void*, void*);
}

struct soObjRaw {
    void* vt;
    void* pad;
    void* self;
};

extern soObjRaw lbl_27_bss_8288;
extern char lbl_27_data_91808[];
extern char lbl_27_bss_827C[];

extern "C" void fn_27_3665B0() {
    fn_27_1E82E8(&lbl_27_bss_8288, 0);
    soObjRaw* p = &lbl_27_bss_8288;
    p->self = lbl_27_data_91808;
    p->vt = lbl_27_data_91808 + 8;
    fn_27_1E847C(p, 0x36, p);
    __register_global_object(p, (void*)fn_27_36662C, lbl_27_bss_827C);
}

__declspec(section ".ctors") extern void* const fn_27_3665B0_ctor = (void*)fn_27_3665B0;
