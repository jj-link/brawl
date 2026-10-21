#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1E82E8(void* self, int arg);
void fn_27_1E847C(void* self, int arg, void* other);
void __register_global_object(void* obj, void (*dtor)(void*), void* dtorTable);
void fn_27_31E5B8();
void fn_27_31E634(void* p);
}

struct soStaticWork {
    void* m_vtblLike;
    int m_pad;
    void* m_data;
};

extern soStaticWork lbl_27_bss_7BD0;
extern char lbl_27_data_85928[];
extern char lbl_27_bss_7BC4[];

void fn_27_31E5B8() {
    fn_27_1E82E8(&lbl_27_bss_7BD0, 0);
    lbl_27_bss_7BD0.m_data = lbl_27_data_85928;
    lbl_27_bss_7BD0.m_vtblLike = lbl_27_data_85928 + 8;
    fn_27_1E847C(&lbl_27_bss_7BD0, 0x22, &lbl_27_bss_7BD0);
    __register_global_object(&lbl_27_bss_7BD0, fn_27_31E634, lbl_27_bss_7BC4);
}

__declspec(section ".ctors") extern void* const fn_27_31E5B8_ctor = (void*)fn_27_31E5B8;
