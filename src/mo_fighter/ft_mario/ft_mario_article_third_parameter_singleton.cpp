struct MarioParameterSingletonStorage { void* primary; void* secondary; };
struct MarioParameterSingletonRegistration { void* next; void* object; void* destructor; };
class MarioParameterSingletonView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual int dispatch();
};
extern "C" {
extern signed char lbl_91_bss_280;
extern MarioParameterSingletonStorage lbl_91_bss_284;
extern MarioParameterSingletonRegistration lbl_91_bss_3A8;
extern unsigned char lbl_91_data_2D60[];
extern unsigned char lbl_91_data_2D34[];
extern unsigned char lbl_91_data_2CCC[];
extern unsigned char lbl_91_data_7E84[];
void* fn_91_101B8(void*, short);
void __register_global_object(void*, void*, void*);
int fn_91_18F9C(void*) {
    if (lbl_91_bss_280 == 0) {
        lbl_91_bss_284.primary = lbl_91_data_2D60;
        lbl_91_bss_284.secondary = lbl_91_data_2D34;
        lbl_91_bss_284.primary = lbl_91_data_2CCC;
        lbl_91_bss_284.secondary = lbl_91_data_2CCC + 0x10;
        lbl_91_bss_284.primary = lbl_91_data_7E84;
        lbl_91_bss_284.secondary = lbl_91_data_7E84 + 0x10;
        __register_global_object(&lbl_91_bss_284, reinterpret_cast<void*>(fn_91_101B8), &lbl_91_bss_3A8);
        lbl_91_bss_280 = 1;
    }
    return reinterpret_cast<MarioParameterSingletonView*>(&lbl_91_bss_284)->dispatch();
}
}
