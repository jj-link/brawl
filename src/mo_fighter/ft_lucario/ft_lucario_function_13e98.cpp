#pragma force_active on
struct LucarioArticleMediatorStorage { void* primary; void* secondary; };
struct LucarioArticleMediatorRegistration { void* next; void* object; void* destructor; };
class LucarioArticleMediatorView {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_118_bss_370;
extern LucarioArticleMediatorStorage lbl_118_bss_374;
extern LucarioArticleMediatorRegistration lbl_118_bss_334;
extern unsigned char lbl_118_data_1C14[], lbl_118_data_1BE8[];
extern unsigned char lbl_118_data_1B80[], lbl_118_data_70DC[];
void* fn_118_13BFC(void*, short);
void __register_global_object(void*, void*, void*);
void fn_118_13E98(void) {
    if (lbl_118_bss_370 == 0) {
        lbl_118_bss_374.primary = lbl_118_data_1C14;
        lbl_118_bss_374.secondary = lbl_118_data_1BE8;
        lbl_118_bss_374.primary = lbl_118_data_1B80;
        lbl_118_bss_374.secondary = lbl_118_data_1B80 + 0x10;
        lbl_118_bss_374.primary = lbl_118_data_70DC;
        lbl_118_bss_374.secondary = lbl_118_data_70DC + 0x10;
        __register_global_object(&lbl_118_bss_374, reinterpret_cast<void*>(fn_118_13BFC), &lbl_118_bss_334);
        lbl_118_bss_370 = 1;
    }
    reinterpret_cast<LucarioArticleMediatorView*>(&lbl_118_bss_374)->dispatch();
}
}