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
extern signed char lbl_108_bss_214;
extern Storage lbl_108_bss_218;
extern Registration lbl_108_bss_1B4;
extern unsigned char lbl_108_data_290C[], lbl_108_data_28E0[];
extern unsigned char lbl_108_data_2878[], lbl_108_data_78E8[];
void* fn_108_10B34(void*, short);
void __register_global_object(void*, void*, void*);
void fn_108_10DD0(void) {
    if (lbl_108_bss_214 == 0) {
        lbl_108_bss_218.primary = lbl_108_data_290C;
        lbl_108_bss_218.secondary = lbl_108_data_28E0;
        lbl_108_bss_218.primary = lbl_108_data_2878;
        lbl_108_bss_218.secondary = lbl_108_data_2878 + 0x10;
        lbl_108_bss_218.primary = lbl_108_data_78E8;
        lbl_108_bss_218.secondary = lbl_108_data_78E8 + 0x10;
        __register_global_object(&lbl_108_bss_218, reinterpret_cast<void*>(fn_108_10B34), &lbl_108_bss_1B4);
        lbl_108_bss_214 = 1;
    }
    reinterpret_cast<View*>(&lbl_108_bss_218)->dispatch();
}
}