#pragma force_active on
extern "C" {
void fn_27_1E82E8(void* self, int arg);
void fn_27_1E847C(void* self, int arg, void* self2);
void __register_global_object(void* obj, void (*dtor)(void*), void* dtorObj);
void fn_27_328CF8(void* self);
}

struct soObj {
    void* a;
    int b;
    void* c;
};

extern soObj lbl_27_bss_7CC4;
extern char lbl_27_data_87D40[0x18];
extern char lbl_27_bss_7CB8[0xC];

extern "C" void fn_27_328C7C() {
    fn_27_1E82E8(&lbl_27_bss_7CC4, 0);
    lbl_27_bss_7CC4.c = lbl_27_data_87D40;
    lbl_27_bss_7CC4.a = lbl_27_data_87D40 + 8;
    fn_27_1E847C(&lbl_27_bss_7CC4, 0x95, &lbl_27_bss_7CC4);
    __register_global_object(&lbl_27_bss_7CC4, fn_27_328CF8, lbl_27_bss_7CB8);
}

__declspec(section ".ctors") extern void* const fn_27_328C7C_ctor = (void*)fn_27_328C7C;
