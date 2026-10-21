#pragma force_active on
struct Obj {
    void* vt0;
    int field4;
    void* vt8;
    int fieldC;
};

extern "C" {
extern Obj lbl_27_bss_7CA8;
extern char lbl_27_data_87860[];
extern char lbl_27_bss_7C9C[];

void fn_27_1E82E8(Obj*, int);
void fn_27_1E847C(Obj*, int, Obj*);
void fn_27_3285B4(Obj*, int);
void __register_global_object(void*, void (*)(Obj*, int), void*);

void fn_27_328538() {
    fn_27_1E82E8(&lbl_27_bss_7CA8, 0);
    lbl_27_bss_7CA8.vt8 = lbl_27_data_87860;
    lbl_27_bss_7CA8.vt0 = lbl_27_data_87860 + 8;
    fn_27_1E847C(&lbl_27_bss_7CA8, 10, &lbl_27_bss_7CA8);
    __register_global_object(&lbl_27_bss_7CA8, fn_27_3285B4,
                             lbl_27_bss_7C9C);
}
}

__declspec(section ".ctors") extern void* const fn_27_328538_ctor = (void*)fn_27_328538;
