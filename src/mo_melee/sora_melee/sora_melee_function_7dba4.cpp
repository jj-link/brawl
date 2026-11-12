#include <types.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on
extern "C" {
void __register_global_object(void*, void*, void*);
void fn_27_7DC10(void*);
extern char lbl_27_data_B620[];
extern signed char lbl_27_bss_1088;
extern char lbl_27_bss_190[];
}
struct GlobalObject {
    void* vt;
    GlobalObject() { vt = 0; vt = lbl_27_data_B620; }
};
extern "C" GlobalObject lbl_27_bss_108C;
extern "C" void* fn_27_7DBA4() {
    if (!lbl_27_bss_1088) {
        GlobalObject* p = new (&lbl_27_bss_108C) GlobalObject;
        __register_global_object(p, (void*)fn_27_7DC10, lbl_27_bss_190);
        lbl_27_bss_1088 = 1;
    }
    return &lbl_27_bss_108C;
}
