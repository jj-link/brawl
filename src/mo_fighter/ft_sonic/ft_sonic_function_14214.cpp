#pragma force_active on
struct SonicMediatorStorage { void* primary; void* secondary; };
struct SonicMediatorRegistration { void* next; void* object; void* destructor; };
class SonicMediatorView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_123_bss_3B0;
extern SonicMediatorStorage lbl_123_bss_3B4;
extern SonicMediatorRegistration lbl_123_bss_344;
extern unsigned char lbl_123_data_1BC4[], lbl_123_data_1B98[];
extern unsigned char lbl_123_data_1B30[], lbl_123_data_6F80[];
void* fn_123_13F70(void*, short);
void __register_global_object(void*, void*, void*);
void fn_123_14214() {
    if (lbl_123_bss_3B0 == 0) {
        lbl_123_bss_3B4.primary = lbl_123_data_1BC4;
        lbl_123_bss_3B4.secondary = lbl_123_data_1B98;
        lbl_123_bss_3B4.primary = lbl_123_data_1B30;
        lbl_123_bss_3B4.secondary = lbl_123_data_1B30 + 0x10;
        lbl_123_bss_3B4.primary = lbl_123_data_6F80;
        lbl_123_bss_3B4.secondary = lbl_123_data_6F80 + 0x10;
        __register_global_object(&lbl_123_bss_3B4, reinterpret_cast<void*>(fn_123_13F70), &lbl_123_bss_344);
        lbl_123_bss_3B0 = 1;
    }
    reinterpret_cast<SonicMediatorView*>(&lbl_123_bss_3B4)->dispatch();
}
}
