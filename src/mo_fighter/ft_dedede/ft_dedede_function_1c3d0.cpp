struct DededeParameterSingletonStorage { void* primary; void* secondary; };
struct DededeParameterSingletonRegistration { void* next; void* object; void* destructor; };
class DededeParameterSingletonView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual int dispatch();
};
extern "C" {
extern signed char lbl_117_bss_394;
extern DededeParameterSingletonStorage lbl_117_bss_398;
extern DededeParameterSingletonRegistration lbl_117_bss_418;
extern unsigned char lbl_117_data_3B0C[], lbl_117_data_3AE0[];
extern unsigned char lbl_117_data_3A78[], lbl_117_data_90D0[];
void* fn_117_1538C(void*, short);
void __register_global_object(void*, void*, void*);
int fn_117_1C3D0(void*) {
    if (lbl_117_bss_394 == 0) {
        lbl_117_bss_398.primary = lbl_117_data_3B0C;
        lbl_117_bss_398.secondary = lbl_117_data_3AE0;
        lbl_117_bss_398.primary = lbl_117_data_3A78;
        lbl_117_bss_398.secondary = lbl_117_data_3A78 + 0x10;
        lbl_117_bss_398.primary = lbl_117_data_90D0;
        lbl_117_bss_398.secondary = lbl_117_data_90D0 + 0x10;
        __register_global_object(&lbl_117_bss_398, reinterpret_cast<void*>(fn_117_1538C), &lbl_117_bss_418);
        lbl_117_bss_394 = 1;
    }
    return reinterpret_cast<DededeParameterSingletonView*>(&lbl_117_bss_398)->dispatch();
}
}
