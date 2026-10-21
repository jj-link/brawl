#pragma force_active on
struct DiddyArticleMediatorStorage { void* primary; void* secondary; };
struct DiddyArticleMediatorRegistration { void* next; void* object; void* destructor; };
class DiddyArticleMediatorView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_115_bss_394;
extern DiddyArticleMediatorStorage lbl_115_bss_398;
extern DiddyArticleMediatorRegistration lbl_115_bss_334;
extern unsigned char lbl_115_data_2BC4[], lbl_115_data_2B98[];
extern unsigned char lbl_115_data_2B30[], lbl_115_data_82E8[];
void* fn_115_171AC(void*, short);
void __register_global_object(void*, void*, void*);
void fn_115_17488(void*) {
    if (lbl_115_bss_394 == 0) {
        lbl_115_bss_398.primary = lbl_115_data_2BC4;
        lbl_115_bss_398.secondary = lbl_115_data_2B98;
        lbl_115_bss_398.primary = lbl_115_data_2B30;
        lbl_115_bss_398.secondary = lbl_115_data_2B30 + 0x10;
        lbl_115_bss_398.primary = lbl_115_data_82E8;
        lbl_115_bss_398.secondary = lbl_115_data_82E8 + 0x10;
        __register_global_object(&lbl_115_bss_398, reinterpret_cast<void*>(fn_115_171AC), &lbl_115_bss_334);
        lbl_115_bss_394 = 1;
    }
    reinterpret_cast<DiddyArticleMediatorView*>(&lbl_115_bss_398)->dispatch();
}
}
