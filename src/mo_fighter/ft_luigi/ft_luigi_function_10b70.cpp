struct LuigiParameterSingletonStorage { void* primary; void* secondary; };
struct LuigiParameterSingletonRegistration { void* next; void* object; void* destructor; };
class LuigiParameterSingletonView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual int dispatch();
};
extern "C" {
extern signed char lbl_99_bss_268;
extern LuigiParameterSingletonStorage lbl_99_bss_26C;
extern LuigiParameterSingletonRegistration lbl_99_bss_1FC;
extern unsigned char lbl_99_data_1B80[];
extern unsigned char lbl_99_data_1B54[];
extern unsigned char lbl_99_data_1AEC[];
extern unsigned char lbl_99_data_6BE4[];
void* fn_99_108D4(void*, short);
void __register_global_object(void*, void*, void*);
int fn_99_10B70(void*) {
    if (lbl_99_bss_268 == 0) {
        lbl_99_bss_26C.primary = lbl_99_data_1B80;
        lbl_99_bss_26C.secondary = lbl_99_data_1B54;
        lbl_99_bss_26C.primary = lbl_99_data_1AEC;
        lbl_99_bss_26C.secondary = lbl_99_data_1AEC + 0x10;
        lbl_99_bss_26C.primary = lbl_99_data_6BE4;
        lbl_99_bss_26C.secondary = lbl_99_data_6BE4 + 0x10;
        __register_global_object(&lbl_99_bss_26C, reinterpret_cast<void*>(fn_99_108D4), &lbl_99_bss_1FC);
        lbl_99_bss_268 = 1;
    }
    return reinterpret_cast<LuigiParameterSingletonView*>(&lbl_99_bss_26C)->dispatch();
}
}
