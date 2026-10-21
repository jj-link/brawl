#pragma force_active on
struct Obj {
    void* vt0;
    unsigned int field4;
    void* vt1;
};

extern "C" {
extern Obj lbl_27_bss_7678;
extern char lbl_27_bss_766C[];
extern char lbl_27_data_82048[];

void fn_27_1E82E8(void*, int);
void fn_27_1E847C(void*, int, void*);
Obj* fn_27_3040BC(Obj*, int);
void __register_global_object(void*, void*, void*);

void fn_27_304040() {
    Obj* p = &lbl_27_bss_7678;
    fn_27_1E82E8(p, 0);
    p->vt1 = lbl_27_data_82048;
    p->vt0 = lbl_27_data_82048 + 8;
    fn_27_1E847C(p, 0x62, p);
    __register_global_object(p, (void*)fn_27_3040BC, lbl_27_bss_766C);
}
}

__declspec(section ".ctors") extern void* const fn_27_304040_ctor = (void*)fn_27_304040;
