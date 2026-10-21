#include <types.h>
#pragma force_active on

struct SoraStorage { void* primary; void* secondary; };
struct SoraRegistration { void* next; void* object; void* destructor; };
class SoraView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};

extern "C" {
extern signed char lbl_27_bss_51E8;
extern SoraStorage lbl_27_bss_51F0;
extern unsigned char lbl_27_data_A138[], lbl_27_data_A108[];
extern unsigned char lbl_27_data_A0A0[], lbl_27_data_A028[];
extern unsigned char lbl_27_bss_8C98[];
void fn_27_7C3D8(void*, s32);
void __register_global_object(void*, void*, void*);

void fn_27_3CBA0C() {
    if (lbl_27_bss_51E8 == 0) {
        lbl_27_bss_51F0.primary = lbl_27_data_A138;
        lbl_27_bss_51F0.secondary = lbl_27_data_A108;
        lbl_27_bss_51F0.primary = lbl_27_data_A0A0;
        lbl_27_bss_51F0.secondary = lbl_27_data_A0A0 + 0x10;
        lbl_27_bss_51F0.primary = lbl_27_data_A028;
        lbl_27_bss_51F0.secondary = lbl_27_data_A028 + 0x10;
        __register_global_object(&lbl_27_bss_51F0, reinterpret_cast<void*>(fn_27_7C3D8), lbl_27_bss_8C98);
        lbl_27_bss_51E8 = 1;
    }
    reinterpret_cast<SoraView*>(&lbl_27_bss_51F0)->dispatch();
}
}
