#pragma force_active on
extern "C" {

struct GlobalObject {
    void* vtable;
};

extern char lbl_27_data_45E78[];
extern GlobalObject lbl_27_bss_513C;
extern char lbl_27_bss_5130[0xC];
void fn_27_1DEE98(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1DEED8(void) {
    lbl_27_bss_513C.vtable = 0;
    lbl_27_bss_513C.vtable = (void*)&lbl_27_data_45E78;
    __register_global_object(&lbl_27_bss_513C, (void*)fn_27_1DEE98, lbl_27_bss_5130);
}

}

__declspec(section ".ctors") extern void* const fn_27_1DEED8_ctor = (void*)fn_27_1DEED8;
