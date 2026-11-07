#pragma force_active on
struct GanonArticleMediatorStorage { void* primary; void* secondary; };
struct GanonArticleMediatorRegistration { void* next; void* object; void* destructor; };
class GanonArticleMediatorView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_109_bss_278;
extern GanonArticleMediatorStorage lbl_109_bss_27C;
extern GanonArticleMediatorRegistration lbl_109_bss_210;
extern unsigned char lbl_109_data_1AD4[], lbl_109_data_1AA8[];
extern unsigned char lbl_109_data_1A40[], lbl_109_data_6E50[];
void* fn_109_1171C(void*, short);
void __register_global_object(void*, void*, void*);
void fn_109_11ACC(void) {
    if (lbl_109_bss_278 == 0) {
        lbl_109_bss_27C.primary = lbl_109_data_1AD4;
        lbl_109_bss_27C.secondary = lbl_109_data_1AA8;
        lbl_109_bss_27C.primary = lbl_109_data_1A40;
        lbl_109_bss_27C.secondary = lbl_109_data_1A40 + 0x10;
        lbl_109_bss_27C.primary = lbl_109_data_6E50;
        lbl_109_bss_27C.secondary = lbl_109_data_6E50 + 0x10;
        __register_global_object(&lbl_109_bss_27C, reinterpret_cast<void*>(fn_109_1171C), &lbl_109_bss_210);
        lbl_109_bss_278 = 1;
    }
    reinterpret_cast<GanonArticleMediatorView*>(&lbl_109_bss_27C)->dispatch();
}
}