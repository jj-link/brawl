#include <types.h>
#pragma force_active on

extern "C" {
    u8 lbl_27_bss_7F70[];
    u8 lbl_27_bss_7F64[];
    u8 lbl_27_data_8E0E8[];
    void fn_27_1E82E8(void* self, int flag);
    void fn_27_1E847C(void* self, int id, void* p);
    void fn_27_351EBC(void* self);
    int __register_global_object(void* obj, void (*dtor)(void*), void* handle);

    void fn_27_351E40() {
        u8* obj = lbl_27_bss_7F70;
        fn_27_1E82E8(obj, 0);
        *(u8**)(obj + 8) = lbl_27_data_8E0E8;
        *(u8**)(obj + 0) = lbl_27_data_8E0E8 + 8;
        fn_27_1E847C(obj, 0x75, obj);
        __register_global_object(obj, fn_27_351EBC, lbl_27_bss_7F64);
    }
}

__declspec(section ".ctors") extern void* const fn_27_351E40_ctor = (void*)fn_27_351E40;
