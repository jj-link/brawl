#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {

void* fn_103_13150(void* object, s32 deleteFlag);
void __register_global_object(void* obj, void* dtor, void* extra);

struct GlobalObject {
    s8 flag;
    void* data;
};

extern s8 lbl_103_bss_258;
extern u8 lbl_103_data_7110[];
extern GlobalObject lbl_103_bss_25C;
extern u8 lbl_103_data_70BC[];
extern u8 lbl_103_bss_1F8[];

void* fn_103_1308C() {
    if (!lbl_103_bss_258) {
        lbl_103_bss_25C.data = (void*)lbl_103_data_7110;
        lbl_103_bss_25C.flag = 1;
        lbl_103_bss_25C.data = (void*)lbl_103_data_70BC;
        __register_global_object(&lbl_103_bss_25C, (void*)fn_103_13150, (void*)lbl_103_bss_1F8);
        lbl_103_bss_258 = 1;
    }
    return (void*)&lbl_103_bss_25C;
}
}
