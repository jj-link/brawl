#pragma force_active on
struct Storage { void* primary; void* secondary; };
struct Registration { void* next; void* object; void* destructor; };
class View {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_110_bss_2BC;
extern Storage lbl_110_bss_2C0;
extern Registration lbl_110_bss_234;
extern unsigned char lbl_110_data_1AF0[], lbl_110_data_1AC4[];
extern unsigned char lbl_110_data_1A5C[], lbl_110_data_701C[];
void* fn_110_12B2C(void*, short);
void __register_global_object(void*, void*, void*);
void fn_110_12E00(void*) {
    if (lbl_110_bss_2BC == 0) {
        lbl_110_bss_2C0.primary = lbl_110_data_1AF0;
        lbl_110_bss_2C0.secondary = lbl_110_data_1AC4;
        lbl_110_bss_2C0.primary = lbl_110_data_1A5C;
        lbl_110_bss_2C0.secondary = lbl_110_data_1A5C + 0x10;
        lbl_110_bss_2C0.primary = lbl_110_data_701C;
        lbl_110_bss_2C0.secondary = lbl_110_data_701C + 0x10;
        __register_global_object(&lbl_110_bss_2C0, reinterpret_cast<void*>(fn_110_12B2C), &lbl_110_bss_234);
        lbl_110_bss_2BC = 1;
    }
    reinterpret_cast<View*>(&lbl_110_bss_2C0)->dispatch();
}
}