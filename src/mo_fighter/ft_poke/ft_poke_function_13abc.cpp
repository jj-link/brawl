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
extern signed char lbl_116_bss_1F4;
extern Storage lbl_116_bss_1F8;
extern Registration lbl_116_bss_240;
extern unsigned char lbl_116_data_26C4[], lbl_116_data_2698[];
extern unsigned char lbl_116_data_2630[], lbl_116_data_74F8[];
void* fn_116_10550(void*, short);
void __register_global_object(void*, void*, void*);
void fn_116_13ABC(void*) {
    if (lbl_116_bss_1F4 == 0) {
        lbl_116_bss_1F8.primary = lbl_116_data_26C4;
        lbl_116_bss_1F8.secondary = lbl_116_data_2698;
        lbl_116_bss_1F8.primary = lbl_116_data_2630;
        lbl_116_bss_1F8.secondary = lbl_116_data_2630 + 0x10;
        lbl_116_bss_1F8.primary = lbl_116_data_74F8;
        lbl_116_bss_1F8.secondary = lbl_116_data_74F8 + 0x10;
        __register_global_object(&lbl_116_bss_1F8, reinterpret_cast<void*>(fn_116_10550), &lbl_116_bss_240);
        lbl_116_bss_1F4 = 1;
    }
    reinterpret_cast<View*>(&lbl_116_bss_1F8)->dispatch();
}
}