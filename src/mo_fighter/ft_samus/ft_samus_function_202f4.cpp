#pragma force_active on
struct SamusArticleMediatorStorage { void* primary; void* secondary; };
struct SamusArticleMediatorRegistration { void* next; void* object; void* destructor; };
class SamusArticleMediatorView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_94_bss_3C8;
extern SamusArticleMediatorStorage lbl_94_bss_3CC;
extern SamusArticleMediatorRegistration lbl_94_bss_410;
extern unsigned char lbl_94_data_49D4[], lbl_94_data_49A8[];
extern unsigned char lbl_94_data_4940[], lbl_94_data_CEB4[];
void* fn_94_1D960(void*, short);
void __register_global_object(void*, void*, void*);
void fn_94_202F4(void) {
    if (lbl_94_bss_3C8 == 0) {
        lbl_94_bss_3CC.primary = lbl_94_data_49D4;
        lbl_94_bss_3CC.secondary = lbl_94_data_49A8;
        lbl_94_bss_3CC.primary = lbl_94_data_4940;
        lbl_94_bss_3CC.secondary = lbl_94_data_4940 + 0x10;
        lbl_94_bss_3CC.primary = lbl_94_data_CEB4;
        lbl_94_bss_3CC.secondary = lbl_94_data_CEB4 + 0x10;
        __register_global_object(&lbl_94_bss_3CC, reinterpret_cast<void*>(fn_94_1D960), &lbl_94_bss_410);
        lbl_94_bss_3C8 = 1;
    }
    reinterpret_cast<SamusArticleMediatorView*>(&lbl_94_bss_3CC)->dispatch();
}
}
